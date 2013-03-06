#include "ShininessParameter.h"

ShininessParameter::ShininessParameter(){
	this->empty = true;
	this->vector = false;
}

ShininessParameter::ShininessParameter(GLint face, GLfloat value){
	this->empty = false;
	this->vector = false;
	this->setFace(face);
	this->setValue(value);
}

GLint ShininessParameter::getParameter(){
	if(this->isEmpty()){
		throw Exception::EmptyShininessParameterException;
	}
	return GL_SHININESS;
}