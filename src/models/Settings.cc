#include "Settings.h"

namespace s21 {
    Settings::Settings() noexcept {
      dotType = 1;
      dotSize = 3;
      lineType = 0;
      lineSize = 3;
      projectionType = 1;
      dotColor = {1, 0, 0};
      lineColor = {0, 1, 0};
      backColor = {0, 0, 0};
    }
    Settings::Settings(const Settings& other) noexcept{
      dotType = other.dotType;
      dotSize = other.dotType;
      dotColor = other.dotColor;
      lineType = other.lineType;
      lineSize = other.dotSize;
      lineColor = other.lineColor;
      backColor = other.backColor;
      projectionType = other.projectionType;
    }
    Settings::Settings(Settings&& other) noexcept{
      dotType = std::move(other.dotType);
      dotSize = std::move(other.dotType);
      dotColor = std::move(other.dotColor);
      lineType = std::move(other.lineType);
      lineSize = std::move(other.dotSize);
      lineColor = std::move(other.lineColor);
      backColor = std::move(other.backColor);
      projectionType = std::move(other.projectionType);
    }
    Settings& Settings::operator=(const Settings& other) {
      if (this != &other) {
        dotType = other.dotType;
        dotSize = other.dotType;
        dotColor = other.dotColor;
        lineType = other.lineType;
        lineSize = other.dotSize;
        lineColor = other.lineColor;
        backColor = other.backColor;
        projectionType = other.projectionType;
      }
      return *this;
    }
    
    Settings& Settings::operator=(Settings&& other) {
      if (this != &other) {
        dotType = std::move(other.dotType);
        dotSize = std::move(other.dotType);
        dotColor = std::move(other.dotColor);
        lineType = std::move(other.lineType);
        lineSize = std::move(other.dotSize);
        lineColor = std::move(other.lineColor);
        backColor = std::move(other.backColor);
        projectionType = std::move(other.projectionType);
      }
      return *this;
    }

    int Settings::getDotType() const noexcept{
      return dotType;
    }
    float Settings::getDotSize() const noexcept{
      return dotSize;
    }
    Color Settings::getDotColor() const noexcept{
      return dotColor;
    }
    int Settings::getLineType() const noexcept{
      return lineType;
    }
    float Settings::getLineSize() const noexcept{
      return lineSize;
    }
    Color Settings::getLineColor() const noexcept{
      return lineColor;
    }
    Color Settings::getBackColor() const noexcept{
      return backColor;
    }
    int Settings::getProjectionType() const noexcept{
      return projectionType;
    }
    void Settings::setDotType(int dotType) noexcept{
      this->dotType = dotType;
    }
    void Settings::setDotSize(float dotSize) noexcept{
      this->dotSize = dotSize;
    }
    void Settings::setDotColor(float red, float green, float blue) noexcept{
      this->dotColor.red = red;
      this->dotColor.green = green;
      this->dotColor.blue = blue;
    }
    void Settings::setLineType(int lineType) noexcept{
      this->lineType = lineType;
    }
    void Settings::setLineSize(float lineSize) noexcept{
      this->lineSize = lineSize;
    }
    void Settings::setLineColor(float red, float green, float blue) noexcept{
      this->lineColor.red = red;
      this->lineColor.green = green;
      this->lineColor.blue = blue;
    }
    void Settings::setBackColor(float red, float green, float blue) noexcept{
      this->backColor.red = red;
      this->backColor.green = green;
      this->backColor.blue = blue;
    }
    void Settings::setProjectionType(int projectionType) noexcept{
      this->projectionType = projectionType;
    }
} // namespace s21