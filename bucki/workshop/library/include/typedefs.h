#include <memory>
#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H


class Client;
class Address;
class Vehicle;
class Rent;

typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Rent> RentPtr;

class ClientRepository;
class VehicleRepository;
class RentRepository;

typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;
typedef std::shared_ptr<RentRepository> RentRepositoryPtr;

class StorageContainer;

typedef std::shared_ptr<StorageContainer> StorageContainerPtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);
typedef bool (*RentPredicate)(RentPtr);


#endif //CARRENTAL_TYPEDEFS_H
