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
    carte_select.cpp \
    cercle.cpp \
    dialog.cpp \
    mainwindow.cpp \
    myqgraphicsscene.cpp \
    projet.cpp \
    selection.cpp \
    zone.cpp \
    groupe_selection.cpp \
    myqabstractlistmodel.cpp \
    volontaire.cpp \
    mytreezonemodel.cpp \
    rectangle.cpp \
    mygraphicsview.cpp \
    analyse.cpp \
    myqpointf.cpp

HEADERS  += \
    cercle.h \
    dialog.h \
    mainwindow.h \
    myqgraphicsscene.h \
    projet.h \
    selection.h \
    zone.h \
    groupe_selection.h \
    myqabstractlistmodel.h \
    volontaire.h \
    mytreezonemodel.h \
    carte_select.h \
    rectangle.h \
    mygraphicsview.h \
    analyse.h \
    myqpointf.h

FORMS    += \
    dialog.ui \
    mainwindow.ui

TRANSLATIONS = lang_fr.ts
