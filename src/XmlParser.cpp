#include <QtGui>
#include <iostream>

#include "XmlParser.h"

using namespace std;

XmlParser::XmlParser(QByteArray data){
	cout << "------------------------" << endl;
	cout << "Parsing xml file" << endl;
	QXmlStreamReader xml(data);
	objects = new QList<Object>();
	while(!xml.atEnd() && !xml.hasError()){
		if(xml.readNextStartElement()){
			if(xml.name()=="object"){
				objects->append(parseObject(xml));
			}
		}
	}
	cout << "End of xml parsing" << endl;
	cout << "------------------------" << endl;
}

QList<Object> XmlParser::getObjects(){
	QList<Object>* result = new QList<Object>();
	for(int i=0;i<this->objects->count();i++){
		Object obj = this->objects->at(i);
		result->append(obj);
	}
	return *(result);
}

Object XmlParser::parseObject(QXmlStreamReader& xml){
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
				obj->addTriangle(parseTriangle(xml));
			}else if(xml.name()=="quad"){
				obj->addQuad(parseQuad(xml));
			}else if(xml.name()=="polygon"){
				obj->addPolygon(parsePolygon(xml));
			}
		}
	}
	return *(obj);
}

Point XmlParser::parsePoint(QXmlStreamReader& xml){
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
	if(xml.tokenType()==QXmlStreamReader::StartElement && xml.tokenType()!=QXmlStreamReader::EndElement){
		while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="point")){
			xml.readNext();
			if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="color"){
				p->setColor(parseColor(xml));
			}
		}
	}
	return *(p);
}

Color XmlParser::parseColor(QXmlStreamReader& xml){
	Color* color;
	if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="color"){
		QXmlStreamAttributes attr = xml.attributes();
		float red,green,blue,alpha=0.0f;
		if(attr.hasAttribute("red") && attr.hasAttribute("green") && attr.hasAttribute("blue")){
			red = attr.value("red").toString().toFloat();
			green = attr.value("green").toString().toFloat();
			blue = attr.value("blue").toString().toFloat();
			if(attr.hasAttribute("alpha")){
				alpha = attr.value("alpha").toString().toFloat();
			}
			color = new Color(red,green,blue,alpha);
		}else{
			color = new Color();
		}

	}
	return *(color);
}

Line* XmlParser::parseLine(QXmlStreamReader& xml){
	Line* line;
	Point points[2];
	cout << "\tParsing line" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="line")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			if(vertexCount>2){
				throw WrongXmlLineFormatException;
			}
			points[vertexCount] = parsePoint(xml);
			vertexCount++;
		}
	}
	if(vertexCount!=2){
		throw WrongXmlLineFormatException;
	}
	line = new Line(points[0],points[1]);
	return line;
}

Triangle* XmlParser::parseTriangle(QXmlStreamReader& xml){
	Triangle* triangle;
	Point points[3];
	cout << "\tParsing triangle" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="triangle")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			points[vertexCount] = parsePoint(xml);
			vertexCount++;
		}
	}
	triangle = new Triangle(points[0],points[1],points[2]);
	return triangle;
}

Quad XmlParser::parseQuad(QXmlStreamReader& xml){
	Quad* quad;
	Point points[4];
	cout << "\tParsing quad" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="quad")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			points[vertexCount] = parsePoint(xml);
			vertexCount++;
		}
	}
	quad = new Quad(points[0],points[1],points[2],points[3]);
	return *(quad);
}

Polygon* XmlParser::parsePolygon(QXmlStreamReader& xml){
	Polygon* polygon = new Polygon();
	cout << "\tParsing polygon" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="polygon")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			polygon->addPoint(parsePoint(xml));
			vertexCount++;
		}
	}
	return polygon;
}