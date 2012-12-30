#include <QtGui>
#include <QToolBar>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QFileDialog>

#include <iostream>

#include "MainWindow.h"
#include "GLWidget.h"

using namespace std;

MainWindow::MainWindow(){
	GLWidget* glWidget = new GLWidget();
	tabWidget = new QTabWidget();
	textEdit = new QTextEdit();
	tabWidget->addTab(glWidget,QString(tr("View")));
	tabWidget->addTab(textEdit,QString(tr("Code")));
	setCentralWidget(tabWidget);
	fileNew = new QAction(tr("&New"),this);
	fileNew->setStatusTip(tr("Create a new file"));
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(fileNew);
	createToolBar();
}

void MainWindow::createToolBar(){
	QToolBar* toolBar = new QToolBar();
	toolBar->setMovable(false);

	newFileButton = new QPushButton();
	newFileButton->setIcon(QIcon(":new-file.png"));
	newFileButton->setIconSize(QSize(20,20));
	newFileButton->setToolTip(tr("Create a new file"));
	newFileButton->setMaximumWidth(28);
	newFileButton->setCursor(Qt::PointingHandCursor);
	connect(newFileButton,SIGNAL(released()),this,SLOT(createNewFile()));
	toolBar->addWidget(newFileButton);

	openFileButton = new QPushButton();
	openFileButton->setIcon(QIcon(":open-file.png"));
	openFileButton->setIconSize(QSize(20,20));
	openFileButton->setToolTip(tr("Open a file"));
	openFileButton->setMaximumWidth(28);
	openFileButton->setCursor(Qt::PointingHandCursor);
	connect(openFileButton,SIGNAL(released()),this,SLOT(openFile()));
	toolBar->addWidget(openFileButton);

	saveFileButton = new QPushButton();
	saveFileButton->setIcon(QIcon(":save-file.png"));
	saveFileButton->setIconSize(QSize(20,20));
	saveFileButton->setToolTip(tr("Save the current file"));
	saveFileButton->setMaximumWidth(28);
	saveFileButton->setCursor(Qt::PointingHandCursor);
	toolBar->addWidget(saveFileButton);

	addToolBar(toolBar);
}

void MainWindow::createNewFile(){
	cout << "Create new file!" << endl;
}

void MainWindow::openFile(){
	QFileDialog fileDialog(this,Qt::Dialog);
	QStringList filters,files;
	filters << "XML files (*.xml)" << "Model files (*.mdl)";
	fileDialog.setNameFilters(filters);
	fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
	fileDialog.exec();
	files = fileDialog.selectedFiles();
	if(!files.empty()){
		QFile* file = new QFile(files.first());
		file->open(QIODevice::ReadWrite);
		QByteArray data = file->readAll();
		QString content(data);
		parseXml(data);
		QTextDocument document(content);
		textEdit->setDocument(new QTextDocument(content));
	}
}

void MainWindow::parseXml(QByteArray data){
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

void MainWindow::parseObject(QXmlStreamReader& xml){
	cout << "Parsing object" << endl;
	while(!(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="object")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="quad"){
			parseQuad(xml);
		}
	}
}

void MainWindow::parseQuad(QXmlStreamReader& xml){
	cout << "Parsing quad" << endl;
	int vertexCount = 0;
	while(!(xml.tokenType()==QXmlStreamReader::EndElement && xml.name()=="quad")){
		xml.readNext();
		if(xml.tokenType()==QXmlStreamReader::StartElement && xml.name()=="vertex"){
			cout << "vertex";
			vertexCount++;
			QXmlStreamAttributes attributes = xml.attributes();
			if(attributes.hasAttribute("x")){
				cout << "\tx=" << qPrintable(attributes.value("x").toString());
			}
			if(attributes.hasAttribute("y")){
				cout << "\ty=" << qPrintable(attributes.value("y").toString());
			}
			if(attributes.hasAttribute("z")){
				cout << "\tz=" << qPrintable(attributes.value("z").toString()) << endl;
			}
		}
	}
	if(vertexCount!=4){
		QMessageBox::critical(this,tr("Xml parsing error"),tr("Xml structure error: wrong vertex number."));
	}
}