//
// Created by student on 16.04.2021.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H
#include <memory>
#include <model/Moped.h>
#include <model/Bicycle.h>
#include <model/Car.h>

class Client;
class Address;
class Rent;
class Vehicle;
class VehicleRepository;
class RentRepository;
class ClientRepository;
class StorageContainer;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Moped> MopedPtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<Car> CarPtr;

typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;
typedef std::shared_ptr<RentRepository> RentRepositoryPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;

typedef std::shared_ptr<StorageContainer> StorageContainerPtr;

typedef bool (*RentPredicate)(RentPtr);
typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);

#endif //CARRENTAL_TYPEDEFS_H
