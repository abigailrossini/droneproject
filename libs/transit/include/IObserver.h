#ifndef IOBSERVER_H_
#define IOBSERVER_H_

#include <iostream>
#include <list>
#include <string>
#include "ISubject.h"

class SimulationModel;

/**
 * @class IObserver
 * @brief Observer interface to receive notifications
 * from subjects subscribed to.
 */
class IObserver {
 public:
  /**
   * @brief Destructor
   */
  virtual ~IObserver() {}

  /**
   * @brief Receives a message from a subscribed subject
   * and sends it to the web view.
   * @param message_from_subject The received message.
   */
  virtual void Update(const std::string &message_from_subject) = 0;

  /**
   * @brief Links this observer to a simulation model,
   *  giving it access to the model's public variables
   *  and functions.
   * @param model The simulation model to link.
   */
  void linkModel(SimulationModel* model) {
    this->model_ = model;
  }

 protected:
  SimulationModel* model_;
};
#endif
