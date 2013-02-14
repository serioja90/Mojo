#include "Point.h"
#include "Exception.h"

#include <iostream>

using namespace std;

Point::Point(){
	empty = true;
}

Point::Point(double x, double y, double z){
	empty = false;
	this->x = x;
	this->y = y;
	this->z = z;
	color = Color();
}

Point::Point(float x, float y, float z){
	empty = false;
	this->x = (double)x;
	this->y = (double)y;
	this->z = (double)z;
	color = Color();
}

Point::Point(int x, int y, int z){
	empty = false;
	this->x = (double)x;
	this->y = (double)y;
	this->z = (double)z;
	color = Color();
}

bool Point::isEmpty(){
	return this->empty;
}

double Point::getX(){
	if(this->isEmpty()){
		throw Exception::EmptyPointException;
	}
	return this->x;
}

double Point::getY(){
	if(this->isEmpty()){
		throw Exception::EmptyPointException;
	}
	return this->y;
}

double Point::getZ(){
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