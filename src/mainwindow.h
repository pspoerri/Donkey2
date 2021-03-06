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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewer.h"
#include "dataset.h"
#include <QTimer>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateUiSlot();
private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionHelp_triggered();

    void on_frame_editingFinished();


    void on_playBtn_clicked();

    void on_speedSlider_valueChanged(int value);

    void on_frameSlider_sliderMoved(int position);

    void on_frame_valueChanged(int arg1);

    void on_openFileBtn_clicked();

private:
    void openFile(QString filename);
    void updateUi();
    void resetUi();
    void toggleFullscreen();
    Ui::MainWindow *ui;
    Viewer viewer;

    Dataset *dataset;

    bool fullscreen;
    bool frameChanged;
    bool frameSliderChanged;
    QTimer *timer;
};

#endif // MAINWINDOW_H
