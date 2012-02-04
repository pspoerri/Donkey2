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
