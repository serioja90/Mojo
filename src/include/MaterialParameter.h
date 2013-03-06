#ifndef MATERIAL_PARAMETER_H
#define MATERIAL_PARAMETER_H

#include <GL/gl.h>
#include "Exception.h"

class MaterialParameter{
	public:
		void setFace(GLint face);
		void setValue(GLfloat value);
		void setVectorValue(GLfloat value[4]);
		GLint getFace();
		GLfloat getValue();
		GLfloat* getVectorValue();
		bool isEmpty();
		bool hasVectorValue();
		virtual GLint getParameter() = 0;
	protected:
		bool empty;
		bool vector;
		GLint face;
		GLfloat value;
		GLfloat vectorValue[4];
};

#endif