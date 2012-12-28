#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	QApplication app(argc,argv);
	cout << "Application initializzed!" << endl;
	return app.exec();
}