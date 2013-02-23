#include <QtGui>
#include <QToolBar>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QFileDialog>

#include <iostream>

#include "MainWindow.h"

using namespace std;

MainWindow::MainWindow(){
	glWidget = new GLWidget();
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
		xmlParser = new XmlParser(data);
		glWidget->setObjects(xmlParser->getObjects());
		QTextDocument document(content);
		textEdit->setDocument(new QTextDocument(content));
	}
}

void MainWindow::keyPressEvent(QKeyEvent* event){
	switch(event->key()){
		case Qt::Key_A:
			glWidget->rotateLeft(0.05f);
			break;
		case Qt::Key_D:
			glWidget->rotateRight(0.05f);
			break;
		case Qt::Key_W:
			glWidget->rotateUp(0.05f);
			break;
		case Qt::Key_S:
			glWidget->rotateDown(0.05f);
			break;
	}
}