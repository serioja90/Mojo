#include <QGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GLWidget.h"

#include <iostream>

using namespace std;

GLWidget::GLWidget(QWidget* parent) : QGLWidget(parent){
	this->objects = new QList<Object>();
	timer = new QTimer();
	timer->setInterval(1);
	timer->setSingleShot(false);
	connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
}

void GLWidget::setObjects(QList<Object> objects){
	for(int i=0;i<objects.count();i++){
		this->objects->append(objects.at(i));
	}
}

void GLWidget::initGL(){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_MULTISAMPLE);
	static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glClearColor(0.0f,0.0f,0.0f,0.5f);
	glClearDepth(1.0f);
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
	glTranslatef(0.0f,0.0f,-5.0f);
	for(int i=0;i<this->objects->count();i++){
		Object obj = this->objects->at(i);
		this->paintObject(obj);
	}
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
			for(int i=0;i<points.count();i++){
				Point point = points.at(i);
				glVertex3f(point.getX(),point.getY(),point.getZ());
			}
		glEnd();
	}
	if(!lines.empty()){
		for(int i=0;i<lines.count();i++){
			glBegin(GL_LINES);
					Line line = lines.at(i);
					QList<Point> linePoints = line.getPoints();
					for(int j=0;j<linePoints.count();j++){
						Point point = linePoints.at(j);
						glVertex3f(point.getX(),point.getY(),point.getZ());
					}
			glEnd();
		}
	}
	if(!triangles.empty()){
		for(int i=0;i<triangles.count();i++){
			glBegin(GL_TRIANGLES);
					Triangle triangle = triangles.at(i);
					QList<Point> trianglePoints = triangle.getPoints();
					for(int j=0;j<trianglePoints.count();j++){
						Point point = trianglePoints.at(j);
						glVertex3f(point.getX(),point.getY(),point.getZ());
					}
			glEnd();
		}
	}

	if(!quads.empty()){
		for(int i=0;i<quads.count();i++){
			glBegin(GL_QUADS);
					Quad quad = quads.at(i);
					QList<Point> quadPoints = quad.getPoints();
					for(int j=0;j<quadPoints.count();j++){
						Point point = quadPoints.at(j);
						glVertex3f(point.getX(),point.getY(),point.getZ());
					}
			glEnd();
		}
	}

	if(!polygons.empty()){
		for(int i=0;i<polygons.count();i++){
			glBegin(GL_POLYGON);
					Polygon polygon = polygons.at(i);
					QList<Point> polygonPoints = polygon.getPoints();
					for(int j=0;j<polygonPoints.count();j++){
						Point point = polygonPoints.at(j);
						glVertex3f(point.getX(),point.getY(),point.getZ());
					}
			glEnd();
		}
	}
}