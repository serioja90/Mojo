#include "Polygon.h"

Polygon::Polygon(){
	points = new QList<Point*>();
}

void Polygon::addPoint(Point* p){
	points->append(p);
}