#include "Point.h"
#include "Exception.h"

Point::Point(){
	empty = true;
}

Point::Point(double x, double y, double z){
	empty = false;
	this->x = x;
	this->y = y;
	this->z = z;
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
		throw EmptyPointException;
	}
	return this->x;
}

double Point::getY(){
	if(this->isEmpty()){
		throw EmptyPointException;
	}
	return this->y;
}

double Point::getZ(){
	if(this->isEmpty()){
		throw EmptyPointException;
	}
	return this->z;
}