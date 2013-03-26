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

const Exception Exception::InvalidFaceException = Exception(
	12,
	"InvalidFaceException",
	"Invalid value for face attribute"
);

const Exception Exception::InvalidParameterException = Exception(
	13,
	"InvalidParameterException",
	"Invalid value for parameter type attribute"
);

const Exception Exception::EmptyMaterialPropertyException = Exception(
	14,
	"EmptyMaterialPropertyException",
	"Empty material property cannot provide any information"
);

const Exception Exception::WrongTypeException = Exception(
	15,
	"WrongTypeException",
	"The value passed as parameter has a wrong type"
);

const Exception Exception::EmptyMaterialException = Exception(
	16,
	"EmptyMaterialException",
	"Empty material cannot provide any information"
);

const Exception Exception::EmptyMaterialParameterException = Exception(
	17,
	"EmptyMaterialParameterException",
	"Cannot set or get infromation for empty material parameter"
);

const Exception Exception::EmptyAmbientParameterException = Exception(
	18,
	"EmptyAmbientParameterException",
	"Cannot set or get information for empty ambient parameter"
);

const Exception Exception::EmptyDiffuseParameterException = Exception(
	19,
	"EmptyDiffuseParameterException",
	"Cannot set or get information for empty diffuse parameter"
);

const Exception Exception::EmptySpecularParameterException = Exception(
	20,
	"EmptySpecularParameterException",
	"Cannot set or get information for empty specular parameter"
);

const Exception Exception::EmptyShininessParameterException = Exception(
	21,
	"EmptyShininessParameterException",
	"Cannot set or get information for empty shininess parameter"
);

const Exception Exception::EmptyEmissionParameterException = Exception(
	22,
	"EmptyEmissionParameterException",
	"Cannot set or get information for empty emission parameter"
);

const Exception Exception::InvalidMaterialParameterException = Exception(
	23,
	"InvalidMaterialParameterException",
	"Invalid value for material parameter attribute"
);

const Exception Exception::InvalidXmlMaterialParameterFace = Exception(
	24,
	"InvalidXmlMaterialParameterFace",
	"Invalid value for material parameter face"
);

const Exception Exception::InvalidXmlMaterialParameterValue = Exception(
	25,
	"InvalidXmlMaterialParameterValue",
	"Invalid value for material parameter"
);

const Exception Exception::InvalidQuadricDrawStyleException = Exception(
	26,
	"InvalidQuadrciDrawStyleException",
	"Invalid value for quadric draw style attribute"
);

const Exception Exception::InvalidQuadricNormalsTypeException = Exception(
	27,
	"InvalidQuadricNormalsTypeException",
	"Invalid value for quadric normals type arrtibute"
);

const Exception Exception::InvalidQuadricOrientationException = Exception(
	28,
	"InvalidQuadricOrientationException",
	"Invalid value for quadric orientation attribute"
);

const Exception Exception::InvalidQuadricTextureMappingTypeException = Exception(
	29,
	"InvalidQuadricTextureMappingTypeException",
	"Invalid value for quadric texture mapping type attribute"
);

const Exception Exception::EmptyQuadricException = Exception(
	30,
	"EmptyQuadricException",
	"Cannot set or get information for empty quadric"
);

const Exception Exception::InvalidXmlSphereOriginException = Exception(
	31,
	"InvalidXmlSphereOriginException",
	"Invalid value for sphere origin"
);