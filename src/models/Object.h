#ifndef MODELS_OBJECT_H
#define MODELS_OBJECT_H

#include <vector>

#include "Vertex.h"

namespace s21 {

class Object {
 public:
  Object() noexcept;
  ~Object() = default;

  int getVerticesNumber() const noexcept;
  int getPolygonsNumber() const noexcept;

  void addVertex(Vertex v);
  void addPolygon(std::vector<int> p);

  const Vertex& getVertex(int i) const;
  const std::vector<int>& getPolygon(int i) const;

  const Vertex& getMaxVertex() const noexcept;
  const Vertex& getMinVertex() const noexcept;
  Vertex getMidVertex() const noexcept;

  Vertex& accessVertex(int i);

 private:
  std::vector<Vertex> vertices;
  std::vector<std::vector<int>> polygons;

  Vertex maxVertex;
  Vertex minVertex;

  void updateMaxVertex(Vertex v) noexcept;
  void updateMinVertex(Vertex v) noexcept;

  static double mean(double a, double b);
};

}  // namespace s21

#endif  // MODELS_OBJECT_H