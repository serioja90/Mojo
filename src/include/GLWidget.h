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
		void rotateLeft(float degrees);
		void rotateRight(float degrees);
		void rotateUp(float degrees);
		void rotateDown(float degrees);
		void addLeftRotation(float byDegrees);
		void addRightRotation(float byDegrees);

	protected:
		QList<Object>* objects;
		QTimer* timer;

		float rotX;
		float rotY;
		float rotZ;
		float stepX;
		float stepY;
		float stepZ;

		void initializeGL();
		void resizeGL(int width, int height);
		void paintGL();
		void paintObject(Object obj);
		void pointsToVertex(QList<Point> points);

	private:
		GLfloat* getNormal(QList<Point> points);

	private slots:
		void repaint();
};

#endif