#ifndef POLYGON_H
#define POLYGON_H

#include <QList>
#include "Point.h"
#include "Material.h"
#include "MaterialParameter.h"

class Polygon{
	public:
		Polygon();
		void addPoint(Point p);
		QList<Point> getPoints();
		QList<const MaterialParameter*> getMaterialParameters();
		void setMaterialParameter(MaterialParameter &param);
	protected:
		QList<Point>* points;
		Material material;
};

#endif