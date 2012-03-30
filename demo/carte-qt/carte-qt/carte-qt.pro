#-------------------------------------------------
#
# Project created by QtCreator 2012-03-30T20:23:34
#
#-------------------------------------------------

QT       += core gui

TARGET = carte-qt
TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += opencv

SOURCES += main.cpp\
        mainwindow.cpp \
    carte_select.cpp \
    points.cpp

HEADERS  += mainwindow.h \
    carte_select.h \
    points.h

FORMS    += mainwindow.ui
