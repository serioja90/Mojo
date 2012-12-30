#ifndef WINDOW_H
#define WINDOW_H

#include <QGLWidget>
#include <QList>
#include <QTimer>
#include "Object.h"

class GLWidget : public QGLWidget{
	Q_OBJECT
	public:
		GLWidget(QWidget* parent = 0);
		void setObjects(QList<Object> objects);
	protected:
		QList<Object>* objects;
		QTimer* timer;
		void initGL();
		void resizeGL(int width, int height);
		void paintGL();
		void paintObject(Object obj);

	private slots:
		void repaint();
};

#endif