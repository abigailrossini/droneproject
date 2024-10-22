#include "DroneFactory.h"
DroneFactory::DroneFactory(DroneObserver* observer) {
  droneObserver = observer;
}
IEntity* DroneFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("drone") == 0) {
    std::cout << "Drone Created" << std::endl;
    return new Drone(entity, droneObserver);
  }
  return nullptr;
}
