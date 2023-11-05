#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QOpenGLWidget>

#include "../models/IObserver.h"
#include "../models/Object.h"
#include "../models/Settings.h"

class GLWidget : public QOpenGLWidget, public s21::IObserver {
 public:
  GLWidget(QWidget* parent = nullptr);
  //  GLWidget(s21::Object* obj, s21::Settings* set, Vertex minVertex, Vertex
  //  maxVertex);

  ~GLWidget() = default;

  void initializeGL() override;
  void paintGL() override;

  void updateSettings() override {
    paintGL();
    update();
  }

  s21::Object* getObject();
  s21::Settings* getSettings();
  void setObject(s21::Object* object);
  void setSettings(s21::Settings* settings);

  s21::Vertex minV;
  s21::Vertex maxV;

 private:
  s21::Object* object = nullptr;
  s21::Settings* settings = nullptr;
};

#endif  // GLWIDGET_H
