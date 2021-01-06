#-------------------------------------------------
#
# Project created by QtCreator 2020-11-25T16:36:03
#
#-------------------------------------------------

QT       += core gui
QT +=printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = analysis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    plot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    plot.h

FORMS    += mainwindow.ui
