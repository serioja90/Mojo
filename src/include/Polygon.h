#ifndef POLYGON_H
#define POLYGON_H

#include <QList>
#include "Point.h"

class Polygon{
	public:
		Polygon();
		void addPoint(Point* p);
	protected:
		QList<Point*>* points;
};

#endif