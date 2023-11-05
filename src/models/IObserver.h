#ifndef MODELS_IOBSERVER_H
#define MODELS_IOBSERVER_H

namespace s21 {

class IObserver {
 public:
  virtual void updateSettings() = 0;
};

}  // namespace s21

#endif  // MODELS_IOBSERVER_H