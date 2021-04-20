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

StorageContainer::StorageContainer(){
    Address *address = new Address("Lodz","Zielona","23");
    Client *client1 = new Client("Anna","Nowak","98765432109",address);
    Address *address2 = new Address("Lodz","Piotrkowska","123");
    Client *client2 = new Client("Jan","Kowalski","1234567890",address2);
    Bicycle *bicycle = new Bicycle("EL95353",100);
    Moped *moped1 = new Moped("WE11",210,900);
    Moped *moped2 = new Moped("WE11",210,1000);
    Moped *moped3 = new Moped("WE11",210,1100);
    Moped *moped4 = new Moped("WE11",210,2000);
    Moped *moped5 = new Moped("WE11",210,2100);
    Car *car1 = new Car("EL990LN",210,1600,Car::A);
    Car *car2 = new Car("EL990LN",210,1600,Car::B);
    Car *car3 = new Car("EL990LN",210,1600,Car::C);
    Car *car4 = new Car("EL990LN",210,1600,Car::D);
    Car *car5 = new Car("EL990LN",210,1600,Car::E);
    Rent *rent1 = new Rent(1,client1,car1,boost::posix_time::not_a_date_time,car1->getBasePrice());
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
