#ifndef WINDOW_H
#define WINDOW_H

#include <QGLWidget>

class GLWidget : public QGLWidget{
	Q_OBJECT
	public:
		GLWidget(QWidget* parent = 0);
	protected:
		void initGL();
		void resizeGL(int width, int height);
		void paintGL();
};

#endif