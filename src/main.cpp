#include <QApplication>

#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::ObjectReader objectReader;
  s21::ObjectTransformer objectTransformer;
  s21::Settings settings;
  s21::SettingsSaver *settingsSaver = s21::SettingsSaver::getInstance("/tmp/settings.json", &settings);
  s21::ViewerController viewerController(objectReader, objectTransformer, settingsSaver);
  MainWindow w(viewerController, &settings);
  w.attach(settingsSaver);
  w.show();
  return a.exec();
}
