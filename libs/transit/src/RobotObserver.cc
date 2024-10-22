#include "RobotObserver.h"
#include <string>
#include "SimulationModel.h"

RobotObserver::RobotObserver() {
}

void RobotObserver::Update(const std::string &message_from_subject) {
  model_->addNotification(message_from_subject);
}
