#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

#include "ISubject.h"
#include "RobotObserver.h"

class Package;

/**
 * @class Robot
 * @brief Represents a robot in a physical system
 *
 * Robots move using euler integration based on a specified
 * velocity and direction.
 */
class Robot : public IEntity, public ISubject{
 public:
  /**
   * @brief Constructor
   * @param obj JSON object containing the robot's information
   */
  Robot(JsonObject& obj, RobotObserver* obv);

  /**
   * @brief Updates the Package
   * 
   * @param dt difference in time since last update
  */
  void update(double dt);

  /**
   * @brief Receives the passed in package
   *
   * @param Package* Package to be received by the robot
  */
  void receive(Package* p);

  /**
   * @brief Sends a notification to all subscribed observers.
   * @param message The notification to send.
   */
  void Notify(const std::string &message);

  bool requestedDelivery = true;

 protected:
  Package* package = nullptr;
};

#endif  // ROBOT_H
