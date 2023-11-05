#ifndef MODELS_OBJECT_TRANSFORMER_H
#define MODELS_OBJECT_TRANSFORMER_H

#include <cmath>

#include "Object.h"

namespace s21 {

class ObjectTransformer {
 public:
  static void moveObject(s21::Object* object, double moveX, double moveY,
                         double moveZ) noexcept;
  static void scaleObject(s21::Object* object, double scaleX, double scaleY,
                          double scaleZ) noexcept;
  static void rotateObjectX(s21::Object* object, double angle) noexcept;
  static void rotateObjectY(s21::Object* object, double angle) noexcept;
  static void rotateObjectZ(s21::Object* object, double angle) noexcept;
};

}  // namespace s21

#endif  // MODELS_OBJECT_TRANSFORMER_H