#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QTextEdit>
#include "XmlParser.h"

class QMenu;
class QAction;

class MainWindow : public QMainWindow{
	Q_OBJECT
	public:
		MainWindow();
	private:
		QMenu* fileMenu;
		QAction* fileNew;

		QPushButton* newFileButton;
		QPushButton* openFileButton;
		QPushButton* saveFileButton;

		QTabWidget* tabWidget;
		QTextEdit* textEdit;

		XmlParser* xmlParser;

		void createToolBar();
	private slots:
		void createNewFile();
		void openFile();
};

#endif