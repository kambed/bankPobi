//
// Created by student on 18.04.2021.
//

#include <model/Bicycle.h>
#include <model/Moped.h>
#include <model/Car.h>
#include "repositories/StorageContainer.h"
#include "model/Rent.h"
#include "typedefs.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Address.h"
#include <memory>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

StorageContainer::StorageContainer(){
    boost::uuids::random_generator generator;
    GoldPtr gold = std::make_shared<Gold>();
    AddressPtr address = std::make_shared<Address>("Lodz","Zielona","23");
    ClientPtr client1 = std::make_shared<Client>("Anna","Nowak","98765432109",address,gold);
    AddressPtr address2 = std::make_shared<Address>("Lodz","Piotrkowska","123");
    ClientPtr client2 = std::make_shared<Client>("Jan","Kowalski","1234567890",address2,gold);
    BicyclePtr bicycle = std::make_shared<Bicycle>("EL95353",100);
    MopedPtr moped1 = std::make_shared<Moped>("WE11",210,900);
    MopedPtr moped2 = std::make_shared<Moped>("WE11",210,1000);
    MopedPtr moped3 = std::make_shared<Moped>("WE11",210,1100);
    MopedPtr moped4 = std::make_shared<Moped>("WE11",210,2000);
    MopedPtr moped5 = std::make_shared<Moped>("WE11",210,2100);
    CarPtr car1 = std::make_shared<Car>("EL990LN",210,1600,Car::A);
    CarPtr car2 = std::make_shared<Car>("EL990LN",210,1600,Car::B);
    CarPtr car3 = std::make_shared<Car>("EL990LN",210,1600,Car::C);
    CarPtr car4 = std::make_shared<Car>("EL990LN",210,1600,Car::D);
    CarPtr car5 = std::make_shared<Car>("EL990LN",210,1600,Car::E);
    RentPtr rent1 = std::make_shared<Rent>(generator(),client1,car1,boost::posix_time::not_a_date_time,car1->getBasePrice());
//    clientrepository.add(client1);
//    clientrepository.add(client2);
//    vehiclerepository.add(bicycle);
//    vehiclerepository.add(moped1);
//    vehiclerepository.add(moped2);
//    vehiclerepository.add(moped3);
//    vehiclerepository.add(moped4);
//    vehiclerepository.add(moped5);
//    vehiclerepository.add(car1);
//    vehiclerepository.add(car2);
//    vehiclerepository.add(car3);
//    vehiclerepository.add(car4);
//    vehiclerepository.add(car5);
//    rentrepository.add(rent1);
    clientrepository.addClient(client1);
    clientrepository.addClient(client2);
    vehiclerepository.addVehicle(bicycle);
    vehiclerepository.addVehicle(moped1);
    vehiclerepository.addVehicle(moped2);
    vehiclerepository.addVehicle(moped3);
    vehiclerepository.addVehicle(moped4);
    vehiclerepository.addVehicle(moped5);
    vehiclerepository.addVehicle(car1);
    vehiclerepository.addVehicle(car2);
    vehiclerepository.addVehicle(car3);
    vehiclerepository.addVehicle(car4);
    vehiclerepository.addVehicle(car5);
    rentrepository.addRent(rent1);
}

VehicleRepository &StorageContainer::getVehiclerepository() {
    return vehiclerepository;
}

RentRepository &StorageContainer::getRentrepository() {
    return rentrepository;
}

ClientRepository &StorageContainer::getClientrepository() {
    return clientrepository;
}
