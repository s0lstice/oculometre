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
    carte_points.cpp \
    carte_select.cpp \
    cercle.cpp \
    dialog.cpp \
    mainwindow.cpp \
    myqgraphicsscene.cpp \
    polygone.cpp \
    projet.cpp \
    selection.cpp \
    sujet.cpp \
    zone.cpp \
    groupe_selection.cpp

HEADERS  += \
    carte_points.h \
    carte_select.h \
    cercle.h \
    dialog.h \
    mainwindow.h \
    myqgraphicsscene.h \
    polygone.h \
    projet.h \
    selection.h \
    sujet.h \
    zone.h \
    groupe_selection.h

FORMS    += \
    dialog.ui \
    mainwindow.ui
