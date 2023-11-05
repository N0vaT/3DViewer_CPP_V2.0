#ifndef MODELS_SETTINGS_H
#define MODELS_SETTINGS_H
#include <iostream>

namespace s21 {

typedef struct Color {
  float red;
  float green;
  float blue;
} Color;

class Settings {
 public:
  Settings() noexcept;
  Settings(const Settings& other) noexcept;
  Settings(Settings&& other) noexcept;
  Settings& operator=(const Settings& other);
  Settings& operator=(Settings&& other);
  ~Settings() = default;

  int getDotType() const noexcept;
  float getDotSize() const noexcept;
  Color getDotColor() const noexcept;
  int getLineType() const noexcept;
  float getLineSize() const noexcept;
  Color getLineColor() const noexcept;
  Color getBackColor() const noexcept;
  int getProjectionType() const noexcept;
  void setDotType(int dotType) noexcept;
  void setDotSize(float dotSize) noexcept;
  void setDotColor(float red, float green, float blue) noexcept;
  void setLineType(int lineType) noexcept;
  void setLineSize(float lineSize) noexcept;
  void setLineColor(float red, float green, float blue) noexcept;
  void setBackColor(float red, float green, float blue) noexcept;
  void setProjectionType(int projectionType) noexcept;

 private:
  /// @brief 0 - means circle, 1 - means square, 2 - none
  int dotType;
  /// @brief Size of point
  float dotSize;
  /// @brief Color of point
  Color dotColor;
  /// @brief 0 - means solid, 1 - means dashed, 2 - none
  int lineType;
  /// @brief Size of line (width)
  float lineSize;
  /// @brief Color of line
  Color lineColor;
  /// @brief Color of background
  Color backColor;
  /// @brief 1 - means parallel projection, 2 - means central projection,
  int projectionType;
};

}  // namespace s21

#endif  // MODELS_SETTINGS_H