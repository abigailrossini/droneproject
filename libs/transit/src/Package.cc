#include "Package.h"
#include "PackageObserver.h"
#include "Robot.h"
#include "ISubject.h"

Package::Package(JsonObject &obj, PackageObserver* obv)
            : IEntity(obj), ISubject(obv) {
}

Vector3 Package::getDestination() const {
  return destination;
}

std::string Package::getStrategyName() const {
  return strategyName;
}

void Package::setStrategyName(std::string strategyName_) {
  strategyName = strategyName_;
}

void Package::update(double dt) {
}

void Package::initDelivery(Robot* owner) {
  this->owner = owner;
  owner->requestedDelivery = false;
  requiresDelivery = false;
  destination = owner->getPosition();
}

void Package::handOff() {
  if (owner) {
    owner->receive(this);
  }
  Notify("Delivered to " + owner->getName());
}

void Package::Notify(const std::string &message) {
  std::string fullMessage = this->getName() + ": " + message;
  std::list<IObserver*>::iterator iterator = list_observer_.begin();
  while (iterator != list_observer_.end()) {
    (*iterator)->Update(fullMessage);
    ++iterator;
  }
}
