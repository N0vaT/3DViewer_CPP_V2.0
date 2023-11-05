#include "ObjectTransformer.h"

using namespace s21;

void ObjectTransformer::moveObject(Object* object, double moveX, double moveY,
                                   double moveZ) noexcept {
  int vn = object->getVerticesNumber();
  for (int i = 0; i < vn; i++) {
    Vertex& vertex = object->accessVertex(i);
    vertex.x += moveX;
    vertex.y += moveY;
    vertex.z += moveZ;
  }
}

void ObjectTransformer::scaleObject(Object* object, double scaleX,
                                    double scaleY, double scaleZ) noexcept {
  int vn = object->getVerticesNumber();
  for (int i = 0; i < vn; i++) {
    Vertex& vertex = object->accessVertex(i);
    vertex.x *= scaleX;
    vertex.y *= scaleY;
    vertex.z *= scaleZ;
  }
}

void ObjectTransformer::rotateObjectX(Object* object, double angle) noexcept {
  int vn = object->getVerticesNumber();
  for (int i = 0; i < vn; i++) {
    Vertex& vertex = object->accessVertex(i);

    double y = vertex.y;
    double z = vertex.z;
    vertex.y = y * cos(angle) + z * sin(angle);
    vertex.z = (-y) * sin(angle) + z * cos(angle);
  }
}

void ObjectTransformer::rotateObjectY(Object* object, double angle) noexcept {
  int vn = object->getVerticesNumber();
  for (int i = 0; i < vn; i++) {
    Vertex& vertex = object->accessVertex(i);

    double x = vertex.x;
    double z = vertex.z;
    vertex.x = x * cos(angle) + z * sin(angle);
    vertex.z = (-x) * sin(angle) + z * cos(angle);
  }
}

void ObjectTransformer::rotateObjectZ(Object* object, double angle) noexcept {
  int vn = object->getVerticesNumber();
  for (int i = 0; i < vn; i++) {
    Vertex& vertex = object->accessVertex(i);

    double x = vertex.x;
    double y = vertex.y;
    vertex.x = x * cos(angle) + y * sin(angle);
    vertex.y = (-x) * sin(angle) + y * cos(angle);
  }
}
