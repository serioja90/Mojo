#include "Object.h"

Object::Object(){
	points = new QList<Point>();
	lines = new QList<Line*>();
	triangles = new QList<Triangle*>();
	quads = new QList<Quad>();
	polygons = new QList<Polygon*>();
}

void Object::addPoint(Point point){
	points->append(point);
}

void Object::addLine(Line* line){
	lines->append(line);
}

void Object::addTriangle(Triangle* triangle){
	triangles->append(triangle);
}

void Object::addQuad(Quad quad){
	quads->append(quad);
}

void Object::addPolygon(Polygon* polygon){
	polygons->append(polygon);
}

QList<Point> Object::getPoints(){
	QList<Point>* result = new QList<Point>();
	for(int i=0;i<this->points->count();i++){
		Point point = this->points->at(i);
		result->append(point);
	}
	return *(result);
}

QList<Line> Object::getLines(){
	QList<Line>* result = new QList<Line>();
	for(int i=0;i<this->lines->count();i++){
		Line line = *(this->lines->at(i));
		result->append(line);
	}
	return *(result);
}

QList<Triangle> Object::getTriangles(){
	QList<Triangle>* result = new QList<Triangle>();
	for(int i=0;i<this->triangles->count();i++){
		Triangle triangle = *(this->triangles->at(i));
		result->append(triangle);
	}
	return *(result);
}

QList<Quad> Object::getQuads(){
	QList<Quad>* result = new QList<Quad>();
	for(int i=0;i<this->quads->count();i++){
		Quad quad = this->quads->at(i);
		result->append(quad);
	}
	return *(result);
}

QList<Polygon> Object::getPolygons(){
	QList<Polygon>* result = new QList<Polygon>();
	for(int i=0;i<this->polygons->count();i++){
		Polygon polygon = *(this->polygons->at(i));
		result->append(polygon);
	}
	return *(result);
}