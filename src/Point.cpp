#include "Point.h"
#include "Exception.h"

#include <iostream>

using namespace std;

Point::Point(){
	empty = true;
}

Point::Point(double xCoord, double yCoord, double zCoord){
	empty = false;
	this->x = xCoord;
	this->y = yCoord;
	this->z = zCoord;
	Color* c = new Color();
	color = *(c);
}

Point::Point(float x, float y, float z){
	empty = false;
	Point((double)x,(double)y,(double)z);
}

Point::Point(int x, int y, int z){
	empty = false;
	Point((double)x,(double)y,(double)z);
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