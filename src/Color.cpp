#include "Color.h"
#include "Exception.h"

Color::Color(){
	this->empty = true;
}

Color::Color(float red, float green, float blue, float alpha){
	this->empty = false;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

Color::Color(float red, float green, float blue){
	this->empty = false;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = 1.0f;
}

Color::Color(int red, int green, int blue, int alpha){
	this->empty = false;
	this->red = (float)red/(float)255;
	this->green = (float)green/(float)255;
	this->blue = (float)blue/(float)255;
	this->alpha = (float)alpha/(float)255;
}

Color::Color(int red, int green, int blue){
	this->empty = false;
	this->red = (float)red/(float)255;
	this->green = (float)green/(float)255;
	this->blue = (float)blue/(float)255;
	this->alpha = 1.0f;
}

float Color::getRed(){
	if(this->isEmpty()){
		throw Exception::EmptyColorException;
	}
	return this->red;
}

float Color::getGreen(){
	if(this->isEmpty()){
		throw Exception::EmptyColorException;
	}
	return this->green;
}

float Color::getBlue(){
	if(this->isEmpty()){
		throw Exception::EmptyColorException;
	}
	return this->blue;
}

float Color::getAlpha(){
	if(this->isEmpty()){
		throw Exception::EmptyColorException;
	}
	return this->alpha;
}

bool Color::isEmpty(){
	return this->empty;
}