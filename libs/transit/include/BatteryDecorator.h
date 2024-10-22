#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "IDroneDecorator.h"
#include "IStrategy.h"
#include "SimulationModel.h"
#include "DroneObserver.h"
#include "BeelineStrategy.h"

class RechargeStation;

/**
 * @class BatteryDecorator
 * @brief Represents a drone with a battery. The battery is constantly discharging
 * and can be recharged by docking at a recharging station.
 */
class BatteryDecorator : public IDroneDecorator {
 public:
        /**
        * @brief Drones are created with a name
        * @param obj JSON object containing the drone's information
        * @param obv DroneObserver object that will subscribe to the drone
        */
        BatteryDecorator(JsonObject& obj, DroneObserver* obv);

        /**
        * @brief Destructor
        */
        virtual ~BatteryDecorator();

        /**
        * @brief Sets closestRechargeStation to closest 
        * recharge station and rechargeStationStrategy to a beeline
        * strategy to the closest station.
        */
        void setRechargeStrategy();

        /**
        * @brief Gets the next delivery in the scheduler
        */
        void getNextDelivery();

        /**
        * @brief Updates the drone's position based on battery.
        * @param dt Delta time
        */
        void update(double dt);

        /**
        * @brief Gets the charge of the battery.
        * @return The charge of the battery.
        */
        double getCharge();

        /**
        * @brief Sets the charge of the battery.
        * @param charge The desired charge of the battery.
        */
        void setCharge(double charge);

        /**
        * @brief Docks the drone at a recharge station.
        * @param station The desired station to dock at.
        * @return Bool for if the dock was successful.
        */
        bool dock(RechargeStation* station);

        /**
        * @brief Undocks the drone at a recharge station.
        * @param station The desired station to undock at.
        * @return Bool for if the undock was successful.
        */
        bool undock(RechargeStation* station);

 private:
        double charge;
        double dischargeRate;
        RechargeStation* closestRechargeStation;
        IStrategy* rechargeStationStrategy;
        bool docked;
};

#endif
