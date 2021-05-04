#include <iostream>
#include <vector>
#include <boost/date_time.hpp>
#include <repositories/StorageContainer.h>
#include <repositories/RentRepository.h>
#include <repositories/VehicleRepository.h>
#include <repositories/ClientRepository.h>
#include <functors/IdPredicate.h>
#include <boost/uuid/random_generator.hpp>
#include <functors/FirstNamePredicate.h>
#include <functors/LastNamePredicate.h>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "typedefs.h"
using namespace std;
//bool testId1(ClientPtr ptr)
//{
//    return ptr->getPersonalId()=="98765432109";
//}
int main() {
    StorageContainerPtr st = std::make_shared<StorageContainer>();
//    cout<<st->getClientrepository().getClient(1)->getInfo();
//    cout<<st->getVehiclerepository().getVehicle(7)->getInfo()<<endl;
//    cout<<st->getVehiclerepository().getVehicle(1)->getInfo()<<endl;
//    cout<<st->getVehiclerepository().getVehicle(0)->getInfo()<<endl;
//    cout<<st->getVehiclerepository().report();
//    cout<<st->getVehiclerepository().reportVehicle()<<endl;
//    cout<<st->getClientrepository().reportClient()<<endl;
//    cout<<st->getRentrepository().reportRent()<<endl;
//    RentPtr rent2 = new Rent(1,st->getClientrepository().getClient(1),st->getVehiclerepository().getVehicle(7),boost::posix_time::not_a_date_time,st->getVehiclerepository().getVehicle(7)->getBasePrice());
//    st->getRentrepository().addRent(rent2);
//    cout<<st->getVehiclerepository().reportVehicle()<<endl;
//    cout<<st->getClientrepository().reportClient()<<endl;
//    cout<<st->getRentrepository().reportRent()<<endl;
    boost::uuids::random_generator generator;
    GoldPtr gold = std::make_shared<Gold>();
    AddressPtr address = std::make_shared<Address>("Lodz","Zielona","23");
    ClientPtr client1 = std::make_shared<Client>("Anna","Nowak","98765432109",address,gold);
    CarPtr car1 = std::make_shared<Car>("EL990LN",210,1600,Car::A);
    RentPtr rent1 = std::make_shared<Rent>(generator(),client1,car1,boost::posix_time::not_a_date_time,car1->getBasePrice());
    st->getRentrepository().addRent(rent1);
    IdPredicate predicate(rent1->getId());
    bool accept = predicate(rent1);
    FirstNamePredicate predicate2("A");
    LastNamePredicate predicate3("K");
    cout<<st->getRentrepository().findAllNew(predicate)[0]->getRentInfo()<<endl;
    cout<<st->getClientrepository().findAllNew(predicate2)[0]->getClientInfo()<<endl;
    cout<<st->getClientrepository().findAllNew(predicate3)[0]->getClientInfo()<<endl;
return 0;
}
