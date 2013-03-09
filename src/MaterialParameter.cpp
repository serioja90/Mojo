#include "MaterialParameter.h"

void MaterialParameter::setFace(GLint face){
	switch(face){
		case GL_FRONT:
		case GL_BACK:
		case GL_FRONT_AND_BACK:
			this->face = face;
			break;
		default:
			throw Exception::InvalidFaceException;
	}
}


bool MaterialParameter::hasVectorValue() const{
	return this->vector;
}

GLint MaterialParameter::getFace() const{
	return this->face;
}

void MaterialParameter::setValue(GLfloat value){
	if(this->hasVectorValue()){
		throw Exception::WrongTypeException;
	}
	this->value = value;
}

void MaterialParameter::setVectorValue(GLfloat value[4]){
	if(!this->hasVectorValue()){
		throw Exception::WrongTypeException;
	}
	for(int i=0;i<4;i++){
		this->vectorValue[i] = value[i];
	}
}

GLfloat MaterialParameter::getValue() const{
	if(this->hasVectorValue()){
		throw Exception::WrongTypeException;
	}
	return this->value;
}

const GLfloat* MaterialParameter::getVectorValue() const{
	if(!this->hasVectorValue()){
		throw Exception::WrongTypeException;
	}
	return this->vectorValue;
}