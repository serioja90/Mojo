#ifndef SHININESS_PARAMETER_H
#define SHININESS_PARAMETER_H

#include <GL/gl.h>
#include "Exception.h"
#include "MaterialParameter.h"

class ShininessParameter : MaterialParameter{
	public:
		ShininessParameter();
		ShininessParameter(GLint face, GLfloat value);
		GLint getParameter();
};

#endif