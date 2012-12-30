#include "Triangle.h"

Triangle::Triangle(){
	this->empty = false;
}

Triangle::Triangle(Point* a, Point* b, Point* c){
	this->empty = true;
	this->a = a;
	this->b = b;
	this->c = c;
}

bool Triangle::isEmpty(){
	return this->empty;
}

