#ifndef CARRENTAL_LOGICCONTAINER_H
#define CARRENTAL_LOGICCONTAINER_H


#include <typedefs.h>

class LogicContainer {
private:
    ClientManagerPtr clientManager;
    VehicleManagerPtr vehicleManager;
    RentManagerPtr rentManager;
public:
    ///CONSTRUCTOR

    LogicContainer();
    /// GETTERS

    /// \return
    ClientManagerPtr &getClientManager();

    /// \return
    const VehicleManagerPtr &getVehicleManager() const;

    /// \return
    const RentManagerPtr &getRentManager() const;
};


#endif //CARRENTAL_LOGICCONTAINER_H
