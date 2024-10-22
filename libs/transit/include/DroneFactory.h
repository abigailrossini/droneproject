#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Drone.h"
#include "DroneObserver.h"
/**
 *@brief Drone Factory to produce Drones class.
 **/
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief DroneFactories are created with a drone observer
   * @param observer DroneObserver object to subscribe to 
   * the drones being produced
   */
  DroneFactory(DroneObserver* observer);

  /**
   * @brief Destructor for DroneFactory class.
   **/
  virtual ~DroneFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);

 private:
    DroneObserver* droneObserver;
};

#endif
