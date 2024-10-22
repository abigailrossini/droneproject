#include "RechargeStationObserver.h"

#include <string>

#include "SimulationModel.h"


RechargeStationObserver::RechargeStationObserver() {
}

void RechargeStationObserver::Update(const std::string &message_from_subject) {
  model_->addNotification(message_from_subject);
}
