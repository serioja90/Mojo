#ifndef AMBIENT_PARAMETER_H
#define AMBIENT_PARAMETER_H

#include <GL/gl.h>
#include "Exception.h"
#include "MaterialParameter.h"

class AmbientParameter : MaterialParameter{
	public:
		AmbientParameter();
		AmbientParameter(GLint face, GLfloat value[4]);
		GLint getParameter();
};

#endif