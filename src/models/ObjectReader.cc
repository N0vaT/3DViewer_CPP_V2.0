#include "ObjectReader.h"

using namespace s21;

Object ObjectReader::readObject(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::exception();  // TODO: change to other exception
  }

  Object object = Object();
  std::string line;
  while (file) {
    std::getline(file, line);
    parseLine(object, line);
  }

  file.close();
  return object;
}

void ObjectReader::parseLine(Object& object, const std::string& line) {
  if (line.size() <= 2) {
    return;
  }

  if (line.at(0) == 'f') {
    readPolygon(object, line);
  } else if (line.at(0) == 'v') {
    readVertex(object, line);
  }
}

void ObjectReader::readVertex(Object& object, const std::string& line) {
  std::string::const_iterator iter = line.begin();
  std::string::const_iterator end = line.end();
  ++iter;
  if (*iter != ' ') {
    return;
  }

  skipSpace(iter, end);
  double x = std::stod(readDouble(iter, end));
  skipSpace(iter, end);
  double y = std::stod(readDouble(iter, end));
  skipSpace(iter, end);
  double z = std::stod(readDouble(iter, end));

  object.addVertex(Vertex(x, y, z));
}

void ObjectReader::skipSpace(std::string::const_iterator& iter,
                             const std::string::const_iterator& end) {
  while (*iter == ' ' && iter != end) {
    ++iter;
  }
}

std::string ObjectReader::readDouble(std::string::const_iterator& iter,
                                     const std::string::const_iterator& end) {
  std::string s;
  while (iter != end && *iter != ' ' && *iter != '/') {
    s += *iter;
    ++iter;
  }

  return s;
}

void ObjectReader::readPolygon(Object& object, const std::string& line) {
  std::vector<int> polygon;
  std::string::const_iterator iter = line.begin();
  std::string::const_iterator end = line.end();
  ++iter;
  if (*iter != ' ') {
    return;
  }

  while (iter != end) {
    skipSpace(iter, end);
    int polygonNumber;
    try {
      polygonNumber = std::stoi(readDouble(iter, end));
    } catch (std::exception& e) {
      break;
    }
    polygon.push_back(polygonNumber >= 0
                          ? polygonNumber
                          : object.getVerticesNumber() + polygonNumber + 1);
    while (iter != end && *iter != ' ') {
      ++iter;
    }
  }
  object.addPolygon(polygon);
}
