#include "Sphere.h"

Sphere::Sphere(){
	this->empty = true;
	this->origin = Point(1.0f,1.0f,1.0f);
	this->radius = 0.5f;
	this->detalization = 25;
	this->drawStyle = GL_FILL;
}

Sphere::Sphere(Point origin, GLfloat radius, GLint detalization){
	this->empty = false;
	this->origin = origin;
	this->radius = radius;
	this->detalization = detalization;
}

void Sphere::setOrigin(Point origin){
	this->empty = false;
	this->origin = origin;
}

void Sphere::setRadius(GLfloat radius){
	this->empty = false;
	this->radius = radius;
}


void Sphere::setDetalization(GLint detalization){
	this->empty = false;
	this->detalization = detalization;
}

Point Sphere::getOrigin(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->origin;
}

GLfloat Sphere::getRadius(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->radius;
}

GLint Sphere::getDetalization(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->detalization;
}