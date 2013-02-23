#include <QGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GLWidget.h"

#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;

GLWidget::GLWidget(QWidget* parent) : QGLWidget(parent){
	this->objects = new QList<Object>();
	rotX = 0.0f;
	rotY = 0.0f;
	rotZ = 0.0f;
	stepX = 0.0f;
	stepY = 0.0f;
	stepZ = 0.0f;
	timer = new QTimer();
	timer->setInterval(1);
	timer->setSingleShot(false);
	connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
}

void GLWidget::setObjects(QList<Object> objects){
	this->objects = new QList<Object>();
	for(int i=0;i<objects.count();i++){
		this->objects->append(objects.at(i));
	}
}

void GLWidget::initializeGL(){
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClearDepth(1.0f);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	// GLfloat ambientLight[] = {0.01f,0.01f,0.01f,1.0f};
	// GLfloat diffuseLight[] = {0.7f,0.7f,0.7f,1.0f};
	// GLfloat lightPos[] = {-50.0f,50.0f,100.0f,1.0f};
	// GLfloat specilar[] = {1.0f,1.0f,1.0f,1.0f};
	// GLfloat specref[] = {1.0f,1.0f,1.0f,1.0f};
	// //glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientLight);
	// glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	// glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	// glLightfv(GL_LIGHT0,GL_SPECULAR,specilar);
	// glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	// glMaterialfv(GL_FRONT,GL_SPECULAR,specref);

	glEnable(GL_LIGHT0);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	timer->start();
}

void GLWidget::resizeGL(int width, int height){
	height = height==0?1:height;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,1.0f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GLWidget::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-5.0f);
	// glRotatef(rotX,1.0f,0.0f,0.0f);
	// 	glRotatef(rotY,0.0f,1.0f,0.0f);
	// 	glRotatef(rotZ,0.0f,0.0f,1.0f);
	gluLookAt(sin(rotY)*7.0f,sin(rotX)*7.0f,cos(rotY)*cos(rotX)*7.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	try{
		glPushMatrix();
		glMateriali(GL_FRONT,GL_SHININESS,128);
		for(int i=0;i<this->objects->count();i++){
			Object obj = this->objects->at(i);
			this->paintObject(obj);
		}
		glPopMatrix();
	}catch(int e){
		cout << "Exception " << e << " catched!";
	}
	rotX += stepX;
	rotY += stepY;
	rotZ += stepZ;
}

void GLWidget::repaint(){
	this->paintGL();
}

void GLWidget::paintObject(Object obj){
	QList<Point> points = obj.getPoints();
	QList<Line> lines = obj.getLines();
	QList<Triangle> triangles = obj.getTriangles();
	QList<Quad> quads = obj.getQuads();
	QList<Polygon> polygons = obj.getPolygons();
	if(!points.empty()){
		glBegin(GL_POINTS);
			this->pointsToVertex(points);
		glEnd();
	}
	if(!lines.empty()){
		for(int i=0;i<lines.count();i++){
			glBegin(GL_LINES);
					Line line = lines.at(i);
					this->pointsToVertex(line.getPoints());
			glEnd();
		}
	}
	if(!triangles.empty()){
		for(int i=0;i<triangles.count();i++){
			glBegin(GL_TRIANGLES);
					Triangle triangle = triangles.at(i);
					this->pointsToVertex(triangle.getPoints());
			glEnd();
		}
	}

	if(!quads.empty()){
		for(int i=0;i<quads.count();i++){
			glBegin(GL_QUADS);
					Quad quad = quads.at(i);
					this->pointsToVertex(quad.getPoints());
			glEnd();
		}
	}

	if(!polygons.empty()){
		for(int i=0;i<polygons.count();i++){
			glBegin(GL_POLYGON);
					Polygon polygon = polygons.at(i);
					this->pointsToVertex(polygon.getPoints());
			glEnd();
		}
	}
}

void GLWidget::pointsToVertex(QList<Point> points){
	for(int i=0;i<points.count();i++){
		Point point = points.at(i);
		Color color = point.getColor();
		if(color.isEmpty()){
			color = Color(255,255,255,255);
		}
		//cout << "Point: " << point.getX() << " " << point.getY() << " " << point.getZ() << endl;
		//cout << "Color: " << color.getRed() << " " << color.getGreen() << " " << color.getBlue() << " " << color.getAlpha() << endl;
		glColor4f(color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
		glVertex3f(point.getX(),point.getY(),point.getZ());
	}
}

void GLWidget::rotateLeft(float degrees){
	rotY -= degrees;
}

void GLWidget::rotateRight(float degrees){
	rotY += degrees;
}

void GLWidget::rotateUp(float degrees){
	rotX -= degrees;
}

void GLWidget::rotateDown(float degrees){
	rotX += degrees;
}

void GLWidget::addLeftRotation(float byDegrees){
	stepY += byDegrees;
}

void GLWidget::addRightRotation(float byDegrees){
	stepY -= byDegrees;
}