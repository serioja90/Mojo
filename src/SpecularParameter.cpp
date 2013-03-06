#include "SpecularParameter.h"

SpecularParameter::SpecularParameter(){
	this->empty = true;
	this->vector = true;
}

SpecularParameter::SpecularParameter(GLint face, GLfloat value[4]){
	this->empty = false;
	this->vector = true;
	this->setFace(face);
	this->setVectorValue(value);
}

GLint SpecularParameter::getParameter(){
	if(this->isEmpty()){
		throw Exception::EmptySpecularParameterException;
	}
	return GL_SPECULAR;
}