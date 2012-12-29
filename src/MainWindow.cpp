#include <QtGui>
#include <QToolBar>
#include <QPushButton>
#include <QIcon>
#include <QSize>

#include "MainWindow.h"
#include "GLWidget.h"

MainWindow::MainWindow(){
	GLWidget* glWidget = new GLWidget();
	setCentralWidget(glWidget);
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
	toolBar->addWidget(newFileButton);

	openFileButton = new QPushButton();
	openFileButton->setIcon(QIcon(":open-file.png"));
	openFileButton->setIconSize(QSize(20,20));
	openFileButton->setToolTip(tr("Open a file"));
	openFileButton->setMaximumWidth(28);
	openFileButton->setCursor(Qt::PointingHandCursor);
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