######################################################################
# Automatically generated by qmake (2.01a) ven dic 28 23:30:30 2012
######################################################################

TEMPLATE = app
DESTDIR = bin
DEPENDPATH += . src
INCLUDEPATH += . src/include

#build
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
RCC_DIR = build/rcc
UI_DIR = build/ui

QT += opengl

LIBS += -lGL -lGLU

# Input
HEADERS +=  src/include/MainWindow.h\
			src/include/Exception.h\
			src/include/GLWidget.h\
			src/include/XmlParser.h\
			src/include/Color.h\
			src/include/Point.h\
			src/include/Line.h\
			src/include/Triangle.h\
			src/include/Quad.h\
			src/include/Polygon.h\
			src/include/MaterialParameter.h\
			src/include/AmbientParameter.h\
			src/include/DiffuseParameter.h\
			src/include/SpecularParameter.h\
			src/include/ShininessParameter.h\
			src/include/EmissionParameter.h\
			src/include/Material.h\
			src/include/Quadric.h\
			src/include/Sphere.h\
			src/inclide/Cylinder.h\
			src/include/Disk.h\
			src/include/Object.h
SOURCES +=  src/main.cpp\
			src/Exception.cpp\
			src/MainWindow.cpp\
			src/GLWidget.cpp\
			src/XmlParser.cpp\
			src/Color.cpp\
			src/Point.cpp\
			src/Line.cpp\
			src/Triangle.cpp\
			src/Quad.cpp\
			src/Polygon.cpp\
			src/MaterialParameter.cpp\
			src/AmbientParameter.cpp\
			src/DiffuseParameter.cpp\
			src/SpecularParameter.cpp\
			src/ShininessParameter.cpp\
			src/EmissionParameter.cpp\
			src/Material.cpp\
			src/Quadric.cpp\
			src/Sphere.cpp\
			src/Cylinder.cpp\
			src/Disk.cpp\
			src/Object.cpp

RESOURCES += resources/icons.qrc
