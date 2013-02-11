#include "Color.h"

Color::Color(){
	this->red = 1.0f;
	this->green = 1.0f;
	this->blue = 1.0f;
	this->alpha = 0.0f;
}

Color::Color(float red, float green, float blue, float alpha){
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

Color::Color(float red, float green, float blue){
	Color(red,green,blue,0.0f);
}

Color::Color(int red, int green, int blue, int alpha){
	Color((float)red, (float)green, (float)blue, (float)alpha);
}

Color::Color(int red, int green, int blue){
	Color(red,green,blue,0);
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