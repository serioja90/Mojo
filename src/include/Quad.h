#ifndef QUAD_H
#define QUAD_H

#include <QList>
#include "Point.h"
#include "Exception.h"
#include "Material.h"
#include "MaterialParameter.h"

class Quad{
	public:
		Quad();
		Quad(Point a, Point b, Point c, Point d);
		Quad(Point a, Point b, Point c, Point d, int order);
		void setPointsOrder(int order);
		QList<Point> getPoints();
		bool isEmpty();
		int getPointsOrder();
		QList<const MaterialParameter*> getMaterialParameters();
		void setMaterialParameter(MaterialParameter &param);
	protected:
		bool empty;
		QList<Point> points;
		Material material;
		int pointsOrder;
};

#endif