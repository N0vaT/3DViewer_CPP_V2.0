#include "tests.h"

using namespace s21;

TEST(Model, Object) {
  Object object;
  ASSERT_EQ(object.getVerticesNumber(), 0);
  ASSERT_EQ(object.getPolygonsNumber(), 0);

  object.addVertex(Vertex(1, 2, 3));
  object.addVertex(Vertex(3, 2, 1));
  object.addVertex(Vertex(2, 3, 1));
  object.addPolygon(std::vector({0, 1, 2}));

  ASSERT_EQ(object.getVerticesNumber(), 3);
  ASSERT_EQ(object.getPolygonsNumber(), 1);

  const Vertex& v = object.getVertex(1);
  ASSERT_EQ(v.x, 3);
  ASSERT_EQ(v.y, 2);
  ASSERT_EQ(v.z, 1);

  const std::vector<int> p = object.getPolygon(0);
  ASSERT_EQ(p.size(), 3);
  ASSERT_EQ(p.at(0), 0);
  ASSERT_EQ(p.at(1), 1);
  ASSERT_EQ(p.at(2), 2);

  ASSERT_ANY_THROW(object.getPolygon(243));
  ASSERT_ANY_THROW(object.getPolygon(-243));
  ASSERT_ANY_THROW(object.getVertex(243));
  ASSERT_ANY_THROW(object.getVertex(-243));
}

TEST(Model, ObjectReader) {
  Object object = ObjectReader::readObject("tests/test_files/cube.obj1");
  ASSERT_EQ(object.getVerticesNumber(), 8);
  ASSERT_EQ(object.getPolygonsNumber(), 10);

  ASSERT_NEAR(object.getVertex(0).x, 0.0, 0.000001);
  ASSERT_NEAR(object.getVertex(0).y, 0.0, 0.000001);
  ASSERT_NEAR(object.getVertex(0).z, 0.0, 0.000001);

  ASSERT_NEAR(object.getVertex(6).x, 2.0, 0.000001);
  ASSERT_NEAR(object.getVertex(6).y, 2.0, 0.000001);
  ASSERT_NEAR(object.getVertex(6).z, 0.0, 0.000001);

  ASSERT_EQ(object.getPolygon(8).size(), 3);
  ASSERT_EQ(object.getPolygon(8).at(0), 1);
  ASSERT_EQ(object.getPolygon(8).at(1), 5);
  ASSERT_EQ(object.getPolygon(8).at(2), 6);

  ASSERT_NEAR(object.getMaxVertex().x, 2, 0.000001);
  ASSERT_NEAR(object.getMaxVertex().y, 2, 0.000001);
  ASSERT_NEAR(object.getMaxVertex().z, 2, 0.000001);

  ASSERT_NEAR(object.getMinVertex().x, 0, 0.000001);
  ASSERT_NEAR(object.getMinVertex().y, 0, 0.000001);
  ASSERT_NEAR(object.getMinVertex().z, 0, 0.000001);

  ASSERT_NEAR(object.getMidVertex().x, 1, 0.000001);
  ASSERT_NEAR(object.getMidVertex().y, 1, 0.000001);
  ASSERT_NEAR(object.getMidVertex().z, 1, 0.000001);
}

TEST(Model, ObjectTransformerMoveObject) {
  Object object = ObjectReader::readObject("tests/test_files/cube.obj1");
  ASSERT_EQ(object.getVerticesNumber(), 8);
  ASSERT_EQ(object.getPolygonsNumber(), 10);

  ObjectTransformer::moveObject(&object, 1, 1, 1);
  ASSERT_NEAR(object.getVertex(0).x, 1.0, 0.000001);
  ASSERT_NEAR(object.getVertex(0).y, 1.0, 0.000001);
  ASSERT_NEAR(object.getVertex(0).z, 1.0, 0.000001);

  ASSERT_NEAR(object.getVertex(6).x, 3.0, 0.000001);
  ASSERT_NEAR(object.getVertex(6).y, 3.0, 0.000001);
  ASSERT_NEAR(object.getVertex(6).z, 1.0, 0.000001);
}

TEST(Model, ObjectTransformerScaleObject) {
  Object object = ObjectReader::readObject("tests/test_files/cube.obj1");
  ASSERT_EQ(object.getVerticesNumber(), 8);
  ASSERT_EQ(object.getPolygonsNumber(), 10);

  ObjectTransformer::scaleObject(&object, 10, 10, 10);
  ASSERT_NEAR(object.getVertex(0).x, 0.0, 0.000001);
  ASSERT_NEAR(object.getVertex(0).y, 0.0, 0.000001);
  ASSERT_NEAR(object.getVertex(0).z, 0.0, 0.000001);

  ASSERT_NEAR(object.getVertex(6).x, 20.0, 0.000001);
  ASSERT_NEAR(object.getVertex(6).y, 20.0, 0.000001);
  ASSERT_NEAR(object.getVertex(6).z, 0.0, 0.000001);
}

TEST(Model, ObjectTransformerRotateObject) {
  Object object = ObjectReader::readObject("tests/test_files/cube.obj1");
  ASSERT_EQ(object.getVerticesNumber(), 8);
  ASSERT_EQ(object.getPolygonsNumber(), 10);

  ObjectTransformer::rotateObjectX(&object, 3);
  ObjectTransformer::rotateObjectY(&object, 3);
  ObjectTransformer::rotateObjectZ(&object, 3);

  ASSERT_NEAR(object.getVertex(0).x, 0.0, 0.000001);
  ASSERT_NEAR(object.getVertex(0).y, 0.0, 0.000001);
  ASSERT_NEAR(object.getVertex(0).z, 0.0, 0.000001);

  ASSERT_NEAR(object.getVertex(6).x, 1.720185, 0.000001);
  ASSERT_NEAR(object.getVertex(6).y, 2.245206, 0.000001);
  ASSERT_NEAR(object.getVertex(6).z, -0.002825, 0.000001);
}

TEST(Model, SkullRead) {
  Object object = ObjectReader::readObject("tests/test_files/skull.obj1");
}
