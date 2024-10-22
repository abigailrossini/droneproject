#define _USE_MATH_DEFINES
#include "RechargeStation.h"
#include "BatteryDecorator.h"
#include <cmath>

RechargeStation::RechargeStation(JsonObject& obj, RechargeStationObserver* obv)
                        : IEntity(obj), ISubject(obv) {
    this->numDocked = 0;
    this->rechargeRate = 5.0;
}

RechargeStation::~RechargeStation() {}

void RechargeStation::linkModel(SimulationModel* model) {
    this->model = model;
    this->model->addRechargeStation(this);
}

void RechargeStation::update(double dt) {
    for (BatteryDecorator* drone : this->dockedDrones) {
        drone->setCharge(std::min(drone->getCharge() +
                                        this->rechargeRate * dt, 100.0));
        if (drone->getCharge() == 100.0)
            this->undock(drone);
    }
}

bool RechargeStation::dock(BatteryDecorator* drone) {
    if (this->numDocked >= this->maxDocked)
        return false;
    this->dockedDrones.push_back(drone);
    this->numDocked++;
    Notify("Charging " + drone->getName());
    return true;
}

bool RechargeStation::undock(BatteryDecorator* drone) {
    std::vector<BatteryDecorator*>::iterator droneIt;
    for (droneIt = this->dockedDrones.begin();
            droneIt < dockedDrones.end(); droneIt++) {
        if (drone == *droneIt) {
            this->dockedDrones.erase(droneIt);
            this->numDocked--;
            drone->undock(this);
            Notify("Finsihed charging " + drone->getName());
            return true;
        }
    }
    return false;
}

void RechargeStation::Notify(const std::string &message) {
  std::string fullMessage = this->getName() + ": " + message;
  std::list<IObserver*>::iterator iterator = list_observer_.begin();
  while (iterator != list_observer_.end()) {
    (*iterator)->Update(fullMessage);
    ++iterator;
  }
}
