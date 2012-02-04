// This file belongs to Donkey²: Yet another XYZ OpenGL Dataviewer
//     https://github.com/moeeeep/donkey2
// Copyright (C) 2011  Pascal Spörri <pascal@moeeeep.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "dataset.h"

#include <QString>
#include <QByteArray>
#include <QFile>
Dataset::Dataset(QString filename)
{
    this->filename = filename;
    readFile();
//    frames = 0;

}

void Dataset::readFile() {
    QFile file(filename);
    QByteArray line;

    int elements_timestep;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      qDebug() << "Couldn't open file";
      exit(EXIT_FAILURE);
    }

    bool xyzw = filename.endsWith(".xyzw",Qt::CaseInsensitive);

    float x,y,z,w;
    // Count the number of lines
    frames = -1;
    while (!file.atEnd()) {
      line = file.readLine();
      if (sscanf(line.data(),"%d",&elements_timestep)== -1) {
        qDebug() << "File has wrong format";
        exit(EXIT_FAILURE);
      }
      if (!file.atEnd())
        line = file.readLine(); // Ignore this line
      if (!file.atEnd())
        line = file.readLine(); // Ignore this line
      timesteps.push_back(Timestep());
      frames++;
      for (int i=0;i<elements_timestep;i++) {
        if (!file.atEnd()) {
          line = file.readLine();
          if(sscanf(line.data(),"%f %f %f %f", &x, &y, &z, &w)==-1) {
            qDebug() << "Error: " << line;
            exit(EXIT_FAILURE);
          }
          if (xyzw)
              timesteps.back().put(x,y,z,w);
          else
              timesteps.back().put(y,z,w,1); // the line has the format: 1, x, y, z
        } else {
          qDebug() << "File has wrong format...";
        }

      }
      timesteps.back().updateBounds();
    }

}
