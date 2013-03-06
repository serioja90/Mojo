#include "MaterialProperty.h"

MaterialProperty::MaterialProperty(){
	this->empty = true;
}

MaterialProperty::MaterialProperty(GLint face, GLint parameter, GLint value){
	this->empty = false;
	this->vector = false;
	this->setFace(face);
	this->setParameter(parameter);
	this->value = (GLfloat)value;
}

MaterialProperty::MaterialProperty(GLint face, GLint parameter, GLint* value){
	int i;
	this->empty = false;
	this->vector = true;
	this->setFace(face);
	this->setParameter(parameter);
	for(i=0;i<4;i++){
		*(this->vectorValue+i) = (GLfloat)(*(value+i));
	}
}

MaterialProperty::MaterialProperty(GLint face, GLint parameter, GLfloat value){
	this->empty = false;
	this->vector = false;
	this->setFace(face);
	this->setParameter(parameter);
	this->value = value;
}

MaterialProperty::MaterialProperty(GLint face, GLint parameter, GLfloat* value){
	int i;
	this->empty = false;
	this->vector = true;
	this->setFace(face);
	this->setParameter(parameter);
	for(i=0;i<4;i++){
		this->vectorValue[i] = value[i];
	}
}

void MaterialProperty::setFace(GLint newFace){
	switch(newFace){
		case GL_FRONT:
		case GL_BACK:
		case GL_FRONT_AND_BACK:
			this->face = newFace;
			break;
		default:
			throw Exception::InvalidFaceException;
	}
}

void MaterialProperty::setParameter(GLint newParameter){
	switch(newParameter){
		case GL_AMBIENT:
		case GL_DIFFUSE:
		case GL_SPECULAR:
		case GL_EMISSION:
		case GL_SHININESS:
		case GL_AMBIENT_AND_DIFFUSE:
		case GL_COLOR_INDEXES:
			this->parameter = newParameter;
			break;
		default:
			throw Exception::InvalidParameterException;
	}
}

void MaterialProperty::setValue(GLint newValue){
	if(this->hasVector()){
		throw Exception::WrongTypeException;
	}
	this->value = (GLfloat)newValue;
}

void MaterialProperty::setValue(GLfloat newValue){
	if(this->hasVector()){
		throw Exception::WrongTypeException;
	}
	this->value = newValue;
}

void MaterialProperty::setVectorValue(GLint* newValue){
	GLint i;
	if(!this->hasVector()){
		throw Exception::WrongTypeException;
	}
	for(i=0;i<4;i++){
		this->vectorValue[i] = (GLfloat)newValue[i];
	}
}

void MaterialProperty::setVectorValue(GLfloat* newValue){
	GLint i;
	if(!this->hasVector()){
		throw Exception::WrongTypeException;
	}
	for(i=0;i<4;i++){
		this->vectorValue[i] = newValue[i];
	}
}

bool MaterialProperty::isEmpty(){
	return this->empty;
}

bool MaterialProperty::hasVector(){
	return this->vector;
}

GLint MaterialProperty::getFace(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialPropertyException;
	}
	return this->face;
}

GLint MaterialProperty::getParameter(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialPropertyException;
	}
	return this->parameter;
}

GLfloat MaterialProperty::getValue(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialPropertyException;
	}else if(this->hasVector()){
		throw Exception::WrongTypeException;
	}
	return this->value;
}

GLint MaterialProperty::getIntValue(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialPropertyException;
	}else if(this->hasVector()){
		throw Exception::WrongTypeException;
	}
	return (GLint)(this->value);
}

GLint* MaterialProperty::getIntVectorValue(){
	GLint* result;
	GLint i;
	if(this->isEmpty()){
		throw Exception::EmptyMaterialPropertyException;
	}else if(!this->hasVector()){
		throw Exception::WrongTypeException;
	}
	result = (GLint*)calloc(4,sizeof(GLint));
	for(i=0;i<4;i++){
		*(result+i) = (GLint)(*(this->vectorValue+i));
	}
	return result;
}

GLfloat* MaterialProperty::getFloatVectorValue(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialPropertyException;
	}else if(!this->hasVector()){
		throw Exception::WrongTypeException;
	}
	return this->vectorValue;
}