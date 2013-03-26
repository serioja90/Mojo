#ifndef SPHERE_H
#define SPHERE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Exception.h"
#include "Quadric.h"
#include "Point.h"
#include "Material.h"

class Sphere : public Quadric{
	public:
		Sphere();
		Sphere(Point origin, GLfloat radius, GLint detalization);
		void setOrigin(Point p);
		void setRadius(GLfloat radius);
		void setDetalization(GLint detalization);
		Point getOrigin();
		GLfloat getRadius();
		GLint getDetalization();
	private:
		Point origin;
		GLfloat radius;
		GLint detalization;
};

#endif