#ifndef DRONE_OBSERVER_H_
#define DRONE_OBSERVER_H_

#include "IObserver.h"

/**
 * @class DroneObserver
 * @brief Observer that receives notifications
 * from all drones in the simulation.
 */
class DroneObserver : public IObserver{
 public:
    /**
    * @brief Constructor
    */
    DroneObserver();

    /**
    * @brief Receives a message from a subscribed subject
    * and sends it to the web view.
    * @param message_from_subject The received message.
    */
    void Update(const std::string &message_from_subject);
};

#endif
