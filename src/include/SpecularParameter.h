#ifndef SPECULAR_PARAMETER_H
#define SPECULAR_PARAMETER_H

#include <GL/gl.h>
#include "Exception.h"
#include "MaterialParameter.h"

class SpecularParameter : public MaterialParameter{
	public:
		SpecularParameter();
		SpecularParameter(GLint face, GLfloat value[4]);
		GLint getParameter() const;
};

#endif