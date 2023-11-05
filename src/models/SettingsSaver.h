#ifndef MODELS_SETTINGS_SAVER_H
#define MODELS_SETTINGS_SAVER_H

#include "../models/IObserver.h"
#include "../models/Settings.h"

namespace s21 {

class SettingsSaver : public s21::IObserver {
 private:
  static SettingsSaver* settingsSaver;

 protected:
  SettingsSaver(const std::string& settingsPath,
                s21::Settings* settings) noexcept;
  SettingsSaver(const SettingsSaver& other) = delete;
  SettingsSaver& operator=(const SettingsSaver& other) = delete;
  ~SettingsSaver() { delete settingsSaver; }

 public:
  static SettingsSaver* getInstance(const std::string& settingsPath,
                                    s21::Settings* settings);

  void readSettings();
  void writeSettings();

  void updateSettings() override { writeSettings(); }

 private:
  std::string settingsPath;
  s21::Settings* settings;
};

}  // namespace s21

#endif  // MODELS_SETTINGS_SAVER_H
