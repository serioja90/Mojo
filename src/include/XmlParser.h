#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QByteArray>
#include "Object.h"
#include "Point.h"
#include "Exception.h"

class QXmlStreamReader;

class XmlParser{
	public:
		XmlParser(QByteArray data);
	protected:
		void parseObject(QXmlStreamReader& xml);
		Point* parsePoint(QXmlStreamReader& xml);
		Line* parseLine(QXmlStreamReader& xml);
		void parseTriangle(QXmlStreamReader& xml);
		void parseQuad(QXmlStreamReader& xml);
		void parsePolygon(QXmlStreamReader& xml);
};

#endif