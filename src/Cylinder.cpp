#include "Cylinder.h"

Cylinder::Cylinder(){
	this->empty = false;
	this->origin = Point(0.0f,0.0f,0.0f);
	this->height = 1.0f;
	this->baseRadius = 0.5f;
	this->topRadius = 0.5f;
	this->detalization = 25;
	this->setQuadricAttributes(Quadric());
}

Cylinder::Cylinder(Point origin, GLfloat baseRadius, GLfloat topRadius, GLfloat height, GLint detalization){
	this->empty = false;
	this->origin = origin;
	this->height = 1.0f;
	this->baseRadius = baseRadius;
	this->topRadius = topRadius;
	this->height = height;
	this->detalization = detalization;
	this->setQuadricAttributes(Quadric());
}

void Cylinder::setOrigin(Point origin){
	this->empty = false;
	this->origin = origin;
}

void Cylinder::setBaseRadius(GLfloat baseRadius){
	this->empty = false;
	this->baseRadius = baseRadius;
}

void Cylinder::setTopRadius(GLfloat topRadius){
	this->empty = false;
	this->topRadius = topRadius;
}

void Cylinder::setHeight(GLfloat height){
	this->empty = false;
	this->height = height;
}

void Cylinder::setDetalization(GLint detalization){
	this->empty = false;
	this->detalization = detalization;
}

Point Cylinder::getOrigin(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->origin;
}

GLfloat Cylinder::getBaseRadius(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->baseRadius;
}

GLfloat Cylinder::getTopRadius(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->topRadius;
}

GLfloat Cylinder::getHeight(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->height;
}

GLint Cylinder::getDetalization(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->detalization;
}