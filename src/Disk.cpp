#include "Disk.h"

Disk::Disk(){
	this->empty = false;
	this->origin = Point(0.0f,0.0f,0.0f);
	this->innerRadius = 0.5f;
	this->outerRadius = 1.0f;
	this->detalization = 25;
	this->setQuadricAttributes(Quadric());
}

Disk::Disk(Point origin, GLfloat innerRadius, GLfloat outerRadius, GLint detalization){
	this->empty = false;
	this->origin = origin;
	this->innerRadius = innerRadius;
	this->outerRadius = outerRadius;
	this->detalization = detalization;
	this->setQuadricAttributes(Quadric());
}

void Disk::setOrigin(Point origin){
	this->empty = false;
	this->origin = origin;
}

void Disk::setInnerRadius(GLfloat innerRadius){
	this->empty = false;
	this->innerRadius = innerRadius;
}

void Disk::setOuterRadius(GLfloat outerRadius){
	this->empty = false;
	this->outerRadius = outerRadius;
}

void Disk::setDetalization(GLint detalization){
	this->empty = false;
	this->detalization = detalization;
}

Point Disk::getOrigin(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->origin;
}

GLfloat Disk::getInnerRadius(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->innerRadius;
}

GLfloat Disk::getOuterRadius(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->outerRadius;
}

GLint Disk::getDetalization(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->detalization;
}