/**
 * @file Point.h
 * The current file contains the definition of the Point
 * structure and its attributes and methods.
 * @brief Point class definition.
 * @author Groza Sergiu
 */

#ifndef POINT_H
#define POINT_H

#include <GL/gl.h>
#include "Color.h"
#include "Exception.h"

/**
 * @class Point
 * The Point structure is one of mostly used inside the
 * application, because many other classes as Line, Triangle
 * Quad etc. use the Point structure to store information
 * about their vertexes. It also can store information about the
 * color of the point that it represents. Also this class
 * provides all the necessary methods for creating new
 * instances of Point and to get information about an existing
 * one.
 * @brief The structure created for storing information about
 *        3D points.
 */
class Point{
	public:
		/**
		 * The simpliest constructor for of the Point class. It
		 * creates an empty Point, that means that it doesn't
		 * contains any usable information.
		 * @return an empty Point object
		 */
		Point();
		/**
		 * This is a Point constructor that accept 3 GLdouble
		 * parameters as arguments, that represent rispectively
		 * the x,y and z coordinate.
		 * @see Point(GLfloat xCoord, GLfloat yCoord, GLfloat zCoord)
		 * @see Point(GLint xCoord, GLint yCoord, GLint zCoord)
		 * @param xCoord the x coordinate
		 * @param yCoord the y coordinate
		 * @param zCoord the z coordinate
		 * @return a Point object
		 */
		Point(GLdouble xCoord, GLdouble yCoord, GLdouble zCoord);
		/**
		 * This is a Point constructor that accept 3 GLfloat
		 * parameters as arguments, that represent rispectively
		 * the x,y and z coordinate.
		 * @see Point(GLdouble xCoord, GLdouble yCoord, GLdouble zCoord)
		 * @see Point(GLint xCoord, GLint yCoord, GLint zCoord)
		 * @param xCoord the x coordinate
		 * @param yCoord the y coordinate
		 * @param zCoord the z coordinate
		 * @return a Point object
		 */
		Point(GLfloat xCoord, GLfloat yCoord, GLfloat zCoord);
		/**
		 * This is a Point constructor that accept 3 GLfloat
		 * parameters as arguments, that represent rispectively
		 * the x,y and z coordinate.
		 * @see Point(GLdouble xCoord, GLdouble yCoord, GLdouble zCoord)
		 * @see Point(GLfloat xCoord, GLfloat yCoord, GLfloat zCoord)
		 * @param xCoord the x coordinate
		 * @param yCoord the y coordinate
		 * @param zCoord the z coordinate
		 * @return a Point object
		 */
		Point(GLint xCoord, GLint yCoord, GLint zCoord);
		/**
		 * The current method returns a boolean that indicates if
		 * the current Point object is empty or not.
		 * @return a boolean
		 */
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