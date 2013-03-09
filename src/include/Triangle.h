#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QList>
#include "Point.h"
#include "Exception.h"
#include "Material.h"
#include "MaterialParameter.h"

class Triangle{
	public:
		Triangle();
		Triangle(Point a, Point b, Point c);
		Triangle(Point a, Point b, Point c, int order);
		void setPointsOrder(int order);
		bool isEmpty();
		QList<Point> getPoints();
		int getPointsOrder();
		QList<const MaterialParameter*> getMaterialParameters();
		void setMaterialParameter(MaterialParameter &param);
	protected:
		bool empty;
		int pointsOrder;
		QList<Point> points;
		Material material;
		Point a;
		Point b;
		Point c;
};

#endif