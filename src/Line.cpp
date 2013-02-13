#include "Line.h"

Line::Line(){
	this->empty = true;
}

Line::Line(Point start, Point end){
	this->empty = false;
	this->start = start;
	this->end = end;
}

QList<Point> Line::getPoints(){
	QList<Point> points;
	points.append(this->start);
	points.append(this->end);
	return points;
}

Point Line::getStartPoint(){
	if(this->isEmpty()){
		throw Exception::EmptyLineException;
	}
	return this->start;
}

Point Line::getEndPoint(){
	if(this->isEmpty()){
		throw Exception::EmptyLineException;
	}
	return this->end;
}

bool Line::isEmpty(){
	return this->empty;
}