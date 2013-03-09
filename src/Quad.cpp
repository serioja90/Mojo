#include "Quad.h"
#include <GL/gl.h>
#include <iostream>

using namespace std;

Quad::Quad(){
	this->empty = true;
}

Quad::Quad(Point a, Point b, Point c, Point d){
	empty = false;
	points.append(a);
	points.append(b);
	points.append(c);
	points.append(d);
	this->pointsOrder = GL_CCW;
}

Quad::Quad(Point a, Point b, Point c, Point d, int order){
	empty = false;
	points.append(a);
	points.append(b);
	points.append(c);
	points.append(d);
	this->pointsOrder = GL_CCW;
	this->setPointsOrder(order);
}

void Quad::setPointsOrder(int order){
	if(order!=GL_CW && order!=GL_CCW){
		throw Exception::InvalidPointsOrderException;
	}
	if(order!=this->pointsOrder){
		for(int i=0;i<points.length()/2;i++){
			points.swap(i,points.length()-i-1);
		}
	}
	this->pointsOrder = order;
}

QList<Point> Quad::getPoints(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadException;
	}
	return points;
}

bool Quad::isEmpty(){
	return this->empty;
}

int Quad::getPointsOrder(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadException;
	}
	return this->pointsOrder;
}

QList<const MaterialParameter*> Quad::getMaterialParameters(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadException;
	}
	return this->material.getParameters();
}

void Quad::setMaterialParameter(MaterialParameter &param){
	this->material.setParameter(param);
}