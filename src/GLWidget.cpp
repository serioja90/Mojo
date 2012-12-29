#include <QGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GLWidget.h"

GLWidget::GLWidget(QWidget* parent) : QGLWidget(parent){
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
	glBegin(GL_QUADS);
		glVertex3f(-1.0f,1.0f,0.0f);
		glVertex3f(1.0f,1.0f,0.0f);
		glVertex3f(1.0f,-1.0f,0.0f);
		glVertex3f(-1.0f,-1.0f,0.0f);
	glEnd();
}