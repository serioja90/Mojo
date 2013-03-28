#ifndef QUADRIC_H
#define QUADRIC_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Exception.h"

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
	protected:
		bool empty;
		GLenum drawStyle;
		GLenum normalsType;
		GLenum orientation;
		GLenum uniformTexture;
};

#endif