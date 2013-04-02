#include "Surface.h"

Surface::Surface(){
	this->curves = 0;
	this->detalization = 0;
	this->style = GLU_FILL;
}

Surface::Surface(QList<Point> points, GLint curves, GLint detalization, GLenum style){
	this->points = points;
	this->setCurves(curves);
	this->setDetalization(detalization);
	this->setStyle(style);
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
		case GLU_FILL:
		case GLU_LINE:
		case GLU_POINT:
		case GLU_SILHOUETTE:
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