#############################################################################
# Makefile for building: carte-qt
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sun May 20 21:45:29 2012
# Project:  carte-qt.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile carte-qt.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/usr/include/opencv -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
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
		myqpointf.cpp moc_dialog.cpp \
		moc_mainwindow.cpp \
		moc_myqgraphicsscene.cpp \
		moc_myqabstractlistmodel.cpp \
		moc_mytreezonemodel.cpp \
		moc_mygraphicsview.cpp
OBJECTS       = main.o \
		carte_select.o \
		cercle.o \
		dialog.o \
		mainwindow.o \
		myqgraphicsscene.o \
		projet.o \
		selection.o \
		zone.o \
		groupe_selection.o \
		myqabstractlistmodel.o \
		volontaire.o \
		mytreezonemodel.o \
		rectangle.o \
		mygraphicsview.o \
		analyse.o \
		myqpointf.o \
		moc_dialog.o \
		moc_mainwindow.o \
		moc_myqgraphicsscene.o \
		moc_myqabstractlistmodel.o \
		moc_mytreezonemodel.o \
		moc_mygraphicsview.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		carte-qt.pro
QMAKE_TARGET  = carte-qt
DESTDIR       = 
TARGET        = carte-qt

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_dialog.h ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: carte-qt.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile carte-qt.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/link_pkgconfig.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile carte-qt.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/carte-qt1.0.0 || $(MKDIR) .tmp/carte-qt1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/carte-qt1.0.0/ && $(COPY_FILE) --parents cercle.h dialog.h mainwindow.h myqgraphicsscene.h projet.h selection.h zone.h groupe_selection.h myqabstractlistmodel.h volontaire.h mytreezonemodel.h carte_select.h rectangle.h mygraphicsview.h analyse.h myqpointf.h .tmp/carte-qt1.0.0/ && $(COPY_FILE) --parents main.cpp carte_select.cpp cercle.cpp dialog.cpp mainwindow.cpp myqgraphicsscene.cpp projet.cpp selection.cpp zone.cpp groupe_selection.cpp myqabstractlistmodel.cpp volontaire.cpp mytreezonemodel.cpp rectangle.cpp mygraphicsview.cpp analyse.cpp myqpointf.cpp .tmp/carte-qt1.0.0/ && $(COPY_FILE) --parents dialog.ui mainwindow.ui .tmp/carte-qt1.0.0/ && $(COPY_FILE) --parents lang_fr.ts .tmp/carte-qt1.0.0/ && (cd `dirname .tmp/carte-qt1.0.0` && $(TAR) carte-qt1.0.0.tar carte-qt1.0.0 && $(COMPRESS) carte-qt1.0.0.tar) && $(MOVE) `dirname .tmp/carte-qt1.0.0`/carte-qt1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/carte-qt1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_dialog.cpp moc_mainwindow.cpp moc_myqgraphicsscene.cpp moc_myqabstractlistmodel.cpp moc_mytreezonemodel.cpp moc_mygraphicsview.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_dialog.cpp moc_mainwindow.cpp moc_myqgraphicsscene.cpp moc_myqabstractlistmodel.cpp moc_mytreezonemodel.cpp moc_mygraphicsview.cpp
moc_dialog.cpp: dialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) dialog.h -o moc_dialog.cpp

moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_myqgraphicsscene.cpp: zone.h \
		myqgraphicsscene.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) myqgraphicsscene.h -o moc_myqgraphicsscene.cpp

moc_myqabstractlistmodel.cpp: myqabstractlistmodel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) myqabstractlistmodel.h -o moc_myqabstractlistmodel.cpp

moc_mytreezonemodel.cpp: mytreezonemodel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mytreezonemodel.h -o moc_mytreezonemodel.cpp

moc_mygraphicsview.cpp: mygraphicsview.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mygraphicsview.h -o moc_mygraphicsview.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_dialog.h ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_dialog.h ui_mainwindow.h
ui_dialog.h: dialog.ui
	/usr/bin/uic-qt4 dialog.ui -o ui_dialog.h

ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

carte_select.o: carte_select.cpp carte_select.h \
		mainwindow.h \
		projet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o carte_select.o carte_select.cpp

cercle.o: cercle.cpp cercle.h \
		zone.h \
		myqpointf.h \
		groupe_selection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cercle.o cercle.cpp

dialog.o: dialog.cpp dialog.h \
		ui_dialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dialog.o dialog.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		projet.h \
		carte_select.h \
		zone.h \
		cercle.h \
		myqpointf.h \
		selection.h \
		rectangle.h \
		groupe_selection.h \
		volontaire.h \
		myqgraphicsscene.h \
		myqabstractlistmodel.h \
		mytreezonemodel.h \
		mygraphicsview.h \
		analyse.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

myqgraphicsscene.o: myqgraphicsscene.cpp myqgraphicsscene.h \
		zone.h \
		mainwindow.h \
		carte_select.h \
		projet.h \
		volontaire.h \
		cercle.h \
		myqpointf.h \
		rectangle.h \
		selection.h \
		groupe_selection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o myqgraphicsscene.o myqgraphicsscene.cpp

projet.o: projet.cpp projet.h \
		groupe_selection.h \
		zone.h \
		volontaire.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o projet.o projet.cpp

selection.o: selection.cpp selection.h \
		zone.h \
		myqpointf.h \
		carte_select.h \
		projet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o selection.o selection.cpp

zone.o: zone.cpp zone.h \
		groupe_selection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o zone.o zone.cpp

groupe_selection.o: groupe_selection.cpp groupe_selection.h \
		zone.h \
		cercle.h \
		myqpointf.h \
		selection.h \
		rectangle.h \
		projet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o groupe_selection.o groupe_selection.cpp

myqabstractlistmodel.o: myqabstractlistmodel.cpp myqabstractlistmodel.h \
		projet.h \
		mainwindow.h \
		volontaire.h \
		myqgraphicsscene.h \
		zone.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o myqabstractlistmodel.o myqabstractlistmodel.cpp

volontaire.o: volontaire.cpp volontaire.h \
		dialog.h \
		projet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o volontaire.o volontaire.cpp

mytreezonemodel.o: mytreezonemodel.cpp mytreezonemodel.h \
		groupe_selection.h \
		zone.h \
		mainwindow.h \
		projet.h \
		selection.h \
		myqpointf.h \
		rectangle.h \
		cercle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mytreezonemodel.o mytreezonemodel.cpp

rectangle.o: rectangle.cpp rectangle.h \
		zone.h \
		myqpointf.h \
		groupe_selection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rectangle.o rectangle.cpp

mygraphicsview.o: mygraphicsview.cpp mygraphicsview.h \
		myqgraphicsscene.h \
		zone.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mygraphicsview.o mygraphicsview.cpp

analyse.o: analyse.cpp analyse.h \
		projet.h \
		groupe_selection.h \
		zone.h \
		volontaire.h \
		rectangle.h \
		myqpointf.h \
		cercle.h \
		selection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o analyse.o analyse.cpp

myqpointf.o: myqpointf.cpp myqpointf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o myqpointf.o myqpointf.cpp

moc_dialog.o: moc_dialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dialog.o moc_dialog.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_myqgraphicsscene.o: moc_myqgraphicsscene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_myqgraphicsscene.o moc_myqgraphicsscene.cpp

moc_myqabstractlistmodel.o: moc_myqabstractlistmodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_myqabstractlistmodel.o moc_myqabstractlistmodel.cpp

moc_mytreezonemodel.o: moc_mytreezonemodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mytreezonemodel.o moc_mytreezonemodel.cpp

moc_mygraphicsview.o: moc_mygraphicsview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mygraphicsview.o moc_mygraphicsview.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

