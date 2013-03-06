#include "AmbientParameter.h"

AmbientParameter::AmbientParameter(){
	this->empty = true;
	this->vector = true;
}

AmbientParameter::AmbientParameter(GLint face, GLfloat value[4]){
	this->empty = false;
	this->vector = true;
	this->setFace(face);
	this->setVectorValue(value);
}

GLint AmbientParameter::getParameter(){
	if(this->isEmpty()){
		throw Exception::EmptyAmbientParameterException;
	}
	return GL_AMBIENT;
}
