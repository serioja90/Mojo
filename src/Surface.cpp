#include "Surface.h"
#include <QtGui>

Surface::Surface(){
	this->curves = 0;
	this->detalization = 0;
	this->style = GL_FILL;
}

Surface::Surface(QList<Point> points, GLint curves, GLint detalization, GLenum style){
	this->points = points;
	this->setCurves(curves);
	this->setDetalization(detalization);
	this->setStyle(style);
}

void Surface::addPoint(Point point){
	this->points.append(point);
}

void Surface::setPoints(QList<Point> points){
	this->points = points;
}

void Surface::setCurves(GLint curves){
	if(curves<0){
		throw Exception::InvalidSurfaceCurvesNumberException;
	}
	this->curves = curves;
}

void Surface::setDetalization(GLint detalization){
	if(detalization<0){
		throw Exception::InvalidSurfaceDetalizationException;
	}
	this->detalization = detalization;
}

void Surface::setStyle(GLenum style){
	switch(style){
		case GL_FILL:
		case GL_LINE:
			this->style = style;
			break;
		default:
			throw Exception::InvalidSurfaceStyleException;
	}
}

QList<Point> Surface::getPoints(){
	return this->points;
}

GLint Surface::getCurves(){
	return this->curves;
}

GLint Surface::getDetalization(){
	return this->detalization;
}

GLenum Surface::getStyle(){
	return this->style;
}

GLfloat*** Surface::toArray(){
	GLfloat*** result = (GLfloat***)calloc(this->points.count()/this->curves,sizeof(GLfloat**));
	//GLfloat result[this->points.count()/this->curves][this->curves][3];
	int counter = 0;
	for(int i=0;i<this->points.count()/this->curves;i++){
		result[i] = (GLfloat**)calloc(this->curves,sizeof(GLfloat*));
		for(int j=0;j<this->curves;j++){
			result[i][j] = Point::toArray(this->points.at(counter));
			counter++;
		}
	}
	return result;
}