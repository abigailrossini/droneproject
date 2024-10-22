#include "BatteryDecorator.h"
#include "RechargeStation.h"

BatteryDecorator::BatteryDecorator(JsonObject& obj, DroneObserver* obv)
                    : IDroneDecorator(obj, obv) {
    this->charge = 100.0;
    this->dischargeRate = 0.2;
    this->rechargeStationStrategy = nullptr;
    this->closestRechargeStation = nullptr;
    this->docked = false;
}

BatteryDecorator::~BatteryDecorator() {
    if (this->rechargeStationStrategy) delete this->rechargeStationStrategy;
}

void BatteryDecorator::setRechargeStrategy() {
    // Find closest recharge station
    RechargeStation* closest = nullptr;
    double closestDistance = std::numeric_limits<double>::infinity();
    for (RechargeStation* rechargeStation
            : model->getRechargeStations()) {
        double distance = (rechargeStation->getPosition()
                            - this->drone->getPosition()).magnitude();
        if (distance < closestDistance) {
            closest = rechargeStation;
            closestDistance = distance;
        }
    }
    // There is a closest recharge station,
    // so head to it with beeline strategy
    if (closest) {
        this->rechargeStationStrategy =
            new BeelineStrategy(this->getPosition(), closest->getPosition());
        this->closestRechargeStation = closest;
    }
}

void BatteryDecorator::getNextDelivery() {
    this->drone->getNextDelivery();
}

void BatteryDecorator::update(double dt) {
    if (this->docked)
        return;

    if (this->charge <= 0.0) {
        Notify("Battery is dead");
        this->charge = 0.0;
        return;
    } else if (this->charge < 20 && !this->rechargeStationStrategy) {
        this->setRechargeStrategy();
        Notify("Heading to closest recharge station");
    } else if (this->charge < 20 && this->rechargeStationStrategy) {
        // Check if strategy is complete and set rechargeStationStrategy to null
        if (this->rechargeStationStrategy->isCompleted()) {
            if (this->dock(this->closestRechargeStation)) {
                delete this->rechargeStationStrategy;
                this->rechargeStationStrategy = nullptr;
            }
        } else {
            // Use battery stategy to get to recharge station
            this->rechargeStationStrategy->move(this->drone, dt);
            this->setPosition(this->drone->getPosition());
            this->setDirection(this->drone->getDirection());
        }
    } else {
        // Move drone regularly
        this->drone->update(dt);
        this->setPosition(this->drone->getPosition());
        this->setDirection(this->drone->getDirection());
    }

    double previousCharge = this->charge;
    this->setCharge(this->charge - (this->dischargeRate * dt));
    double currentCharge = this->charge;
    if (fmod(currentCharge, 20.0) < previousCharge - currentCharge) {
        int rounded = static_cast<int>(std::round(currentCharge));
        Notify("Battery is at " + std::to_string(rounded) + "%");
    }
}

void BatteryDecorator::setCharge(double charge) {
    this->charge = charge;
}

double BatteryDecorator::getCharge() {
    return this->charge;
}

bool BatteryDecorator::dock(RechargeStation* station) {
    this->docked = station->dock(this);
    return this->docked;
}

bool BatteryDecorator::undock(RechargeStation* station) {
    this->docked = false;
    Notify("Battery is at 100%");
    return true;
}
