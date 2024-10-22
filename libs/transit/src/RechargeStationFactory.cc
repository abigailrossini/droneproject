#include "RechargeStationFactory.h"

RechargeStationFactory::RechargeStationFactory(
                                  RechargeStationObserver* observer) {
  rechargeStationObserver = observer;
}

IEntity* RechargeStationFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("recharge station") == 0) {
    std::cout << "Recharge Station Created" << std::endl;
    return new RechargeStation(entity, rechargeStationObserver);
  }
  return nullptr;
}
