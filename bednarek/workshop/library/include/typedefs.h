//
// Created by student on 16.04.2021.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H


class Client;
class Address;
class Rent;
class Vehicle;
class VehicleRepository;
class RentRepository;
class ClientRepository;

typedef Client *ClientPtr;
typedef Address *AddressPtr;
typedef Rent *RentPtr;
typedef Vehicle *VehiclePtr;

typedef VehicleRepository *VehicleRepositoryPtr;
typedef RentRepository *RentRepositoryPtr;
typedef ClientRepository *ClientRepositoryPtr;

typedef bool (*RentPredicate)(RentPtr);
typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);

#endif //CARRENTAL_TYPEDEFS_H
