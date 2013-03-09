#include "AmbientParameter.h"

AmbientParameter::AmbientParameter(){
	GLfloat default_value[4] = {0.2f,0.2f,0.2f,1.0f};
	this->vector = true;
	this->setFace(GL_FRONT_AND_BACK);
	this->setVectorValue(default_value);
}

AmbientParameter::AmbientParameter(GLint face, GLfloat value[4]){
	this->vector = true;
	this->setFace(face);
	this->setVectorValue(value);
}

GLint AmbientParameter::getParameter() const{
	return GL_AMBIENT;
}
