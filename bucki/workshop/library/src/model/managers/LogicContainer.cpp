#include "model/managers/LogicContainer.h"
#include "model/managers/ClientManager.h"
#include "model/managers/VehicleManager.h"
#include "model/managers/RentManager.h"
#include "typedefs.h"

ClientManagerPtr &LogicContainer::getClientManager(){
    return clientManager;
}

LogicContainer::LogicContainer()  {
    clientManager = std::make_shared<ClientManager>();
    vehicleManager = std::make_shared<VehicleManager>();
    rentManager = std::make_shared<RentManager>();
}

const VehicleManagerPtr &LogicContainer::getVehicleManager() const {
    return vehicleManager;
}

const RentManagerPtr &LogicContainer::getRentManager() const {
    return rentManager;
}
