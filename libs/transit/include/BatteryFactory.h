#ifndef BATTERY_FACTORY_H_
#define BATTERY_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "BatteryDecorator.h"
#include "DroneObserver.h"

/**
 *@brief Battery Factory to produce BatteryDecorators class.
 **/
class BatteryFactory : public IEntityFactory {
 public:
  /**
   * @brief BatteryFactories are created with a drone observer
   * @param observer DroneObserver object to subscribe to 
   * the drones being produced
   */
  BatteryFactory(DroneObserver* observer);

  /**
   * @brief Destructor for BatteryFactory class.
   **/
  virtual ~BatteryFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);

 private:
    DroneObserver* batteryObserver;
};

#endif
