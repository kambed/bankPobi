#include <memory>
#include <functional>

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

typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(VehiclePtr)> VehiclePredicate;
typedef std::function<bool(RentPtr)> RentPredicate;

class ClientType;
typedef std::shared_ptr<ClientType> ClientTypePtr;

class ClientManager;
class VehicleManager;
class RentManager;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<VehicleManager> VehicleManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;

class LogicContainer;
typedef std::shared_ptr<LogicContainer> LogicContainerPtr;

#endif //CARRENTAL_TYPEDEFS_H
