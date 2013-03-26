#ifndef POINT_H
#define POINT_H

#include <GL/gl.h>

#include "Color.h"

class Point{
	public:
		Point();
		Point(GLdouble xCoord, GLdouble yCoord, GLdouble zCoord);
		Point(GLfloat xCoord, GLfloat yCoord, GLfloat zCoord);
		Point(GLint xCoord, GLint yCoord, GLint zCoord);
		bool isEmpty();
		void setColor(Color color);
		GLfloat getX();
		GLfloat getY();
		GLfloat getZ();
		Color getColor();
		static GLfloat* toArray(Point p);
	protected:
		Color color;
		bool empty;
		GLfloat x;
		GLfloat y;
		GLfloat z;
};

#endif