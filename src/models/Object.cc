#include "Object.h"

using namespace s21;

Object::Object() noexcept
    : vertices(std::vector<Vertex>()),
      polygons(std::vector<std::vector<int>>()) {}

int Object::getVerticesNumber() const noexcept { return vertices.size(); }

int Object::getPolygonsNumber() const noexcept { return polygons.size(); }

void Object::addVertex(Vertex v) {
  vertices.push_back(v);
  updateMaxVertex(v);
  updateMinVertex(v);
}

void Object::updateMaxVertex(Vertex v) noexcept {
  if (getVerticesNumber() <= 1) {
    maxVertex = v;
    return;
  }

  maxVertex.x = std::max(maxVertex.x, v.x);
  maxVertex.y = std::max(maxVertex.y, v.y);
  maxVertex.z = std::max(maxVertex.z, v.z);
}

void Object::updateMinVertex(Vertex v) noexcept {
  if (getVerticesNumber() <= 1) {
    minVertex = v;
    return;
  }

  minVertex.x = std::min(minVertex.x, v.x);
  minVertex.y = std::min(minVertex.y, v.y);
  minVertex.z = std::min(minVertex.z, v.z);
}

void Object::addPolygon(std::vector<int> p) { polygons.push_back(p); }

const Vertex& Object::getVertex(int i) const { return vertices.at(i); }

const std::vector<int>& Object::getPolygon(int i) const {
  return polygons.at(i);
}

const Vertex& Object::getMaxVertex() const noexcept { return maxVertex; }

const Vertex& Object::getMinVertex() const noexcept { return minVertex; }

Vertex Object::getMidVertex() const noexcept {
  return Vertex(mean(maxVertex.x, minVertex.x), mean(maxVertex.y, minVertex.y),
                mean(maxVertex.z, minVertex.z));
}

double Object::mean(double a, double b) { return (a + b) / 2.0; }

Vertex& Object::accessVertex(int i) { return vertices.at(i); }
