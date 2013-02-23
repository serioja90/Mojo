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
	private:
		int code;
		QString name;
		QString description;
};

#endif