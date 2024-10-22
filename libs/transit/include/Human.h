#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"
#include "IStrategy.h"
/**
 * @class Human
 * @brief Represents a human in a physical system.
 */
class Human : public IEntity {
 public:
  /**
   * @brief Humans are created by the "add Human" button, with a name
   * @param obj JSON object containing the human's information
   */
  Human(JsonObject& obj);

  /**
   * @brief Destructor for Human
   */
  ~Human();

  /**
   *@brief Updates the position for Human
   *@param dt Delta time
   */
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
