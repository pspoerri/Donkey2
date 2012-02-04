#-------------------------------------------------
#
# Project created by QtCreator 2012-02-04T10:59:27
#
#-------------------------------------------------

QT       += core gui xml opengl

TARGET = xyzw
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    viewer.cpp \
    particle.cpp \
    timestep.cpp \
    dataset.cpp

HEADERS  += mainwindow.h \
    viewer.h \
    particle.h \
    datatypes.h \
    timestep.h \
    dataset.h \
    vcamera.h

FORMS    += mainwindow.ui

LIBS += -lqglviewer-qt4
