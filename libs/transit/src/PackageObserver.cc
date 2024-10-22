#include "PackageObserver.h"
#include <string>
#include "SimulationModel.h"

PackageObserver::PackageObserver() {
}

void PackageObserver::Update(const std::string &message_from_subject) {
  model_->addNotification(message_from_subject);
}
