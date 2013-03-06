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

bool MaterialParameter::isEmpty(){
	return this->empty;
}

bool MaterialParameter::hasVectorValue(){
	return this->vector;
}

GLint MaterialParameter::getFace(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialParameterException;
	}
	return this->face;
}

void MaterialParameter::setValue(GLfloat value){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialParameterException;
	}else if(this->hasVectorValue()){
		throw Exception::WrongTypeException;
	}
	this->value = value;
}

void MaterialParameter::setVectorValue(GLfloat value[4]){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialParameterException;
	}else if(!this->hasVectorValue()){
		throw Exception::WrongTypeException;
	}
	for(int i=0;i<4;i++){
		this->vectorValue[i] = value[i];
	}
}

GLfloat MaterialParameter::getValue(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialParameterException;
	}else if(this->hasVectorValue()){
		throw Exception::WrongTypeException;
	}
	return this->value;
}

GLfloat* MaterialParameter::getVectorValue(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialParameterException;
	}else if(!this->hasVectorValue()){
		throw Exception::WrongTypeException;
	}
	return this->vectorValue;
}