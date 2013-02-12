#include <QApplication>
#include <iostream>
#include "MainWindow.h"

using namespace std;

int main(int argc, char** argv){
	QApplication app(argc,argv);
	MainWindow window;
	window.resize(800,600);
	window.setWindowTitle("Mojo - 3D Models Creator");
	window.show();
	return app.exec();
}