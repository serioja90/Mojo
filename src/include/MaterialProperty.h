#ifndef MATERIAL_PROPERTY_H
#define MATERIAL_PROPERTY_H

#include <GL/gl.h>
#include "Exception.h"

class MaterialProperty{
	public:
		MaterialProperty();
		MaterialProperty(GLint face, GLint parameter, GLint value);
		MaterialProperty(GLint face, GLint parameter, GLfloat value);
		MaterialProperty(GLint face, GLint parameter, GLint* value);
		MaterialProperty(GLint face, GLint parameter, GLfloat* value);
		void setFace(GLint newFace);
		void setParameter(GLint newParameter);
		void setValue(GLint newValue);
		void setValue(GLfloat newValue);
		void setVectorValue(GLint* newValue);
		void setVectorValue(GLfloat* newValue);
		bool isEmpty();
		bool hasVector();
		GLint getFace();
		GLint getParameter();
		GLfloat getValue();
		GLint getIntValue();
		GLint* getIntVectorValue();
		GLfloat* getFloatVectorValue();
	private:
		bool empty;
		bool vector;
		GLint face;
		GLint parameter;
		GLfloat value;
		GLfloat vectorValue[4];
};

#endif