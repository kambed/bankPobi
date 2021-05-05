#include <iostream>
#include <string>
#include <model/clients/Client.h>
#include <model/Address.h>
#include <model/vehicles/Bicycle.h>
#include "typedefs.h"
#include "repositories/StorageContainer.h"
#include <vector>
#include <model/clients/Gold.h>
#include <memory>
#include <model/clients/Default.h>
#include "model/managers/LogicContainer.h"
#include "model/managers/ClientManager.h"
#include "model/managers/VehicleManager.h"
#include "model/managers/RentManager.h"
#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/ptime.hpp>


using namespace std;

bool rentPredicate(RentPtr rent) {
    return rent->getId() == 1;
}

int main() {
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    LogicContainerPtr logicContainer = make_shared<LogicContainer>();

    ClientManagerPtr clientManager = logicContainer->getClientManager();
    VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
    RentManagerPtr rentManager = logicContainer->getRentManager();

    AddressPtr address = std::make_shared<Address>("Lodz", "Politechniki", "38");
    ClientTypePtr defaultType = std::make_shared<Default>();

    ClientPtr client1 = clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
    ClientPtr client2 = clientManager->registerClient("Anna", "Kowalska", "12345678901", address, defaultType);
    VehiclePtr vehicle1 = vehicleManager->registerBicycle("AB1234",100);
    VehiclePtr vehicle2 = vehicleManager->registerBicycle("CD5678",200);
    rentManager->rentVehicle(1,client1,vehicle1,now - boost::posix_time::hours(20));
    rentManager->rentVehicle(2,client2,vehicle2,now - boost::posix_time::hours(25));

    cout << "Aktualne wypozyczenia: " << endl;
    for(int i=0;i<rentManager->findAllRents().size();i++){
        cout << rentManager->findAllRents()[i]->getRentInfo()<<endl;
    }

    rentManager->returnVehicle(vehicleManager->getVehicle("CD5678"),now);

    cout << endl << rentManager->findRents(rentPredicate)[0]->getRentInfo();

    return 0;
}
