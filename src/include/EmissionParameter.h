#ifndef EMISSION_PARAMETER_H
#define EMISSION_PARAMETER_H

#include <GL/gl.h>
#include "Exception.h"
#include "MaterialParameter.h"

class EmissionParameter : public MaterialParameter{
	public:
		EmissionParameter();
		EmissionParameter(GLint face, GLfloat value[4]);
		GLint getParameter() const;
};

#endif