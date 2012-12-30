#include "Quad.h"

Quad::Quad(){
	this->empty = true;
}

Quad::Quad(Point* a, Point* b, Point* c, Point* d){
	this->empty = false;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

QList<Point> Quad::getPoints(){
	QList<Point>* result = new QList<Point>();
	result->append(*(this->a));
	result->append(*(this->b));
	result->append(*(this->c));
	result->append(*(this->d));
	return *(result);
}