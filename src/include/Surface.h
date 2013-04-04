#ifndef SURFACE_H
#define SURFACE_H

#include <QList>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Point.h"
#include "Exception.h"

class Surface{
	public:
		Surface();
		Surface(QList<Point> points, GLint curves, GLint detalization, GLenum style);
		void addPoint(Point point);
		void setPoints(QList<Point> points);
		void setCurves(GLint curves);
		void setDetalization(GLint detalization);
		void setStyle(GLenum style);
		QList<Point> getPoints();
		GLint getCurves();
		GLint getDetalization();
		GLenum getStyle();
		GLfloat*** toArray();
	protected:
		QList<Point> points;
		GLint curves;
		GLint detalization;
		GLenum style;
};

#endif