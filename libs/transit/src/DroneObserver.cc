#include "DroneObserver.h"

#include <string>

#include "SimulationModel.h"

DroneObserver::DroneObserver() {
}

void DroneObserver::Update(const std::string &message_from_subject) {
  model_->addNotification(message_from_subject);
}
