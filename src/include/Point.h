#ifndef POINT_H
#define POINT_H

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
		double getX();
		double getY();
		double getZ();
	protected:
		bool empty;
		double x;
		double y;
		double z;
};

#endif