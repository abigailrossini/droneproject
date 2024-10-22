#include "IDroneDecorator.h"

IDroneDecorator::IDroneDecorator(JsonObject& obj, DroneObserver* obv)
                    : Drone(obj, obv) {
    this->drone = new Drone(obj, obv);
}

IDroneDecorator::~IDroneDecorator() {
    if (this->drone) delete this->drone;
}

void IDroneDecorator::linkModel(SimulationModel* model) {
    this->model = model;
    this->drone->linkModel(model);
}
