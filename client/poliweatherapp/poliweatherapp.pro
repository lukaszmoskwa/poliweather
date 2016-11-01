#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T17:01:39
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = poliweatherapp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jsonreader.cpp

HEADERS  += mainwindow.h \
    jsonreader.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
