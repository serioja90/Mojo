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
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	// GLfloat ambientLight[] = {0.01f,0.01f,0.01f,1.0f};
	// //glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientLight);
	// glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	// glLightfv(GL_LIGHT0,GL_SPECULAR,specilar);

	//glEnable(GL_LIGHT0);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_RESCALE_NORMAL);
	glEnable(GL_LIGHT0);
	GLfloat material_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialf(GL_FRONT,GL_SHININESS,128.0f);
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
	//glTranslatef(0.0f,0.0f,-5.0f);
	gluLookAt(sin(rotY)*7.0f,sin(rotX)*7.0f,cos(rotY)*cos(rotX)*7.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glPushMatrix();
		// use glTranslatef to indicate the light position
		glTranslatef(0.0f,3.0f,0.0f);
		// prepare the diffuse light color
		GLfloat light0_diffuse[] = {1.0f, 1.0f, 1.0f};
		// prepare the vector that will be used to indicate if the
		// light has an fixed position or an infinite
		// If using a spot light the last value have to be 1.0f while
		// the others indicates an alternative translation
		// If using a normal diffuse light the first 3 values indicates
		// the light direction.
		GLfloat light0_position[] = {0.0, -1.0, 0.0, 1.0};
		// when using a spot light we have to indicate the direction
		GLfloat light0_spot_direction[] = {0.0, -1.0f, 0.0}; // indicate the direction relative to the current light position
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
		glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.4);
		// glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_spot_direction);
		// glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 15.0);
	glPopMatrix();

	try{
		glPushMatrix();
		for(int i=0;i<this->objects->count();i++){
			Object obj = this->objects->at(i);
			this->paintObject(obj);
		}

		glColor4f(0.2f,1.0f,0.7f,0.0f);
		QList<Point> ground;
		ground.append(Point(3.0f,-1.0f,3.0f));
		ground.append(Point(3.0f,-1.0f,-3.0f));
		ground.append(Point(-3.0f,-1.0f,-3.0f));
		ground.append(Point(-3.0f,-1.0f,3.0f));
		glBegin(GL_QUADS);
			glNormal3fv(getNormal(ground));
			glVertex3fv(Point::toArray(ground.at(0)));
			glVertex3fv(Point::toArray(ground.at(1)));
			glVertex3fv(Point::toArray(ground.at(2)));
			glVertex3fv(Point::toArray(ground.at(3)));
		glEnd();
		glPopMatrix();
	}catch(int e){
		cout << "Exception " << e << " catched!";
	}

	rotX += stepX;
	rotY += stepY;
	rotZ += stepZ;
	GLenum err;
	while((err = glGetError())!=GL_NO_ERROR){
		cout << gluErrorString(err) << endl;
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
					glNormal3fv(getNormal(triangle.getPoints()));
					this->pointsToVertex(triangle.getPoints());
			glEnd();
		}
	}

	if(!quads.empty()){
		for(int i=0;i<quads.count();i++){
			glBegin(GL_QUADS);
					Quad quad = quads.at(i);
					glNormal3fv(getNormal(quad.getPoints()));
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

GLfloat* GLWidget::getNormal(QList<Point> points){
	int i;
	GLfloat normal[3] = {0.0f,0.0f,0.0f};
	GLfloat length;
	for(i=0;i<3 && i<points.count();i++){
		Point p1 = points.at(i);
		Point p2 = points.at((i+1) % points.count());
		if(p1.isEmpty() || p2.isEmpty()){
			throw Exception::EmptyPointException;
		}
		normal[0] += (p1.getY() - p2.getY()) * (p1.getZ() + p2.getZ());
		normal[1] += (p1.getZ() - p2.getZ()) * (p1.getX() + p2.getX());
		normal[2] += (p1.getX() - p2.getX()) * (p1.getY() + p2.getY());
	}
	length = sqrt(normal[0]*normal[0] + normal[1]*normal[1] + normal[2]*normal[2]);
	if(length!=0){
		for(i=0;i<3;i++){
			normal[i] = normal[i]/length;
		}
	}
	return normal;
}