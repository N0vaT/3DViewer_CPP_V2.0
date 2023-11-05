#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QTimer>
#include <QWidget>
#include <QtOpenGLWidgets>
#include <list>

#include "QtWidgets/qpushbutton.h"

#ifdef __controllers
#endif
#include "../controllers/ViewerController.h"
#ifdef __controllers
#endif

#ifdef __model
#endif
#include "../models/ISubject.h"
#include "../models/Object.h"
#include "../models/ObjectReader.h"
#include "../models/ObjectTransformer.h"
#include "../models/Settings.h"
#include "../models/SettingsSaver.h"
#include "../models/Vertex.h"
#ifdef __model
#endif

#include "gifmaker/gif_hash.h"
#include "gifmaker/gif_lib.h"
#include "gifmaker/gif_lib_private.h"
#include "gifmaker/qgifglobal.h"
#include "gifmaker/qgifimage.h"
#include "gifmaker/qgifimage_p.h"
#include "glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public s21::ISubject {
  Q_OBJECT

 public:
  MainWindow(s21::ViewerController viewerController, s21::Settings *settings,
             QWidget *parent = nullptr);
  ~MainWindow();

  void openFile();
  void rotate();
  void move();
  void scale();
  void chooseColor();
  void takeScreenshot();
  void recordGIF();
  void attach(s21::IObserver *observer) override {
    listObserver.push_back(observer);
  }
  void detach(s21::IObserver *observer) override {
    listObserver.remove(observer);
  }
  void notify() override {
    std::list<s21::IObserver *>::iterator iterator = listObserver.begin();
    while (iterator != listObserver.end()) {
      (*iterator)->updateSettings();
      ++iterator;
    }
  }

  QTimer *timer;
  QList<QImage> screens;
  s21::Vertex minVertex = {0.0, 0.0, 0.0};
  s21::Vertex maxVertex = {0.0, 0.0, 0.0};

 private:
  void applySettings();
  void tick();
  s21::ViewerController viewerController;
  Ui::MainWindow *ui;
  s21::Object object;
  GLWidget *glwidget;
  s21::Settings *settings;
  QColor dotColor;
  QColor lineColor;
  QColor backColor;
  bool dotColorFlag;
  bool lineColorFlag;
  bool backColorFlag;
  int timerCounter;
  std::string settingsPath;
  std::list<s21::IObserver *> listObserver;
};
#endif  // MAINWINDOW_H
