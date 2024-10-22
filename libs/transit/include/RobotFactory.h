#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Robot.h"
#include "RobotObserver.h"

/**
 *@brief Robot Factory to produce Robots class.
 **/
class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief RobotFactories are created with a robot observer
   * @param observer RobotObserver object to subscribe to 
   * the robots being produced
   */
  RobotFactory(RobotObserver* observer);

  /**
   * @brief Destructor for RobotFactory class.
   **/
  virtual ~RobotFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);

 private:
    RobotObserver* robotObserver;
};

#endif
