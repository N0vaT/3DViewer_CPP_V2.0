#ifndef CONTROLLERS_VIEWER_CONTROLLER_H
#define CONTROLLERS_VIEWER_CONTROLLER_H

#include <iostream>

#include "../models/ObjectReader.h"
#include "../models/ObjectTransformer.h"
#include "../models/Settings.h"
#include "../models/SettingsSaver.h"

namespace s21 {

class ViewerController {
 public:
  ViewerController() noexcept;
  explicit ViewerController(s21::ObjectReader objectReader,
                            s21::ObjectTransformer objectTransformer,
                            s21::SettingsSaver* settingsSaver) noexcept;
  ViewerController(const ViewerController& other) noexcept;
  ViewerController(ViewerController&& other) noexcept;
  ViewerController& operator=(const ViewerController& other);
  ViewerController& operator=(ViewerController&& other);
  ~ViewerController() = default;

  s21::Object initObject(const std::string& filePath);
  void moveObject(s21::Object* object, double moveX, double moveY,
                  double moveZ);
  void scaleObject(s21::Object* object, double scaleX, double scaleY,
                   double scaleZ);
  void rotateObjectX(s21::Object* object, double angle);
  void rotateObjectY(s21::Object* object, double angle);
  void rotateObjectZ(s21::Object* object, double angle);
  s21::Vertex& middlePoint(s21::Object* object);
  void readSettings();
  void writeSettings();

 private:
  s21::ObjectReader objectReader;
  s21::ObjectTransformer objectTransformer;
  s21::SettingsSaver* settingsSaver;
};

}  // namespace s21

#endif  // CONTROLLERS_VIEWER_CONTROLLER_H
