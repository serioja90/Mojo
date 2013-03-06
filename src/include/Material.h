#ifndef MATERIAL_H
#define MATERIAL_H

#include <QList>
#include <GL/gl.h>
#include "MaterialProperty.h"

class Material{
	public:
		Material();
		void addProperty(MaterialProperty prop);
		bool isEmpty();
		QList<MaterialProperty> getProperties();
	private:
		bool empty;
		QList<MaterialProperty> properties;
};

#endif