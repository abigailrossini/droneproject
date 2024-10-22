#ifndef ISUBJECT_H_
#define ISUBJECT_H_
#include <iostream>
#include <list>
#include <string>

#include "IObserver.h"

class IObserver;

/**
 * @class ISubject
 * @brief Subject interface to send notifications
 * to subscribed observers.
 */
class ISubject {
 public:
  /**
   * @brief A subject is created with an initial observer subscribed to it.
   * @param observer The initial observer to subscribe to the subject.
   */
  ISubject(IObserver* observer);

  /**
   * @brief Destructor
   */
  ~ISubject();

  /**
   * @brief Adds an observer to list of subscribed observers.
   * @param observer The observer to subscribe to the subject.
   */
  virtual void Attach(IObserver* observer);

  /**
   * @brief Removes an observer to list of subscribed observers.
   * @param observer The observer to unsubscribe from the subject.
   */
  virtual void Detach(IObserver* observer);

  /**
   * @brief Sends a notification to all subscribed observers.
   * @param message The notification to send.
   */
  virtual void Notify(const std::string &message);

 protected:
    std::list<IObserver*> list_observer_;
};
#endif

