#include "Color.h"

Color::Color(){
	this->red = 1.0f;
	this->green = 1.0f;
	this->blue = 1.0f;
	this->alpha = 1.0f;
}

Color::Color(float red, float green, float blue, float alpha){
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

Color::Color(float red, float green, float blue){
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = 1.0f;
}

Color::Color(int red, int green, int blue, int alpha){
	this->red = (float)red;
	this->green = (float)green;
	this->blue = (float)blue;
	this->alpha = (float)alpha;
}

Color::Color(int red, int green, int blue){
	this->red = (float)red;
	this->green = (float)green;
	this->blue = (float)blue;
	this->alpha = 1.0f;
}

float Color::getRed(){
	return this->red;
}

float Color::getGreen(){
	return this->green;
}

float Color::getBlue(){
	return this->blue;
}

float Color::getAlpha(){
	return this->alpha;
}