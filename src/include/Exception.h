#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class QString;

class Exception{
	public:
		Exception(int code, const QString& name, const QString& description);
		int getCode();
		QString getName();
		QString getDescription();
		static const Exception InvalidXmlPointFormatException;
		static const Exception InvalidXmlLineFormatException;
		static const Exception InvalidXmlTriangleFormatException;
		static const Exception InvalidXmlQuadFormatException;
		static const Exception InvalidXmlPolygonFormatException;
		static const Exception EmptyPointException;
		static const Exception EmptyLineException;
		static const Exception EmptyTriangleException;
		static const Exception EmptyQuadException;
		static const Exception EmptyPolygonException;
		static const Exception EmptyColorException;
		static const Exception InvalidPointsOrderException;
		static const Exception InvalidFaceException;
		static const Exception InvalidParameterException;
		static const Exception EmptyMaterialPropertyException;
		static const Exception WrongTypeException;
		static const Exception EmptyMaterialException;
		static const Exception EmptyMaterialParameterException;
		static const Exception EmptyAmbientParameterException;
		static const Exception EmptyDiffuseParameterException;
		static const Exception EmptySpecularParameterException;
		static const Exception EmptyShininessParameterException;
	private:
		int code;
		QString name;
		QString description;
};

#endif