#ifndef MODELS_VERTEX_H
#define MODELS_VERTEX_H

namespace s21 {

struct Vertex {
  Vertex() = default;
  Vertex(double xv, double yv, double zv) noexcept;

  double x;
  double y;
  double z;
};

}  // namespace s21

#endif  // MODELS_VERTEX_H
