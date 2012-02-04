#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewer.h"
#include "dataset.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionHelp_triggered();

    void on_frame_editingFinished();


private:

    void updateUi();

    Ui::MainWindow *ui;
    Viewer viewer;

    Dataset *dataset;

};

#endif // MAINWINDOW_H
