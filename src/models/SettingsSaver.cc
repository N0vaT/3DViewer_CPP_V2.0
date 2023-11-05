#include "SettingsSaver.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

namespace s21 {
    SettingsSaver::SettingsSaver(const std::string& settingsPath, s21::Settings *settings) noexcept {
      this->settingsPath = settingsPath;
      this->settings = settings;
    }

    SettingsSaver* SettingsSaver::settingsSaver = nullptr;

    SettingsSaver *SettingsSaver::getInstance(const std::string& settingsPath, s21::Settings *settings){
       if (!settingsSaver) {
         settingsSaver = new SettingsSaver(settingsPath, settings);
       }
       return settingsSaver;
    }

    void SettingsSaver::readSettings(){
      QFile load_settings(QString::fromStdString(settingsPath));

      if (load_settings.open(QIODevice::ReadOnly)) {
        QJsonDocument loaded_settings =
            QJsonDocument::fromJson(load_settings.readAll());
        QJsonObject jsonSettings = loaded_settings.object();

        settings->setLineType(jsonSettings.value("lineType").toInt());
        settings->setLineSize(jsonSettings.value("lineSize").toDouble());
        settings->setDotType(jsonSettings.value("dotType").toInt());
        settings->setDotSize(jsonSettings.value("dotSize").toDouble());
        settings->setProjectionType(jsonSettings.value("projectionType").toInt());
        settings->setBackColor(jsonSettings.value("bg_color_r").toDouble(), jsonSettings.value("bg_color_g").toDouble(), jsonSettings.value("bg_color_b").toDouble());
        settings->setDotColor(jsonSettings.value("dot_color_r").toDouble(), jsonSettings.value("dot_color_g").toDouble(), jsonSettings.value("dot_color_b").toDouble());
        settings->setLineColor(jsonSettings.value("line_color_r").toDouble(), jsonSettings.value("line_color_g").toDouble(), jsonSettings.value("line_color_b").toDouble());
        load_settings.close();
      }
    }

    void SettingsSaver::writeSettings(){
      QJsonObject jsonSettings;
      jsonSettings["lineType"] = settings->getLineType();
      jsonSettings["lineSize"] = settings->getLineSize();
      jsonSettings["dotType"] = settings->getDotType();
      jsonSettings["dotSize"] = settings->getDotSize();
      jsonSettings["projectionType"] = settings->getProjectionType();
      jsonSettings["bg_color_r"] = settings->getBackColor().red;
      jsonSettings["bg_color_g"] = settings->getBackColor().green;
      jsonSettings["bg_color_b"] = settings->getBackColor().blue;
      jsonSettings["line_color_r"] = settings->getLineColor().red;
      jsonSettings["line_color_g"] = settings->getLineColor().green;
      jsonSettings["line_color_b"] = settings->getLineColor().blue;
      jsonSettings["dot_color_r"] = settings->getDotColor().red;
      jsonSettings["dot_color_g"] = settings->getDotColor().green;
      jsonSettings["dot_color_b"] = settings->getDotColor().blue;
      QJsonDocument doc(jsonSettings);
      QFile file_settings(QString::fromStdString(settingsPath));
      if (file_settings.open(QIODevice::WriteOnly)) {
        file_settings.write(doc.toJson());
        file_settings.close();
      }
    }

} // namespace s21
