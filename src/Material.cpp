#include "Material.h"

Material::Material(){
	AmbientParameter default_ambient = *(new AmbientParameter());
	DiffuseParameter default_diffuse = *(new DiffuseParameter());
	SpecularParameter default_specular = *(new SpecularParameter());
	ShininessParameter default_shininess = *(new ShininessParameter());
	EmissionParameter default_emission = *(new EmissionParameter());
	this->setParameter(default_ambient);
	this->setParameter(default_diffuse);
	this->setParameter(default_specular);
	this->setParameter(default_shininess);
	this->setParameter(default_emission);
}

void Material::setParameter(MaterialParameter &param){
	switch(param.getParameter()){
		case GL_AMBIENT:
			ambient.append(dynamic_cast<AmbientParameter&>(param));
			break;
		case GL_DIFFUSE:
			diffuse.append(dynamic_cast<DiffuseParameter&>(param));
			break;
		case GL_SPECULAR:
			specular.append(dynamic_cast<SpecularParameter&>(param));
			break;
		case GL_SHININESS:
			shininess.append(dynamic_cast<ShininessParameter&>(param));
			break;
		case GL_EMISSION:
			emission.append(dynamic_cast<EmissionParameter&>(param));
			break;
		default:
			throw Exception::InvalidMaterialParameterException;
	}
}

QList<const MaterialParameter*> Material::getParameters(){
	QList<const MaterialParameter*> parameters;
	for(int i=0;i<ambient.count();i++){
		parameters << &(ambient.at(i));
	}
	for(int i=0;i<diffuse.count();i++){
		parameters << &(diffuse.at(i));
	}
	for(int i=0;i<specular.count();i++){
		parameters << &(specular.at(i));
	}
	for(int i=0;i<shininess.count();i++){
		parameters << &(shininess.at(i));
	}
	for(int i=0;i<emission.count();i++){
		parameters << &(emission.at(i));
	}
	return parameters;
}