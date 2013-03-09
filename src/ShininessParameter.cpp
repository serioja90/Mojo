#include "ShininessParameter.h"

ShininessParameter::ShininessParameter(){
	this->vector = false;
	this->setFace(GL_FRONT_AND_BACK);
	this->setValue(0.0f);
}

ShininessParameter::ShininessParameter(GLint face, GLfloat value){
	this->vector = false;
	this->setFace(face);
	this->setValue(value);
}

GLint ShininessParameter::getParameter() const{
	return GL_SHININESS;
}