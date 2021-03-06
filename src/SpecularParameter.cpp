#include "SpecularParameter.h"

SpecularParameter::SpecularParameter(){
	GLfloat default_value[4] = {0.0f, 0.0f, 0.0f, 1.0f};
	this->vector = true;
	this->setFace(GL_FRONT_AND_BACK);
	this->setVectorValue(default_value);
}

SpecularParameter::SpecularParameter(GLint face, GLfloat value[4]){
	this->vector = true;
	this->setFace(face);
	this->setVectorValue(value);
}

GLint SpecularParameter::getParameter() const{
	return GL_SPECULAR;
}