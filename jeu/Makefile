#############################################################################
# Makefile for building: partie_08
# Generated by qmake (2.01a) (Qt 4.8.6) on: Wed Mar 21 11:05:33 2018
# Project:  partie_08.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -o Makefile partie_08.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -Wall -Wextra -std=c++11 -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Isrc -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
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

SOURCES       = src/circle.cpp \
		src/Comportement.cpp \
		src/Fondjeu.cpp \
		src/joueur.cpp \
		src/main.cpp \
		src/render_area.cpp \
		src/vec2.cpp \
		src/window.cpp moc_render_area.cpp \
		moc_window.cpp
OBJECTS       = circle.o \
		Comportement.o \
		Fondjeu.o \
		joueur.o \
		main.o \
		render_area.o \
		vec2.o \
		window.o \
		moc_render_area.o \
		moc_window.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
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
		partie_08.pro
QMAKE_TARGET  = partie_08
DESTDIR       = 
TARGET        = partie_08

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

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: partie_08.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
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
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile partie_08.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
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
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile partie_08.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/partie_081.0.0 || $(MKDIR) .tmp/partie_081.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/partie_081.0.0/ && $(COPY_FILE) --parents src/circle.hpp src/Comportement.hpp src/Fondjeu.hpp src/joueur.hpp src/render_area.hpp src/vec2.hpp src/window.hpp .tmp/partie_081.0.0/ && $(COPY_FILE) --parents src/circle.cpp src/Comportement.cpp src/Fondjeu.cpp src/joueur.cpp src/main.cpp src/render_area.cpp src/vec2.cpp src/window.cpp .tmp/partie_081.0.0/ && $(COPY_FILE) --parents src/mainwindow.ui .tmp/partie_081.0.0/ && (cd `dirname .tmp/partie_081.0.0` && $(TAR) partie_081.0.0.tar partie_081.0.0 && $(COMPRESS) partie_081.0.0.tar) && $(MOVE) `dirname .tmp/partie_081.0.0`/partie_081.0.0.tar.gz . && $(DEL_FILE) -r .tmp/partie_081.0.0


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

compiler_moc_header_make_all: moc_render_area.cpp moc_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_render_area.cpp moc_window.cpp
moc_render_area.cpp: src/circle.hpp \
		src/vec2.hpp \
		src/joueur.hpp \
		src/Comportement.hpp \
		src/Fondjeu.hpp \
		src/render_area.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/render_area.hpp -o moc_render_area.cpp

moc_window.cpp: src/window.hpp
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) src/window.hpp -o moc_window.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: src/mainwindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic src/mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

circle.o: src/circle.cpp src/circle.hpp \
		src/vec2.hpp \
		src/joueur.hpp \
		src/Comportement.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o circle.o src/circle.cpp

Comportement.o: src/Comportement.cpp src/Comportement.hpp \
		src/vec2.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Comportement.o src/Comportement.cpp

Fondjeu.o: src/Fondjeu.cpp src/Fondjeu.hpp \
		src/vec2.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Fondjeu.o src/Fondjeu.cpp

joueur.o: src/joueur.cpp src/joueur.hpp \
		src/vec2.hpp \
		src/Comportement.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o joueur.o src/joueur.cpp

main.o: src/main.cpp src/window.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

render_area.o: src/render_area.cpp src/render_area.hpp \
		src/circle.hpp \
		src/vec2.hpp \
		src/joueur.hpp \
		src/Comportement.hpp \
		src/Fondjeu.hpp \
		src/vaisseau.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o render_area.o src/render_area.cpp

vec2.o: src/vec2.cpp src/vec2.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vec2.o src/vec2.cpp

window.o: src/window.cpp src/window.hpp \
		src/render_area.hpp \
		src/circle.hpp \
		src/vec2.hpp \
		src/joueur.hpp \
		src/Comportement.hpp \
		src/Fondjeu.hpp \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o window.o src/window.cpp

moc_render_area.o: moc_render_area.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_render_area.o moc_render_area.cpp

moc_window.o: moc_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_window.o moc_window.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

