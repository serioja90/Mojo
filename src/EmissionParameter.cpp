#include "EmissionParameter.h"

EmissionParameter::EmissionParameter(){
	GLfloat default_value[4] = {0.0f, 0.0f, 0.0f, 1.0f};
	this->vector = true;
	this->setFace(GL_FRONT_AND_BACK);
	this->setVectorValue(default_value);
}

EmissionParameter::EmissionParameter(GLint face, GLfloat value[4]){
	this->vector = true;
	this->setFace(face);
	this->setVectorValue(value);
}

GLint EmissionParameter::getParameter() const{
	return GL_EMISSION;
}