#include <iostream>
#include <string>
#include <model/Clients/Client.h>
#include <model/Address.h>
#include <model/Vehicles/Bicycle.h>
#include "typedefs.h"
#include "repositories/StorageContainer.h"
#include <vector>
#include <model/Clients/Gold.h>

using namespace std;

int main() {

    StorageContainerPtr storage = make_shared<StorageContainer>();
    cout << "Przed: " << endl << endl;
    cout << storage->getClientsRepo().reportClients() << endl;
    cout << storage->getVehiclesRepo().reportVehicles() << endl;
    cout << storage->getRentsRepo().reportRents() << endl;

    AddressPtr address = make_shared<Address>("Lodz", "Zielona", "5");
    ClientTypePtr gold = make_shared<Gold>();
    ClientPtr client = make_shared<Client>("Ala", "Kot", "11111111111", address, gold);
    storage->getClientsRepo().addClient(client);
    VehiclePtr bicycle = make_shared<Bicycle>("AB0101", 100);
    storage->getVehiclesRepo().addVehicle(bicycle);
    RentPtr rent = make_shared<Rent>(2, client, bicycle, boost::posix_time::second_clock::local_time());
    storage->getRentsRepo().addRent(rent);

    cout << "Po: " << endl << endl;
    cout << storage->getClientsRepo().reportClients() << endl;
    cout << storage->getVehiclesRepo().reportVehicles() << endl;
    cout << storage->getRentsRepo().reportRents() << endl;

//    vector<ClientPtr> findAll = storage->getClientsRepo().findAll();

//    cout << endl << "FindAllTest:" << endl;
//    for(int i=0;i<findAll.size();i++)
//        cout << findAll[i]->getClientInfo() << endl;

    return 0;
}
