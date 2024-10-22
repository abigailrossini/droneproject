#ifndef IDRONE_DECORATOR_H_
#define IDRONE_DECORATOR_H_

#include "Drone.h"
#include "DroneObserver.h"
#include "SimulationModel.h"

/**
 * @class IDroneDecorator
 * @brief Represents a drone in a physical system.
 * 
 * A drone decorator has an instance of a drone. Subclasses need to
 * override the `Update` function to implement their own behavior.
 *
 */
class IDroneDecorator : public Drone {
 protected:
        Drone* drone;

 public:
        /**
        * @brief Drones are created with a name
        * @param obj JSON object containing the drone's information
        * @param obv DroneObserver object that will subscribe to the drone
        */
        IDroneDecorator(JsonObject& obj, DroneObserver* obv);

        /**
        * @brief Destructor
        */
        virtual ~IDroneDecorator();

        /**
        * @brief Links this drone to a simulation model,
        * giving it access to the model's public variables
        * and functions. Also links the drone member variable
        * to the model.
        * @param model The simulation model to link.
        */
        virtual void linkModel(SimulationModel* model);

        /**
        * @brief Updates the drone's position
        * @param dt Delta time
        */
        virtual void update(double dt) = 0;
};

#endif
