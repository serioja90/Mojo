#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QList>
#include "Point.h"
#include "Exception.h"

class Triangle{
	public:
		Triangle();
		Triangle(Point a, Point b, Point c);
		bool isEmpty();
		QList<Point> getPoints();
	protected:
		bool empty;
		Point a;
		Point b;
		Point c;
};

#endif