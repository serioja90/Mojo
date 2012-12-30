#include "Triangle.h"

Triangle::Triangle(){
	this->empty = true;
}

Triangle::Triangle(Point* a, Point* b, Point* c){
	this->empty = false;
	this->a = a;
	this->b = b;
	this->c = c;
}

bool Triangle::isEmpty(){
	return this->empty;
}

QList<Point> Triangle::getPoints(){
	QList<Point>* result = new QList<Point>();
	if(this->isEmpty()){
		throw EmptyTriangleException;
	}
	result->append(*(this->a));
	result->append(*(this->b));
	result->append(*(this->c));
	return *(result);
}

