#ifndef POINT_H
#define POINT_H

#include "Color.h"

class Point{
	public:
		Point();
		Point(double xCoord, double yCoord, double zCoord);
		Point(float xCoord, float yCoord, float zCoord);
		Point(int xCoord, int yCoord, int zCoord);
		bool isEmpty();
		void setX(double xCoord);
		void setY(double yCoord);
		void setZ(double zCoord);
		void setColor(Color color);
		double getX();
		double getY();
		double getZ();
		Color getColor();
	protected:
		Color color;
		bool empty;
		double x;
		double y;
		double z;
};

#endif