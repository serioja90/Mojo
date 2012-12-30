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