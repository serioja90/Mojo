#ifndef DIFFUSE_PARAMETER_H
#define DIFFUSE_PARAMETER_H

#include <GL/gl.h>
#include "Exception.h"
#include "MaterialParameter.h"

class DiffuseParameter : public MaterialParameter{
	public:
		DiffuseParameter();
		DiffuseParameter(GLint face, GLfloat value[4]);
		GLint getParameter() const;
};

#endif