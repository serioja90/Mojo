#ifndef OBJECT_H
#define OBJECT_H

#include <QList>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Quad.h"
#include "Polygon.h"

class Object{
	public:
		Object();
		void addPoint(Point* point);
		void addLine(Line* line);
		void addTriangle(Triangle* triangle);
		void addQuad(Quad* quad);
		void addPolygon(Polygon* polygon);
		QList<Point> getPoints();
		QList<Line> getLines();
		QList<Triangle> getTriangles();
		QList<Quad> getQuads();
		QList<Polygon> getPolygons();
	protected:
		QList<Point*>* points;
		QList<Line*>* lines;
		QList<Triangle*>* triangles;
		QList<Quad*>* quads;
		QList<Polygon*>* polygons;
};

#endif