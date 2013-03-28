#ifndef CYLINDER_H
#define CYLINDER_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Exception.h"
#include "Point.h"
#include "Quadric.h"

class Cylinder : public Quadric{
	public:
		Cylinder();
		Cylinder(Point origin, GLfloat baseRadius, GLfloat topRadius, GLfloat height, GLint detalization);
		void setOrigin(Point origin);
		void setBaseRadius(GLfloat baseRadius);
		void setTopRadius(GLfloat topRadius);
		void setHeight(GLfloat height);
		void setDetalization(GLint detalization);
		Point getOrigin();
		GLfloat getBaseRadius();
		GLfloat getTopRadius();
		GLfloat getHeight();
		GLint getDetalization();
	private:
		Point origin;
		GLfloat baseRadius;
		GLfloat topRadius;
		GLfloat height;
		GLint detalization;
};

#endif