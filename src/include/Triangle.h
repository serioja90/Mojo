#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle{
	public:
		Triangle();
		Triangle(Point* a, Point* b, Point* c);
		bool isEmpty();
	protected:
		bool empty;
		Point* a;
		Point* b;
		Point* c;
};

#endif