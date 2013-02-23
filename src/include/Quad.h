#ifndef QUAD_H
#define QUAD_H

#include <QList>
#include "Point.h"
#include "Exception.h"

class Quad{
	public:
		Quad();
		Quad(Point a, Point b, Point c, Point d);
		Quad(Point a, Point b, Point c, Point d, int order);
		void setPointsOrder(int order);
		QList<Point> getPoints();
		bool isEmpty();
		int getPointsOrder();
	protected:
		bool empty;
		QList<Point> points;
		int pointsOrder;
};

#endif