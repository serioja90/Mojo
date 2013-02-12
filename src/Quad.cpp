#include "Quad.h"

#include <iostream>

using namespace std;

Quad::Quad(){
	this->empty = true;
}

Quad::Quad(Point pointA, Point pointB, Point pointC, Point pointD){
	empty = false;
	points.append(pointA);
	points.append(pointB);
	points.append(pointC);
	points.append(pointD);
}

QList<Point> Quad::getPoints(){
	return points;
}