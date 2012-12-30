#ifndef QUAD_H
#define QUAD_H

#include "Point.h"

class Quad{
	public:
		Quad();
		Quad(Point* a, Point* b, Point* c, Point* d);
	protected:
		bool empty;
		Point* a;
		Point* b;
		Point* c;
		Point* d;
};

#endif