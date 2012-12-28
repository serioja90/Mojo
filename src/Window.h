#ifndef WINDOW_H
#define WINDOW_H

#include <QGLWidget>

class Window : public QGLWidget{
	Q_OBJECT
	public:
		Window(QWidget* parent = 0);
	protected:
		void initGL();
		void resizeGL(int width, int height);
		void paintGL();
		void keyPressEvent(QKeyEvent* event);
};

#endif