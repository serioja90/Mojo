#include <QApplication>
#include <iostream>
#include "Window.h"

using namespace std;

int main(int argc, char** argv){
	QApplication app(argc,argv);
	Window window;
	window.resize(800,600);
	window.show();
	return app.exec();
}