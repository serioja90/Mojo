#ifndef LINE_H
#define LINE_H

#include <QList>
#include "Point.h"
#include "Exception.h"

class Line{
	public:
		Line();
		Line(Point* start, Point* end);
		bool isEmpty();
		QList<Point> getPoints();
		Point getStartPoint();
		Point getEndPoint();
	protected:
		bool empty;
		Point* start;
		Point* end;
};

#endif