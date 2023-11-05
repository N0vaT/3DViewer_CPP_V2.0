#ifndef MODELS_ISUBJECT_H
#define MODELS_ISUBJECT_H

#include "IObserver.h"

namespace s21 {
class ISubject {
 public:
  virtual void attach(s21::IObserver *observer) = 0;
  virtual void detach(s21::IObserver *observer) = 0;
  virtual void notify() = 0;
};
}  // namespace s21

#endif  // MODELS_ISUBJECT_H