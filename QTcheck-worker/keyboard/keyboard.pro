#-------------------------------------------------
#
# Project created by QtCreator 2020-12-09T12:35:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = keyboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    keyboard.cpp

HEADERS  += mainwindow.h \
    keyboard.h \
    line.h

FORMS    += mainwindow.ui
