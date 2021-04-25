#ifndef CARRENTAL_LOGICCONTAINER_H
#define CARRENTAL_LOGICCONTAINER_H


#include <typedefs.h>

class LogicContainer {
private:
    ClientManagerPtr clientManager;
    VehicleManagerPtr vehicleManager;
    RentManagerPtr rentManager;
public:
    LogicContainer();

    ClientManagerPtr &getClientManager();

    const VehicleManagerPtr &getVehicleManager() const;

    const RentManagerPtr &getRentManager() const;
};


#endif //CARRENTAL_LOGICCONTAINER_H
