#include "Robot.h"
#include "RobotObserver.h"
#include "ISubject.h"
#include "Package.h"
Robot::Robot(JsonObject& obj, RobotObserver* obv)
          : IEntity(obj), ISubject(obv) {}

void Robot::update(double dt) {}

void Robot::receive(Package* p) {
  Notify("Recieved " + p->getName());
  package = p;
}
void Robot::Notify(const std::string &message) {
  std::string fullMessage = this->getName() + ": " + message;
  std::list<IObserver*>::iterator iterator = list_observer_.begin();
  while (iterator != list_observer_.end()) {
    (*iterator)->Update(fullMessage);
    ++iterator;
  }
}
