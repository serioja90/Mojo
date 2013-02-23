#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QList>
#include "Point.h"
#include "Exception.h"

class Triangle{
	public:
		Triangle();
		Triangle(Point a, Point b, Point c);
		Triangle(Point a, Point b, Point c, int order);
		void setPointsOrder(int order);
		bool isEmpty();
		QList<Point> getPoints();
		int getPointsOrder();
	protected:
		bool empty;
		int pointsOrder;
		QList<Point> points;
		Point a;
		Point b;
		Point c;
};

#endif