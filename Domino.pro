#-------------------------------------------------
#
# Project created by QtCreator 2014-01-01T18:27:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Domino
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylabel.cpp \
    cfileform.cpp

HEADERS  += mainwindow.h \
    mylabel.h \
    cfileform.h

FORMS    += mainwindow.ui \
    cfileform.ui

CONFIG    += c++11
