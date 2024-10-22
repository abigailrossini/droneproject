#ifndef PACKAGE_OBSERVER_H_
#define PACKAGE_OBSERVER_H_

#include "IObserver.h"

/**
 * @class PackageObserver
 * @brief Observer that receives notifications
 * from all packages in the simulation.
 */
class PackageObserver : public IObserver{
 public:
    /**
    * @brief Constructor
    */
    PackageObserver();

    /**
    * @brief Receives a message from a subscribed subject
    * and sends it to the web view.
    * @param message_from_subject The received message.
    */
    void Update(const std::string &message_from_subject);
};

#endif
