#include "ISubject.h"
// #include "IObserver.h"
#include <list>

ISubject::ISubject(IObserver* observer) {
  Attach(observer);
}

ISubject::~ISubject() {
}

void ISubject::Attach(IObserver* observer) {
  if (observer != nullptr) {
    list_observer_.push_back(observer);
  }
}
void ISubject::Detach(IObserver* observer) {
  list_observer_.remove(observer);
}
void ISubject::Notify(const std::string &message) {
  std::list<IObserver*>::iterator iterator = list_observer_.begin();
  while (iterator != list_observer_.end()) {
    (*iterator)->Update(message);
    ++iterator;
  }
}
