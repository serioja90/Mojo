#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QByteArray>
#include <QList>
#include "Object.h"
#include "Color.h"
#include "Exception.h"

class QXmlStreamReader;

class XmlParser{
	public:
		XmlParser(QByteArray data);
		QList<Object> getObjects();
	protected:
		QList<Object>* objects;
		Object parseObject(QXmlStreamReader& xml);
		Point parsePoint(QXmlStreamReader& xml);
		Line* parseLine(QXmlStreamReader& xml);
		Triangle* parseTriangle(QXmlStreamReader& xml);
		Quad* parseQuad(QXmlStreamReader& xml);
		Polygon* parsePolygon(QXmlStreamReader& xml);
		Sphere* parseSphere(QXmlStreamReader& xml);
		Cylinder* parseCylinder(QXmlStreamReader& xml);
		Disk* parseDisk(QXmlStreamReader& xml);
		Surface* parseSurface(QXmlStreamReader& xml);
		Color parseColor(QXmlStreamReader& xml);
		Color getColor(const QString&);
		QList<MaterialParameter*> getMaterialParameters(QXmlStreamReader& xml);
		Quadric getQuadricFromAttributes(QXmlStreamAttributes& attr);
};

#endif