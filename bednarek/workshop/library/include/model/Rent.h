//
// Created by student on 05.04.2021.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "Client.h"
#include "Vehicle.h"
class Client;
class Rent {
private:
    unsigned int id;
    Client *client;
    Vehicle *vehicle;
public:
    Rent(unsigned int id, Client *client, Vehicle *vehicle);

    unsigned int getId() const;

    Client *getClient() const;

    Vehicle *getVehicle() const;

    std::string getRentInfo();
};


#endif //CARRENTAL_RENT_H
