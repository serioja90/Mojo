#ifndef QUAD_H
#define QUAD_H

#include <QList>
#include "Point.h"
#include "Exception.h"

class Quad{
	public:
		Quad();
		Quad(Point* a, Point* b, Point* c, Point* d);
		QList<Point> getPoints();
	protected:
		bool empty;
		Point* a;
		Point* b;
		Point* c;
		Point* d;
};

#endif