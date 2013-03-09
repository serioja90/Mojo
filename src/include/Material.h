#ifndef MATERIAL_H
#define MATERIAL_H

#include <QtGui>
#include <QList>
#include <GL/gl.h>
#include "Exception.h"
#include "MaterialParameter.h"
#include "AmbientParameter.h"
#include "DiffuseParameter.h"
#include "SpecularParameter.h"
#include "ShininessParameter.h"
#include "EmissionParameter.h"

class Material{
	public:
		Material();
		void setParameter(MaterialParameter &param);
		QList<const MaterialParameter*> getParameters();
	private:
		QList<AmbientParameter> ambient;
		QList<DiffuseParameter> diffuse;
		QList<SpecularParameter> specular;
		QList<ShininessParameter> shininess;
		QList<EmissionParameter> emission;
};

#endif