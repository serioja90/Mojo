#ifndef DISK_H
#define DISK_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Exception.h"
#include "Quadric.h"
#include "Point.h"

class Disk : public Quadric{
	public:
		Disk();
		Disk(Point origin, GLfloat innerRadius, GLfloat outerRadius, GLint detalization);
		void setOrigin(Point origin);
		void setInnerRadius(GLfloat innerRadius);
		void setOuterRadius(GLfloat outerRadius);
		void setDetalization(GLint detalization);
		Point getOrigin();
		GLfloat getInnerRadius();
		GLfloat getOuterRadius();
		GLint getDetalization();
	protected:
		Point origin;
		GLfloat innerRadius;
		GLfloat outerRadius;
		GLint detalization;
};

#endif