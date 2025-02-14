#ifndef DRONE_H_
#define DRONE_H_
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

#include "ISubject.h"
#include "DroneObserver.h"


class Package;

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/**
 * @class Drone
 * @brief Represents a drone in a physical system. Drones move using euler
 * integration based on a specified velocity and direction.
 */
class Drone : public IEntity, public ISubject {
 public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   * @param obv DroneObserver object to subscribe to the drone
   */
  Drone(JsonObject& obj, DroneObserver* obv);

  /**
   * @brief Destructor
   */
  ~Drone();


  /**
   * @brief Gets the next delivery in the scheduler
   */
  void getNextDelivery();

  /**
   * @brief Updates the drone's position
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief Removing the copy constructor operator
   * so that drones cannot be copied.
   */
  Drone(const Drone& drone) = delete;

  /**
   * @brief Removing the assignment operator
   * so that drones cannot be copied.
   */
  Drone& operator=(const Drone& drone) = delete;

  /**
   * @brief Sends a notification to all subscribed observers.
   * @param message The notification to send.
   */
  void Notify(const std::string &message);

 private:
  bool available = false;
  bool pickedUp = false;
  Package* package = nullptr;
  IStrategy* toPackage = nullptr;
  IStrategy* toFinalDestination = nullptr;
};

#endif
