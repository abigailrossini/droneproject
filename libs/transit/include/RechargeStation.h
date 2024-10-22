#ifndef RECHARGE_STATION_H_
#define RECHARGE_STATION_H_

#include "IEntity.h"
#include "IObserver.h"
#include "RechargeStationObserver.h"

class BatteryDecorator;

/**
 * @class RechargeStation
 * @brief Represents a recharge station in a physical system. Recharge stations
 * can simultaneously charge up to 5 docked drones. 
 */
class RechargeStation : public IEntity, public ISubject {
 public:
  /**
   * @brief RechargeStation are created with a name
   * @param obj JSON object containing the station's information
   * @param obv Recharge Station Observer object to subscribe to the recharge station
   */
  RechargeStation(JsonObject& obj, RechargeStationObserver* obv);

  /**
   * @brief Destructor
   */
  ~RechargeStation();

  /**
   * @brief Links this entity to a simulation model,
   *  giving it access to the model's public variables
   *  and functions. Also adds itself to the model's list
   *  of recharge stations.
   * @param model The simulation model to link.
   */
  void linkModel(SimulationModel* model);

  /**
   * @brief Updates the battery charge of docked drones.
   * @param dt The time step of the update.
   */
  void update(double dt);

  /**
  * @brief Docks a drone at the recharge station.
  * @param drone The desired drock to dock.
  * @return Bool for if the dock was successful.
  */
  bool dock(BatteryDecorator* drone);

  /**
  * @brief Undocks a drone at the recharge station.
  * @param drone The desired drock to undock.
  * @return Bool for if the undock was successful.
  */
  bool undock(BatteryDecorator* drone);

  /**
   * @brief Sends a notification to all subscribed observers.
   * @param message The notification to send.
   */
  void Notify(const std::string &message);

 private:
  double rechargeRate;
  std::vector<BatteryDecorator*> dockedDrones;
  int maxDocked = 5;
  int numDocked;
};

#endif
