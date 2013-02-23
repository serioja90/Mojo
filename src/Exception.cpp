#include "Exception.h"

Exception::Exception(int code, const QString& name, const QString& description){
	this->code = code;
	this->name = name;
	this->description = description;
}

int Exception::getCode(){
	return this->code;
}

QString Exception::getName(){
	return this->name;
}

QString Exception::getDescription(){
	return this->description;
}

const Exception Exception::InvalidXmlPointFormatException = Exception(
	0,
	"InvalidXmlPointFormatException",
	"The point structure inside the xml file has an invalid format"
);

const Exception Exception::InvalidXmlLineFormatException = Exception(
	1,
	"InvalidXmlLineFormatException",
	"The line structure inside the xml file has an invalid format"
);

const Exception Exception::InvalidXmlTriangleFormatException = Exception(
	2,
	"InvalidXmlTriangleFormatException",
	"The triangle structure inside the xml file has an invalid format"
);

const Exception Exception::InvalidXmlQuadFormatException = Exception(
	3,
	"InvalidXmlQuadFormatException",
	"The quad structure inside the xml file has an invalid format"
);

const Exception Exception::InvalidXmlPolygonFormatException = Exception(
	4,
	"InvalidXmlPolygonFormatException",
	"The polygon structure inside the xml file has an invalid format"
);

const Exception Exception::EmptyPointException = Exception(
	5,
	"EmptyPointException",
	"The point is empty and cannot provide any information"
);

const Exception Exception::EmptyLineException = Exception(
	6,
	"EmptyLineException",
	"The line is empty and cannot provide any information"
);

const Exception Exception::EmptyTriangleException = Exception(
	7,
	"EmptyTriangleException",
	"The triangle is empty and cannot provide any information"
);

const Exception Exception::EmptyQuadException = Exception(
	8,
	"EmptyQuadException",
	"The quad is empty and cannot provide any information"
);

const Exception Exception::EmptyPolygonException = Exception(
	9,
	"EmptyPolygonException",
	"The polygon is empty and cannot provide any information"
);

const Exception Exception::EmptyColorException = Exception(
	10,
	"EmptyColorException",
	"The color il empty and cannot provide any information"
);

const Exception Exception::InvalidPointsOrderException = Exception(
	11,
	"InvalidPointsOrderException",
	"Invalid value for points order attribute"
);