#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QTextEdit>

class QMenu;
class QAction;
class QXmlStreamReader;

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

		void createToolBar();
		void parseXml(QByteArray data);
		void parseObject(QXmlStreamReader& xml);
		void parseQuad(QXmlStreamReader& xml);
	private slots:
		void createNewFile();
		void openFile();
};

#endif