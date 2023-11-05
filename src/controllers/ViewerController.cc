#include "ViewerController.h"

namespace s21 {
ViewerController::ViewerController() noexcept {}
ViewerController::ViewerController(s21::ObjectReader objectReader,
                                   s21::ObjectTransformer objectTransformer,
                                   s21::SettingsSaver* settingsSaver) noexcept {
  this->objectReader = objectReader;
  this->objectTransformer = objectTransformer;
  this->settingsSaver = settingsSaver;
}
ViewerController::ViewerController(const ViewerController& other) noexcept
    : objectReader(other.objectReader),
      objectTransformer(other.objectTransformer),
      settingsSaver(other.settingsSaver) {}
ViewerController::ViewerController(ViewerController&& other) noexcept
    : ViewerController() {
  std::swap(objectReader, other.objectReader);
  std::swap(objectTransformer, other.objectTransformer);
  std::swap(settingsSaver, other.settingsSaver);
}
ViewerController& ViewerController::operator=(const ViewerController& other) {
  if (this != &other) {
    objectReader = other.objectReader;
    objectTransformer = other.objectTransformer;
    settingsSaver = other.settingsSaver;
  }
  return *this;
}

ViewerController& ViewerController::operator=(ViewerController&& other) {
  if (this != &other) {
    objectReader = std::move(other.objectReader);
    objectTransformer = std::move(other.objectTransformer);
    settingsSaver = std::move(other.settingsSaver);
  }
  return *this;
}

s21::Object ViewerController::initObject(const std::string& filePath) {
  return objectReader.readObject(filePath);
}

void ViewerController::moveObject(s21::Object* object, double moveX,
                                  double moveY, double moveZ) {
  objectTransformer.moveObject(object, moveX, moveY, moveZ);
}

void ViewerController::scaleObject(s21::Object* object, double scaleX,
                                   double scaleY, double scaleZ) {
  objectTransformer.scaleObject(object, scaleX, scaleY, scaleZ);
}

void ViewerController::rotateObjectX(s21::Object* object, double angle) {
  objectTransformer.rotateObjectX(object, angle);
}

void ViewerController::rotateObjectY(s21::Object* object, double angle) {
  objectTransformer.rotateObjectY(object, angle);
}

void ViewerController::rotateObjectZ(s21::Object* object, double angle) {
  objectTransformer.rotateObjectZ(object, angle);
}

s21::Vertex& ViewerController::middlePoint(s21::Object* object) {
  s21::Vertex vertex = object->getMidVertex();
  return vertex;
}

void ViewerController::readSettings() { settingsSaver->readSettings(); }

void ViewerController::writeSettings() { settingsSaver->writeSettings(); }

}  // namespace s21
