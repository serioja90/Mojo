#############################################################################
# Makefile for building: bin/Mojo
# Generated by qmake (2.01a) (Qt 4.8.3) on: gio mar 28 12:34:14 2013
# Project:  Mojo.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile Mojo.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I. -Isrc/include -I/usr/X11R6/include -Ibuild/moc
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L/usr/X11R6/lib64 -lGLU -lQtOpenGL -lQtGui -lQtCore -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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

OBJECTS_DIR   = build/obj/

####### Files

SOURCES       = src/main.cpp \
		src/Exception.cpp \
		src/MainWindow.cpp \
		src/GLWidget.cpp \
		src/XmlParser.cpp \
		src/Color.cpp \
		src/Point.cpp \
		src/Line.cpp \
		src/Triangle.cpp \
		src/Quad.cpp \
		src/Polygon.cpp \
		src/MaterialParameter.cpp \
		src/AmbientParameter.cpp \
		src/DiffuseParameter.cpp \
		src/SpecularParameter.cpp \
		src/ShininessParameter.cpp \
		src/EmissionParameter.cpp \
		src/Material.cpp \
		src/Quadric.cpp \
		src/Sphere.cpp \
		src/Cylinder.cpp \
		src/Disk.cpp \
		src/Object.cpp build/moc/moc_MainWindow.cpp \
		build/moc/moc_GLWidget.cpp \
		build/rcc/qrc_icons.cpp
OBJECTS       = build/obj/main.o \
		build/obj/Exception.o \
		build/obj/MainWindow.o \
		build/obj/GLWidget.o \
		build/obj/XmlParser.o \
		build/obj/Color.o \
		build/obj/Point.o \
		build/obj/Line.o \
		build/obj/Triangle.o \
		build/obj/Quad.o \
		build/obj/Polygon.o \
		build/obj/MaterialParameter.o \
		build/obj/AmbientParameter.o \
		build/obj/DiffuseParameter.o \
		build/obj/SpecularParameter.o \
		build/obj/ShininessParameter.o \
		build/obj/EmissionParameter.o \
		build/obj/Material.o \
		build/obj/Quadric.o \
		build/obj/Sphere.o \
		build/obj/Cylinder.o \
		build/obj/Disk.o \
		build/obj/Object.o \
		build/obj/moc_MainWindow.o \
		build/obj/moc_GLWidget.o \
		build/obj/qrc_icons.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		Mojo.pro
QMAKE_TARGET  = Mojo
DESTDIR       = bin/
TARGET        = bin/Mojo

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

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Mojo.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile Mojo.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/x86_64-linux-gnu/libQtOpenGL.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Mojo.pro

dist: 
	@$(CHK_DIR_EXISTS) build/obj/Mojo1.0.0 || $(MKDIR) build/obj/Mojo1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/obj/Mojo1.0.0/ && $(COPY_FILE) --parents src/include/MainWindow.h src/include/Exception.h src/include/GLWidget.h src/include/XmlParser.h src/include/Color.h src/include/Point.h src/include/Line.h src/include/Triangle.h src/include/Quad.h src/include/Polygon.h src/include/MaterialParameter.h src/include/AmbientParameter.h src/include/DiffuseParameter.h src/include/SpecularParameter.h src/include/ShininessParameter.h src/include/EmissionParameter.h src/include/Material.h src/include/Quadric.h src/include/Sphere.h src/inclide/Cylinder.h src/include/Disk.h src/include/Object.h build/obj/Mojo1.0.0/ && $(COPY_FILE) --parents resources/icons.qrc build/obj/Mojo1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/Exception.cpp src/MainWindow.cpp src/GLWidget.cpp src/XmlParser.cpp src/Color.cpp src/Point.cpp src/Line.cpp src/Triangle.cpp src/Quad.cpp src/Polygon.cpp src/MaterialParameter.cpp src/AmbientParameter.cpp src/DiffuseParameter.cpp src/SpecularParameter.cpp src/ShininessParameter.cpp src/EmissionParameter.cpp src/Material.cpp src/Quadric.cpp src/Sphere.cpp src/Cylinder.cpp src/Disk.cpp src/Object.cpp build/obj/Mojo1.0.0/ && (cd `dirname build/obj/Mojo1.0.0` && $(TAR) Mojo1.0.0.tar Mojo1.0.0 && $(COMPRESS) Mojo1.0.0.tar) && $(MOVE) `dirname build/obj/Mojo1.0.0`/Mojo1.0.0.tar.gz . && $(DEL_FILE) -r build/obj/Mojo1.0.0


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

compiler_moc_header_make_all: build/moc/moc_MainWindow.cpp build/moc/moc_GLWidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc/moc_MainWindow.cpp build/moc/moc_GLWidget.cpp
build/moc/moc_MainWindow.cpp: src/include/XmlParser.h \
		src/include/Object.h \
		src/include/Point.h \
		src/include/Color.h \
		src/include/Line.h \
		src/include/Exception.h \
		src/include/Triangle.h \
		src/include/Material.h \
		src/include/MaterialParameter.h \
		src/include/AmbientParameter.h \
		src/include/DiffuseParameter.h \
		src/include/SpecularParameter.h \
		src/include/ShininessParameter.h \
		src/include/EmissionParameter.h \
		src/include/Quad.h \
		src/include/Polygon.h \
		src/include/Sphere.h \
		src/include/Quadric.h \
		src/include/Cylinder.h \
		src/include/GLWidget.h \
		src/include/MainWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/include/MainWindow.h -o build/moc/moc_MainWindow.cpp

build/moc/moc_GLWidget.cpp: src/include/Object.h \
		src/include/Point.h \
		src/include/Color.h \
		src/include/Line.h \
		src/include/Exception.h \
		src/include/Triangle.h \
		src/include/Material.h \
		src/include/MaterialParameter.h \
		src/include/AmbientParameter.h \
		src/include/DiffuseParameter.h \
		src/include/SpecularParameter.h \
		src/include/ShininessParameter.h \
		src/include/EmissionParameter.h \
		src/include/Quad.h \
		src/include/Polygon.h \
		src/include/Sphere.h \
		src/include/Quadric.h \
		src/include/Cylinder.h \
		src/include/GLWidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/include/GLWidget.h -o build/moc/moc_GLWidget.cpp

compiler_rcc_make_all: build/rcc/qrc_icons.cpp
compiler_rcc_clean:
	-$(DEL_FILE) build/rcc/qrc_icons.cpp
build/rcc/qrc_icons.cpp: resources/icons.qrc \
		resources/images/new-file.png \
		resources/images/open-file.png \
		resources/images/save-file.png
	/usr/bin/rcc -name icons resources/icons.qrc -o build/rcc/qrc_icons.cpp

compiler_image_collection_make_all: build/ui/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) build/ui/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

build/obj/main.o: src/main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/main.o src/main.cpp

build/obj/Exception.o: src/Exception.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Exception.o src/Exception.cpp

build/obj/MainWindow.o: src/MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/MainWindow.o src/MainWindow.cpp

build/obj/GLWidget.o: src/GLWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/GLWidget.o src/GLWidget.cpp

build/obj/XmlParser.o: src/XmlParser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/XmlParser.o src/XmlParser.cpp

build/obj/Color.o: src/Color.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Color.o src/Color.cpp

build/obj/Point.o: src/Point.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Point.o src/Point.cpp

build/obj/Line.o: src/Line.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Line.o src/Line.cpp

build/obj/Triangle.o: src/Triangle.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Triangle.o src/Triangle.cpp

build/obj/Quad.o: src/Quad.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Quad.o src/Quad.cpp

build/obj/Polygon.o: src/Polygon.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Polygon.o src/Polygon.cpp

build/obj/MaterialParameter.o: src/MaterialParameter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/MaterialParameter.o src/MaterialParameter.cpp

build/obj/AmbientParameter.o: src/AmbientParameter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/AmbientParameter.o src/AmbientParameter.cpp

build/obj/DiffuseParameter.o: src/DiffuseParameter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/DiffuseParameter.o src/DiffuseParameter.cpp

build/obj/SpecularParameter.o: src/SpecularParameter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/SpecularParameter.o src/SpecularParameter.cpp

build/obj/ShininessParameter.o: src/ShininessParameter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/ShininessParameter.o src/ShininessParameter.cpp

build/obj/EmissionParameter.o: src/EmissionParameter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/EmissionParameter.o src/EmissionParameter.cpp

build/obj/Material.o: src/Material.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Material.o src/Material.cpp

build/obj/Quadric.o: src/Quadric.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Quadric.o src/Quadric.cpp

build/obj/Sphere.o: src/Sphere.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Sphere.o src/Sphere.cpp

build/obj/Cylinder.o: src/Cylinder.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Cylinder.o src/Cylinder.cpp

build/obj/Disk.o: src/Disk.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Disk.o src/Disk.cpp

build/obj/Object.o: src/Object.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/Object.o src/Object.cpp

build/obj/moc_MainWindow.o: build/moc/moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_MainWindow.o build/moc/moc_MainWindow.cpp

build/obj/moc_GLWidget.o: build/moc/moc_GLWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_GLWidget.o build/moc/moc_GLWidget.cpp

build/obj/qrc_icons.o: build/rcc/qrc_icons.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/qrc_icons.o build/rcc/qrc_icons.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

