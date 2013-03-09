#include "DiffuseParameter.h"

DiffuseParameter::DiffuseParameter(){
	GLfloat default_value[4] = {0.8f, 0.8f, 0.8f, 1.0f};
	this->vector = true;
	this->setFace(GL_FRONT_AND_BACK);
	this->setVectorValue(default_value);
}

DiffuseParameter::DiffuseParameter(GLint face, GLfloat value[4]){
	this->vector = true;
	this->setFace(face);
	this->setVectorValue(value);
}

GLint DiffuseParameter::getParameter() const{
	return GL_DIFFUSE;
}