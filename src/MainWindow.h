#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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

		void createToolBar();
};

#endif