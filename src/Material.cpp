#include "Material.h"

Material::Material(){
	this->empty = true;
}

void Material::addProperty(MaterialProperty prop){
	this->empty = false;
	this->properties.append(prop);
}

bool Material::isEmpty(){
	return this->empty;
}

QList<MaterialProperty> Material::getProperties(){
	if(this->isEmpty()){
		throw Exception::EmptyMaterialException;
	}
	return this->properties;
}