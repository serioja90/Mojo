#include <QtGui>
#include <GL/gl.h>
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
		try{
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
				}else if(xml.name()=="sphere"){
					obj->addSphere(parseSphere(xml));
				}else if(xml.name()=="cylinder"){
					obj->addCylinder(parseCylinder(xml));
				}else if(xml.name()=="disk"){
					obj->addDisk(parseDisk(xml));
				}
			}
		}catch(Exception e){
			QString msg = QString("Exception ") + QString::number(e.getCode()) + QString(":\n");
			msg += QString("'") + QString(e.getName()) + QString("'") ;
			msg += QString(" at line ") + QString::number(xml.lineNumber()) +QString("\n");
			msg += QString(e.getDescription());
			QMessageBox::critical(NULL,QString("Mojo"),msg);
			break;
			qDebug() << "Thrown exception: " << e.getCode() << "\t" << e.getName() << "\n" << e.getDescription();
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
			x = attr.value("x").toString().toDouble();
			y = attr.value("y").toString().toDouble();
			z = attr.value("z").toString().toDouble();
			p = new Point(x,y,z);
		}else{
			throw Exception::InvalidXmlPointFormatException;
		}
		if(attr.hasAttribute("color")){
			Color col = getColor(attr.value("color").toString());
			p->setColor(col);
		}
		while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="point")){
			xml.readNext();
		}
	}else{
		throw Exception::InvalidXmlPointFormatException;
	}
	cout << "\tx=" << p->getX() << "\ty=" << p->getY() << "\tz=" << p->getZ() << endl;
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

Color XmlParser::getColor(const QString& col){
	QString red = QString("FF"), green = QString("FF"), blue = QString("FF"), alpha = QString("FF");
	int r,g,b,a;
	bool ok;
	if(col.length()==3){
		red = QString(col.at(0)) + QString(col.at(0));
		green = QString(col.at(1)) + QString(col.at(1));
		blue = QString(col.at(2)) + QString(col.at(2));
	}else if(col.length()==6){
		red = QString(col.at(0)) + QString(col.at(1));
		green = QString(col.at(2)) + QString(col.at(3));
		blue = QString(col.at(4)) + QString(col.at(5));
	}else if(col.length()==8){
		red = QString(col.at(0)) + QString(col.at(1));
		green = QString(col.at(2)) + QString(col.at(3));
		blue = QString(col.at(4)) + QString(col.at(5));
		alpha = QString(col.at(6)) + QString(col.at(7));
	}
	r = red.toInt(&ok,16);
	g = green.toInt(&ok,16);
	b = blue.toInt(&ok,16);
	a = alpha.toInt(&ok,16);
	return Color(r,g,b,a);
}

QList<MaterialParameter*> XmlParser::getMaterialParameters(QXmlStreamReader& xml){
	QList<MaterialParameter*> material_parameters;
	GLfloat value[4];
	QStringList vals;
	GLint face;
	QXmlStreamAttributes attr;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="material")){
		xml.readNext();
		attr = xml.attributes();
		if(attr.hasAttribute("face")){
			if(attr.value("face").toString().toLower()=="front"){
				face = GL_FRONT;
			}else if(attr.value("face").toString().toLower()=="back"){
				face = GL_BACK;
			}else if(attr.value("face").toString().toLower()=="front_and_back"){
				face = GL_FRONT_AND_BACK;
			}else{
				throw Exception::InvalidXmlMaterialParameterFace;
			}
		}else{
			face = GL_FRONT_AND_BACK;
		}
		if(attr.hasAttribute("value")){
			vals = attr.value("value").toString().split(",");
			if(vals.count()!=1 && vals.count()!=4){
				throw Exception::InvalidXmlMaterialParameterValue;
			}
			for(int i=0;i<4 && i<vals.count();i++){
				value[i] = vals.at(i).toFloat();
			}
		}
		if(xml.name()=="ambient"){
			material_parameters.append(new AmbientParameter(face,value));
		}else if(xml.name()=="diffuse"){
			material_parameters.append(new DiffuseParameter(face,value));
		}else if(xml.name()=="specular"){
			material_parameters.append(new SpecularParameter(face,value));
		}else if(xml.name()=="shininess"){
			material_parameters.append(new ShininessParameter(face,value[0]));
		}else if(xml.name()=="emission"){
			material_parameters.append(new EmissionParameter(face,value));
		}
	}
	return material_parameters;
}

Line* XmlParser::parseLine(QXmlStreamReader& xml){
	Line* line;
	Point points[2];
	Color color = Color();
	QXmlStreamAttributes attr = xml.attributes();
	if(attr.hasAttribute("color")){
		color = getColor(attr.value("color").toString());
	}
	cout << "\tParsing line" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="line")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			if(vertexCount>2){
				throw Exception::InvalidXmlLineFormatException;
			}
			points[vertexCount] = parsePoint(xml);
			if(points[vertexCount].getColor().isEmpty() && !color.isEmpty()){
				points[vertexCount].setColor(color);
			}
			vertexCount++;
		}
	}
	if(vertexCount!=2){
		throw Exception::InvalidXmlLineFormatException;
	}
	line = new Line(points[0],points[1]);
	return line;
}

Triangle* XmlParser::parseTriangle(QXmlStreamReader& xml){
	Triangle* triangle;
	int order = GL_CCW;
	Point points[3];
	Color color = Color();
	QList<MaterialParameter*> material_parameters;
	QXmlStreamAttributes attr = xml.attributes();
	if(attr.hasAttribute("color")){
		color = getColor(attr.value("color").toString());
	}
	if(attr.hasAttribute("order")){
		if(attr.value("order").toString().toLower()=="cw"){
			order = GL_CW;
		}
	}
	cout << "\tParsing triangle" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="triangle")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			points[vertexCount] = parsePoint(xml);
			if(points[vertexCount].getColor().isEmpty() && !color.isEmpty()){
				points[vertexCount].setColor(color);
			}
			vertexCount++;
		}else if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="material"){
			material_parameters = getMaterialParameters(xml);
		}
	}
	if(vertexCount!=3){
		throw Exception::InvalidXmlTriangleFormatException;
	}
	triangle = new Triangle(points[0],points[1],points[2],order);
	for(int i=0;i<material_parameters.count();i++){
		triangle->setMaterialParameter(*(material_parameters.at(i)));
	}
	return triangle;
}

Quad* XmlParser::parseQuad(QXmlStreamReader& xml){
	Quad* quad;
	int order = GL_CCW;
	Color color = Color();
	Point points[4];
	QList<MaterialParameter*> material_parameters;
	cout << "\tParsing quad" << endl;
	int vertexCount = 0;
	QXmlStreamAttributes attr = xml.attributes();
	if(attr.hasAttribute("color")){
		color = getColor(attr.value("color").toString());
	}
	if(attr.hasAttribute("order")){
		if(attr.value("order").toString().toLower()=="cw"){
			order = GL_CW;
		}
	}
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="quad")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			points[vertexCount] = parsePoint(xml);
			if(points[vertexCount].getColor().isEmpty() && !color.isEmpty()){
				points[vertexCount].setColor(color);
			}
			vertexCount++;
		}else if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="material"){
			material_parameters = getMaterialParameters(xml);
		}
	}
	if(vertexCount!=4){
		throw Exception::InvalidXmlQuadFormatException;
	}
	quad = new Quad(points[0],points[1],points[2],points[3],order);
	for(int i=0;i<material_parameters.count();i++){
		quad->setMaterialParameter(*(material_parameters.at(i)));
	}
	return quad;
}

Polygon* XmlParser::parsePolygon(QXmlStreamReader& xml){
	Polygon* polygon = new Polygon();
	Color color = Color();
	QList<MaterialParameter*> material_parameters;
	QXmlStreamAttributes attr = xml.attributes();
	if(attr.hasAttribute("color")){
		color = getColor(attr.value("color").toString());
	}
	cout << "\tParsing polygon" << endl;
	int vertexCount = 0;
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="polygon")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="point"){
			cout << "\t";
			Point point = parsePoint(xml);
			if(point.getColor().isEmpty() && !color.isEmpty()){
				point.setColor(color);
			}
			polygon->addPoint(point);
			vertexCount++;
		}else if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="material"){
			material_parameters = getMaterialParameters(xml);
		}
	}
	for(int i=0;i<material_parameters.count();i++){
		polygon->setMaterialParameter(*(material_parameters.at(i)));
	}
	return polygon;
}

Quadric XmlParser::getQuadricFromAttributes(QXmlStreamAttributes& attr){
	Quadric quadric = Quadric();
	if(attr.hasAttribute("style")){
		QString style = attr.value("style").toString().toLower();
		if(style=="fill"){
			quadric.setDrawStyle(GLU_FILL);
		}else if(style=="line"){
			quadric.setDrawStyle(GLU_LINE);
		}else if(style=="point"){
			quadric.setDrawStyle(GLU_POINT);
		}else if(style=="silhouette"){
			quadric.setDrawStyle(GLU_SILHOUETTE);
		}else{
			throw Exception::InvalidXmlQuadricDrawStyleException;
		}
	}
	if(attr.hasAttribute("normals")){
		QString normals = attr.value("normals").toString().toLower();
		if(normals=="none"){
			quadric.setNormalsType(GLU_NONE);
		}else if(normals=="smooth"){
			quadric.setNormalsType(GLU_SMOOTH);
		}else if(normals=="flat"){
			quadric.setNormalsType(GLU_FLAT);
		}else{
			throw Exception::InvalidXmlQuadricNormalsTypeException;
		}
	}
	if(attr.hasAttribute("orientation")){
		QString orientation = attr.value("orientation").toString().toLower();
		if(orientation=="out"){
			quadric.setOrientation(GLU_OUTSIDE);
		}else if(orientation=="in"){
			quadric.setOrientation(GLU_INSIDE);
		}else{
			throw Exception::InvalidXmlQuadricOrientationException;
		}
	}
	if(attr.hasAttribute("uniform_texture")){
		QString uniform_texture = attr.value("uniform_texture").toString().toLower();
		if(uniform_texture=="true"){
			quadric.setTextureUniform(GL_TRUE);
		}else if(uniform_texture=="false"){
			quadric.setTextureUniform(GL_FALSE);
		}else{
			throw Exception::InvalidXmlQuadricTextureMappingTypeException;
		}
	}
	return quadric;
}

Sphere* XmlParser::parseSphere(QXmlStreamReader& xml){
	Sphere* sphere = new Sphere();
	Point origin;
	Color color = Color();
	QStringList vals;
	QXmlStreamAttributes attr = xml.attributes();
	if(attr.hasAttribute("origin")){
		vals = attr.value("origin").toString().split(",");
		if(vals.count()==3){
			GLfloat x,y,z;
			x = vals.at(0).toFloat();
			y = vals.at(1).toFloat();
			z = vals.at(2).toFloat();
			origin = Point(x,y,z);
		}else{
			throw Exception::InvalidXmlSphereOriginException;
		}
		if(attr.hasAttribute("color")){
			color = getColor(attr.value("color").toString());
			origin.setColor(color);
		}
		sphere->setOrigin(origin);
	}
	if(attr.hasAttribute("radius")){
		sphere->setRadius(attr.value("radius").toString().toFloat());
	}
	if(attr.hasAttribute("detalization")){
		sphere->setDetalization(attr.value("detalization").toString().toFloat());
	}
	sphere->setQuadricAttributes(getQuadricFromAttributes(attr));
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="sphere")){
		xml.readNext();
	}
	return sphere;
}

Cylinder* XmlParser::parseCylinder(QXmlStreamReader& xml){
	Cylinder* cylinder = new Cylinder();
	Point origin;
	Color color = Color();
	QStringList vals;
	QXmlStreamAttributes attr = xml.attributes();
	if(attr.hasAttribute("origin")){
		vals = attr.value("origin").toString().split(",");
		if(vals.count()==3){
			GLfloat x,y,z;
			x = vals.at(0).toFloat();
			y = vals.at(1).toFloat();
			z = vals.at(2).toFloat();
			origin = Point(x,y,z);
		}else{
			throw Exception::InvalidXmlSphereOriginException;
		}
		if(attr.hasAttribute("color")){
			color = getColor(attr.value("color").toString());
			origin.setColor(color);
		}
		cylinder->setOrigin(origin);
	}
	if(attr.hasAttribute("baseRadius")){
		cylinder->setBaseRadius(attr.value("baseRadius").toString().toFloat());
	}
	if(attr.hasAttribute("topRadius")){
		cylinder->setTopRadius(attr.value("topRadius").toString().toFloat());
	}
	if(attr.hasAttribute("height")){
		cylinder->setHeight(attr.value("height").toString().toFloat());
	}
	if(attr.hasAttribute("detalization")){
		cylinder->setDetalization(attr.value("detalization").toString().toFloat());
	}
	cylinder->setQuadricAttributes(getQuadricFromAttributes(attr));
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="cylinder")){
		xml.readNext();
	}
	return cylinder;
}

Disk* XmlParser::parseDisk(QXmlStreamReader& xml){
	Disk* disk = new Disk();
	Point origin;
	Color color = Color();
	QStringList vals;
	QXmlStreamAttributes attr = xml.attributes();
	if(attr.hasAttribute("origin")){
		vals = attr.value("origin").toString().split(",");
		if(vals.count()==3){
			GLfloat x,y,z;
			x = vals.at(0).toFloat();
			y = vals.at(1).toFloat();
			z = vals.at(2).toFloat();
			origin = Point(x,y,z);
		}else{
			throw Exception::InvalidXmlSphereOriginException;
		}
		if(attr.hasAttribute("color")){
			color = getColor(attr.value("color").toString());
			origin.setColor(color);
		}
		disk->setOrigin(origin);
	}
	if(attr.hasAttribute("innerRadius")){
		disk->setInnerRadius(attr.value("innerRadius").toString().toFloat());
	}
	if(attr.hasAttribute("outerRadius")){
		disk->setOuterRadius(attr.value("outerRadius").toString().toFloat());
	}
	if(attr.hasAttribute("detalization")){
		disk->setDetalization(attr.value("detalization").toString().toFloat());
	}
	disk->setQuadricAttributes(getQuadricFromAttributes(attr));
	while(!xml.atEnd() && !xml.hasError() && !(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="disk")){
		xml.readNext();
	}
	return disk;
}