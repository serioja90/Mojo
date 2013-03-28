#include "Quadric.h"

Quadric::Quadric(){
	this->empty = false;
	this->drawStyle = GL_FILL;
	this->normalsType = GLU_SMOOTH;
	this->orientation = GLU_OUTSIDE;
	this->uniformTexture = GL_TRUE;
}

bool Quadric::isEmpty(){
	return this->empty;
}

void Quadric::setDrawStyle(GLenum drawStyle){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	switch(drawStyle){
		case GLU_FILL:
		case GLU_LINE:
		case GLU_POINT:
		case GLU_SILHOUETTE:
			this->drawStyle = drawStyle;
			break;
		default:
			throw Exception::InvalidQuadricDrawStyleException;
	}
}

GLenum Quadric::getDrawStyle(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->drawStyle;
}

void Quadric::setNormalsType(GLenum normalsType){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	switch(normalsType){
		case GLU_NONE:
		case GLU_SMOOTH:
		case GLU_FLAT:
			this->normalsType = normalsType;
			break;
		default:
			throw Exception::InvalidQuadricNormalsTypeException;
	}
}

GLenum Quadric::getNormalsType(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->normalsType;
}

void Quadric::setOrientation(GLenum orientation){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	switch(orientation){
		case GLU_INSIDE:
		case GLU_OUTSIDE:
			this->orientation = orientation;
			break;
		default:
			throw Exception::InvalidQuadricOrientationException;
	}
}

GLenum Quadric::getOrientation(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->orientation;
}

void Quadric::setTextureUniform(GLenum isUniform){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	switch(isUniform){
		case GL_TRUE:
		case GL_FALSE:
			this->uniformTexture = isUniform;
			break;
		default:
			throw Exception::InvalidQuadricTextureMappingTypeException;
	}
}

GLenum Quadric::isTextureUniform(){
	if(this->isEmpty()){
		throw Exception::EmptyQuadricException;
	}
	return this->uniformTexture;
}

void Quadric::setQuadricAttributes(Quadric quadric){
	this->drawStyle = quadric.getDrawStyle();
	this->normalsType = quadric.getNormalsType();
	this->orientation = quadric.getOrientation();
	this->uniformTexture = quadric.isTextureUniform();
}

QList<const MaterialParameter*> Quadric::getMaterialParameters(){
	return this->material.getParameters();
}

void Quadric::setMaterialParameter(MaterialParameter &param){
	this->material.setParameter(param);
}