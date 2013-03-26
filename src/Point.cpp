#include "Point.h"
#include "Exception.h"

#include <iostream>

using namespace std;

Point::Point(){
	empty = true;
}

Point::Point(GLdouble x, GLdouble y, GLdouble z){
	empty = false;
	this->x = (GLfloat)x;
	this->y = (GLfloat)y;
	this->z = (GLfloat)z;
	color = Color();
}

Point::Point(GLfloat x, GLfloat y, GLfloat z){
	empty = false;
	this->x = x;
	this->y = y;
	this->z = z;
	color = Color();
}

Point::Point(GLint x, GLint y, GLint z){
	empty = false;
	this->x = (GLfloat)x;
	this->y = (GLfloat)y;
	this->z = (GLfloat)z;
	color = Color();
}

bool Point::isEmpty(){
	return this->empty;
}


GLfloat Point::getX(){
	if(this->isEmpty()){
		throw Exception::EmptyPointException;
	}
	return this->x;
}

GLfloat Point::getY(){
	if(this->isEmpty()){
		throw Exception::EmptyPointException;
	}
	return this->y;
}

GLfloat Point::getZ(){
	if(this->isEmpty()){
		throw Exception::EmptyPointException;
	}
	return this->z;
}

void Point::setColor(Color color){
	this->color = color;
}

Color Point::getColor(){
	if(this->isEmpty()){
		throw Exception::EmptyPointException;
	}
	return this->color;
}

GLfloat* Point::toArray(Point p){
	GLfloat* result;
	if(p.isEmpty()){
		throw Exception::EmptyPointException;
	}
	result = (GLfloat*)calloc(3,sizeof(GLfloat));
	result[0] = p.getX();
	result[1] = p.getY();
	result[2] = p.getZ();
	return result;
}