#ifndef ROBOT_OBSERVER_H_
#define ROBOT_OBSERVER_H_
#include "IObserver.h"

/**
 * @class RobotObserver
 * @brief Observer that receives notifications
 * from all robots in the simulation.
 */
class RobotObserver : public IObserver{
 public:
    /**
    * @brief Constructor
    */
    RobotObserver();

    /**
    * @brief Receives a message from a subscribed subject
    * and sends it to the web view.
    * @param message_from_subject The received message.
    */
    void Update(const std::string &message_from_subject);
};

#endif
