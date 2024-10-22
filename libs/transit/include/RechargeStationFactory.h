#ifndef RECHARGE_STATION_FACTORY_H_
#define RECHARGE_STATION_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "RechargeStation.h"
#include "RechargeStationObserver.h"

/**
 *@brief Recharge Station Factory to produce Recharge Station class.
 **/
class RechargeStationFactory : public IEntityFactory {
 public:
  /**
   * @brief RechargeStationFactories are created with a recharge station observer
   * @param observer RechargeStationObserver object to subscribe to 
   * the recharge stations being produced
   */
  RechargeStationFactory(RechargeStationObserver* observer);

  /**
   * @brief Destructor for RechargeStationFactory class.
   **/
  ~RechargeStationFactory() {}

  /**
   * @brief Creates a new Recharge station via the JSON object
   * @param entity JsonObject to be used
   * @return a pointer to the Recharge Station, Nullpointer if failed
   **/
  IEntity* CreateEntity(JsonObject& entity);

 private:
  RechargeStationObserver* rechargeStationObserver;
};

#endif
