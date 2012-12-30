#include <QtGui>
#include <iostream>

#include "XmlParser.h"

using namespace std;

XmlParser::XmlParser(QByteArray data){
	cout << "------------------------" << endl;
	cout << "Parsing xml file" << endl;
	QXmlStreamReader xml(data);
	QList<QXmlStreamReader> objects;
	while(!xml.atEnd() && !xml.hasError()){
		if(xml.readNextStartElement()){
			if(xml.name()=="object"){
				parseObject(xml);
			}
		}
	}
	cout << "End of xml parsing" << endl;
	cout << "------------------------" << endl;
}

void XmlParser::parseObject(QXmlStreamReader& xml){
	Object* obj = new Object();
	cout << "Parsing object" << endl;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="object")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement){
			if(xml.name()=="point"){
				obj->addPoint(parsePoint(xml));
			}else if(xml.name()=="line"){
				obj->addLine(parseLine(xml));
			}else if(xml.name()=="triangle"){
				parseTriangle(xml);
			}else if(xml.name()=="quad"){
				parseQuad(xml);
			}else if(xml.name()=="polygon"){
				parsePolygon(xml);
			}
		}
	}
}

Point* XmlParser::parsePoint(QXmlStreamReader& xml){
	Point* p;
	if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
		cout << "\tpoint";
		QXmlStreamAttributes attr = xml.attributes();
		if(attr.hasAttribute("x") && attr.hasAttribute("y") && attr.hasAttribute("z")){
			double x,y,z;
			cout << "\tx=" << qPrintable(attr.value("x").toString())
				 << "\ty=" << qPrintable(attr.value("y").toString())
				 << "\tz=" << qPrintable(attr.value("z").toString()) << endl;
			x = attr.value("x").toString().toDouble();
			y = attr.value("y").toString().toDouble();
			z = attr.value("z").toString().toDouble();
			p = new Point(x,y,z);
		}
	}
	return p;
}

Line* XmlParser::parseLine(QXmlStreamReader& xml){
	Line* line;
	Point* points[2];
	cout << "\tParsing line" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="line")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			if(vertexCount>2){
				throw WrongXmlLineFormat;
			}
			points[vertexCount] = parsePoint(xml);
			vertexCount++;
		}
	}
	if(vertexCount!=2){
		throw WrongXmlLineFormat;
	}
	line = new Line(points[0],points[1]);
	return line;
}

void XmlParser::parseTriangle(QXmlStreamReader& xml){
	cout << "\tParsing triangle" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="triangle")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			parsePoint(xml);
			vertexCount++;
		}
	}
}

void XmlParser::parseQuad(QXmlStreamReader& xml){
	cout << "\tParsing quad" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="quad")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			parsePoint(xml);
			vertexCount++;
		}
	}
}

void XmlParser::parsePolygon(QXmlStreamReader& xml){
	cout << "\tParsing polygon" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="polygon")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			parsePoint(xml);
			vertexCount++;
		}
	}
}