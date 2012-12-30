#include "Polygon.h"

Polygon::Polygon(){
	points = new QList<Point*>();
}

void Polygon::addPoint(Point* p){
	points->append(p);
}

QList<Point> Polygon::getPoints(){
	QList<Point>* result = new QList<Point>();
	for(int i=0;i<this->points->count();i++){
		Point point = *(this->points->at(i));
		result->append(point);
	}
	return *(result);
}