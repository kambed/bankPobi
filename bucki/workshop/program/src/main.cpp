#include <iostream>
#include <string>
#include <model/Client.h>
#include <model/Address.h>
#include <model/Bicycle.h>
#include "typedefs.h"
#include "repositories/StorageContainer.h"
#include <vector>

using namespace std;

int main() {

    StorageContainerPtr storage = new StorageContainer();
    cout << "Przed: " << endl << endl;
    cout << storage->getClientsRepo().reportClients() << endl;
    cout << storage->getVehiclesRepo().reportVehicles() << endl;
    cout << storage->getRentsRepo().reportRents() << endl;

    AddressPtr address = new Address("Lodz","Zielona","5");
    ClientPtr client = new Client("Ala","Kot","11111111111",address);
    storage->getClientsRepo().addClient(client);
    VehiclePtr bicycle = new Bicycle("AB0101",100);
    storage->getVehiclesRepo().addVehicle(bicycle);
    RentPtr rent = new Rent(2,client,bicycle,boost::posix_time::second_clock::local_time());
    storage->getRentsRepo().addRent(rent);

    cout << "Po: " << endl << endl;
    cout << storage->getClientsRepo().reportClients() << endl;
    cout << storage->getVehiclesRepo().reportVehicles() << endl;
    cout << storage->getRentsRepo().reportRents() << endl;

    vector<ClientPtr> findAll = storage->getClientsRepo().findAll();

//    cout << endl << "FindAllTest:" << endl;
//    for(int i=0;i<findAll.size();i++)
//        cout << findAll[i]->getClientInfo() << endl;

    return 0;
}
