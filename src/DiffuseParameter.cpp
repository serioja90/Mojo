#include "DiffuseParameter.h"

DiffuseParameter::DiffuseParameter(){
	this->empty = true;
	this->vector = true;
}

DiffuseParameter::DiffuseParameter(GLint face, GLfloat value[4]){
	this->empty = false;
	this->vector = true;
	this->setFace(face);
	this->setVectorValue(value);
}

GLint DiffuseParameter::getParameter(){
	if(this->isEmpty()){
		throw Exception::EmptyDiffuseParameterException;
	}
	return GL_DIFFUSE;
}