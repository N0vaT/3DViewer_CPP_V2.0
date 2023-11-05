#include "glwidget.h"

GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent) {}
void GLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void GLWidget::paintGL() {
  double minCoord = minV.x;
  if (minCoord > minV.y) minCoord = minV.y;
  if (minCoord > minV.z) minCoord = minV.z;

  double maxCoord = maxV.x;
  if (maxCoord < maxV.y) maxCoord = maxV.y;
  if (maxCoord < maxV.z) maxCoord = maxV.z;

  minCoord *= 2;
  maxCoord *= 2;

  glClearColor(settings->getBackColor().red, settings->getBackColor().green,
               settings->getBackColor().blue, 1);

  glClear(GL_COLOR_BUFFER_BIT);  // чистим буфер
  glMatrixMode(GL_PROJECTION);   // устанавливаем матрицу
  glLoadIdentity();              // загружаем матрицу
  if (settings->getProjectionType() == 1) {
    glOrtho(minCoord, maxCoord, minCoord, maxCoord, minCoord,
            maxCoord);  // подготавливаем плоскости для матрицы
  } else {
    glFrustum(-1, 1, -1, 1, 0.5, 40);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPointSize(settings->getDotSize());  // Размер точки
  if (settings->getDotType() == 0) {
    glEnable(GL_POINT_SMOOTH);
  }
  if (settings->getDotType() == 0 || settings->getDotType() == 1) {
    glBegin(GL_POINTS);
    glColor3f(settings->getDotColor().red, settings->getDotColor().green,
              settings->getDotColor().blue);  // Цвет которым рисовать
    for (int i = 0; object != nullptr && i < object->getVerticesNumber(); i++) {
      glVertex3d(object->getVertex(i).x, object->getVertex(i).y,
                 object->getVertex(i).z);
    }
    glEnd();
  }

  if (settings->getLineType() == 0) {
    glEnable(GL_LINE);
  } else if (settings->getLineType() == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
  }

  if (settings->getLineType() == 0 || settings->getLineType() == 1) {
    glLineWidth(settings->getLineSize());
    glColor3f(settings->getLineColor().red, settings->getLineColor().green,
              settings->getLineColor().blue);
    int k = 0;
    for (int i = 0; object != nullptr && i < object->getPolygonsNumber(); i++) {
      glBegin(GL_LINE_LOOP);
      for (int j = 0; j < object->getPolygon(i).size(); j++) {
        k = object->getPolygon(i).at(j) - 1;
        glVertex3d(object->getVertex(k).x, object->getVertex(k).y,
                   object->getVertex(k).z);
      }
      glEnd();
    }
  }
}

s21::Object* GLWidget::getObject() { return object; }
s21::Settings* GLWidget::getSettings() { return settings; }
void GLWidget::setObject(s21::Object* object) { this->object = object; }
void GLWidget::setSettings(s21::Settings* settings) {
  this->settings = settings;
}
