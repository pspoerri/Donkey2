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


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dataset = 0;
    ui->setupUi(this);
    ui->mainLayout->addWidget(&viewer);

}

MainWindow::~MainWindow()
{
    delete ui;
    if (dataset != NULL)
        delete dataset;
}

void MainWindow::on_actionExit_triggered()
{
    this->window()->close();
    exit(EXIT_SUCCESS);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), NULL, tr("XYZ File (*.xyz);;XYZW File (*.xyzw)"));
    if (filename == NULL)
        return;

    if (dataset != NULL)
        delete dataset;
    dataset = new Dataset(filename);
    viewer.dataset = dataset;
    updateUi();
}

void MainWindow::updateUi() {
    if (dataset != NULL) {
        ui->frameSlider->setMaximum(dataset->frames);
        ui->frameSlider->setValue(0);
        ui->frame->setValue(0);

        ui->speedSlider->setValue(1);
    }
}

void MainWindow::on_actionHelp_triggered()
{
    viewer.help();
}

void MainWindow::on_frame_editingFinished()
{
    int f = ui->frame->value();
    viewer.frame = f;
}


