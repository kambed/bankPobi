#include <iostream>
#include <string>
#include "model/clients/Client.h"
#include "model/Address.h"
#include "model/vehicles/Bicycle.h"
#include "typedefs.h"
#include "repositories/StorageContainer.h"
#include <vector>
#include <memory>
#include "model/clients/Default.h"
#include "model/managers/LogicContainer.h"
#include "model/managers/ClientManager.h"
#include "model/managers/VehicleManager.h"
#include "model/managers/RentManager.h"
#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include "functors/IdPredicate.h"
#include "functors/FirstNamePredicate.h"
#include "functors/LastNamePredicate.h"


using namespace std;

bool rentPredicate(RentPtr rent) {
    return rent->getClient()->getFirstName() == "Jan";
}

int main() {
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    LogicContainerPtr logicContainer = make_shared<LogicContainer>();

    ClientManagerPtr clientManager = logicContainer->getClientManager();
    VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
    RentManagerPtr rentManager = logicContainer->getRentManager();

    AddressPtr address = make_shared<Address>("Lodz", "Politechniki", "38");
    ClientTypePtr defaultType = make_shared<Default>();

    ClientPtr client1 = clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
    ClientPtr client2 = clientManager->registerClient("Anna", "Kowalska", "12345678901", address, defaultType);
    VehiclePtr vehicle1 = vehicleManager->registerBicycle("AB1234",100);
    VehiclePtr vehicle2 = vehicleManager->registerBicycle("CD5678",200);
    RentPtr rent1 = rentManager->rentVehicle(client1,vehicle1,now - boost::posix_time::hours(20));
    RentPtr rent2 = rentManager->rentVehicle(client2,vehicle2,now - boost::posix_time::hours(25));

    cout << "Aktualne wypozyczenia: " << endl;
    for(int i=0;i<rentManager->findAllRents().size();i++){
        cout << rentManager->findAllRents()[i]->getRentInfo()<<endl;
    }

    rentManager->returnVehicle(vehicleManager->getVehicle("CD5678"),now);

    IdPredicate predicate(rent1->getId());

    cout << endl << "Klient o zadanym ID:" << endl;
    cout << endl << rentManager->findRents(predicate)[0]->getRentInfo() << endl;

    FirstNamePredicate predicate2("J");
    vector<ClientPtr> j = clientManager->findClients(predicate2);

    LastNamePredicate predicate3("K");
    vector<ClientPtr> k = clientManager->findClients(predicate3);

    cout << endl << "Klienci na z imieniem na J: " << endl;
    for(int i=0;i<j.size();i++)
        cout << j[i]->getClientInfo() << endl;

    cout << endl << "Klienci na z nazwiskiem na K: " << endl;
    for(int i=0;i<k.size();i++)
        cout << k[0]->getClientInfo() << endl;

    return 0;
}
