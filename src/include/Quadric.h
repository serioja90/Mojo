#ifndef QUADRIC_H
#define QUADRIC_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Exception.h"
#include "Material.h"

class Quadric{
	public:
		Quadric();
		void setDrawStyle(GLenum drawStyle);
		GLenum getDrawStyle();
		void setNormalsType(GLenum normalsType);
		GLenum getNormalsType();
		void setOrientation(GLenum orientation);
		GLenum getOrientation();
		void setTextureUniform(GLenum isUniform);
		GLenum isTextureUniform();
		bool isEmpty();
		void setQuadricAttributes(Quadric quadric);
		QList<const MaterialParameter*> getMaterialParameters();
		void setMaterialParameter(MaterialParameter &param);
	protected:
		bool empty;
		GLenum drawStyle;
		GLenum normalsType;
		GLenum orientation;
		GLenum uniformTexture;
		Material material;
};

#endif