//
// Created by student on 16.04.2021.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H
#include <memory>
#include <model/Moped.h>
#include <model/Bicycle.h>
#include <model/Car.h>
#include <model/ClientType.h>
#include <model/Default.h>
#include <model/Platinum.h>
#include <model/Gold.h>
#include <model/Silver.h>
#include <model/Diamond.h>
#include <model/Bronze.h>
#include <functional>

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
typedef std::shared_ptr<ClientType> ClientTypePtr;

typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;
typedef std::shared_ptr<RentRepository> RentRepositoryPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;

typedef std::shared_ptr<StorageContainer> StorageContainerPtr;

typedef std::shared_ptr<Default> DefaultPtr;
typedef std::shared_ptr<Bronze> BronzePtr;
typedef std::shared_ptr<Silver> SilverPtr;
typedef std::shared_ptr<Gold> GoldPtr;
typedef std::shared_ptr<Platinum> PlatinumPtr;
typedef std::shared_ptr<Diamond> DiamondPtr;

typedef std::function<bool(RentPtr)> RentPredicate;
typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(VehiclePtr)> VehiclePredicate;

#endif //CARRENTAL_TYPEDEFS_H
