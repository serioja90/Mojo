#include "Triangle.h"
#include <QtGui>
#include <GL/gl.h>

Triangle::Triangle(){
	this->empty = true;
}

Triangle::Triangle(Point a, Point b, Point c){
	this->empty = false;
	this->points.append(a);
	this->points.append(b);
	this->points.append(c);
	this->pointsOrder = GL_CCW;
}

Triangle::Triangle(Point a, Point b, Point c, int order){
	this->empty = false;
	this->points.append(a);
	this->points.append(b);
	this->points.append(c);
	this->pointsOrder = GL_CCW;
	this->setPointsOrder(order);
}

void Triangle::setPointsOrder(int order){
	if(order!=GL_CCW && order!=GL_CW){
		throw Exception::InvalidPointsOrderException;
	}
	if(order!=this->pointsOrder){
		for(int i=0;i<points.length()/2;i++){
			points.swap(i,points.length()-i-1);
		}
	}
	this->pointsOrder = order;
}

bool Triangle::isEmpty(){
	return this->empty;
}

QList<Point> Triangle::getPoints(){
	if(this->isEmpty()){
		throw Exception::EmptyTriangleException;
	}
	return this->points;
}

int Triangle::getPointsOrder(){
	if(this->isEmpty()){
		throw Exception::EmptyTriangleException;
	}
	return this->pointsOrder;
}

Material Triangle::getMaterial(){
	return this->material;
}



