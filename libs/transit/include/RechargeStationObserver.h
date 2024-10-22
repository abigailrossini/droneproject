#ifndef RECHARGE_STATION_OBSERVER_H_
#define RECHARGE_STATION_OBSERVER_H_

#include "IObserver.h"

/**
 * @class RechargeStationObserver
 * @brief Observer that receives notifications
 * from all recharge stations in the simulation.
 */
class RechargeStationObserver : public IObserver {
 public:
    /**
    * @brief Constructor
    */
    RechargeStationObserver();

    /**
    * @brief Receives a message from a subscribed subject
    * and sends it to the web view.
    * @param message_from_subject The received message.
    */
    void Update(const std::string &message_from_subject);
};

#endif
