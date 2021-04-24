#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H


class Client;
class Address;
class Vehicle;
class Rent;

typedef Address *AddressPtr;
typedef Client *ClientPtr;
typedef Vehicle *VehiclePtr;
typedef Rent *RentPtr;

class ClientRepository;
class VehicleRepository;
class RentRepository;

typedef ClientRepository *ClientRepositoryPtr;
typedef VehicleRepository *VehicleRepositoryPtr;
typedef RentRepository *RentRepositoryPtr;

class StorageContainer;

typedef StorageContainer *StorageContainerPtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);
typedef bool (*RentPredicate)(RentPtr);


#endif //CARRENTAL_TYPEDEFS_H
