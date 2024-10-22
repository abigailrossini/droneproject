#include "BatteryFactory.h"

BatteryFactory::BatteryFactory(DroneObserver* observer) {
  batteryObserver = observer;
}

IEntity* BatteryFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("battery") == 0) {
    std::cout << "Battery Created" << std::endl;
    IEntity* battery = new BatteryDecorator(entity, batteryObserver);
    return battery;
  }
  return nullptr;
}
