#ifndef MODELS_OBJECT_READER_H
#define MODELS_OBJECT_READER_H

#include <fstream>
#include <iostream>  // TODO: remove

#include "Object.h"

namespace s21 {

class ObjectReader {
 public:
  static Object readObject(const std::string& filename);

 private:
  static void parseLine(Object& object, const std::string& line);
  static void readVertex(Object& object, const std::string& line);
  static void readPolygon(Object& object, const std::string& line);
  static void skipSpace(std::string::const_iterator& iter,
                        const std::string::const_iterator& end);
  static std::string readDouble(std::string::const_iterator& iter,
                                const std::string::const_iterator& end);
};

}  // namespace s21

#endif  // MODELS_OBJECT_READER_H
