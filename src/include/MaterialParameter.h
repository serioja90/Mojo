#ifndef MATERIAL_PARAMETER_H
#define MATERIAL_PARAMETER_H

#include <GL/gl.h>
#include "Exception.h"

class MaterialParameter{
	public:
		void setFace(GLint face);
		void setValue(GLfloat value);
		void setVectorValue(GLfloat value[4]);
		GLint getFace() const;
		GLfloat getValue() const;
		const GLfloat* getVectorValue() const;
		bool hasVectorValue() const;
		virtual GLint getParameter() const = 0;
	protected:
		bool vector;
		GLint face;
		GLfloat value;
		GLfloat vectorValue[4];
};

#endif