#ifndef OBJECT_H
#define OBJECT_H

#include <QList>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Quad.h"
#include "Polygon.h"
#include "Sphere.h"
#include "Cylinder.h"

class Object{
	public:
		Object();
		void addPoint(Point point);
		void addLine(Line* line);
		void addTriangle(Triangle* triangle);
		void addQuad(Quad* quad);
		void addPolygon(Polygon* polygon);
		void addSphere(Sphere* sphere);
		void addCylinder(Cylinder* cylinder);
		QList<Point> getPoints();
		QList<Line> getLines();
		QList<Triangle> getTriangles();
		QList<Quad> getQuads();
		QList<Polygon> getPolygons();
		QList<Sphere> getSpheres();
		QList<Cylinder> getCylinders();
	protected:
		QList<Point>* points;
		QList<Line*>* lines;
		QList<Triangle*>* triangles;
		QList<Quad*>* quads;
		QList<Polygon*>* polygons;
		QList<Sphere*>* spheres;
		QList<Cylinder*>* cylinders;
};

#endif