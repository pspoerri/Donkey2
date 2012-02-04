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

#ifndef DATASET_H
#define DATASET_H

#include <QString>
#include <QFileDialog>
#include <vector>
#include "timestep.h"
class Dataset
{
public:
    Dataset(QString filename);
    ~Dataset() {
        // Do nothing (at the moment)
    };
    int frames;
    QString filename;


    std::vector<Timestep> timesteps;
private:
    void readFile();
};

#endif // DATASET_H
