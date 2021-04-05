//
// Created by student on 05.04.2021.
//

#include <iostream>
#include <string>
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

Rent::Rent(unsigned int id, Client *client, Vehicle *vehicle) : id(id), client(client), vehicle(vehicle) {
    client->setCurrentRents(this);
    vehicle->setRented(true);
}

unsigned int Rent::getId() const {
    return id;
}

Client *Rent::getClient() const {
    return client;
}

Vehicle *Rent::getVehicle() const {
    return vehicle;
}

std::string Rent::getRentInfo() {
    return "Rent ID:" + std::to_string(id) + " " + client->getClientInfo() + " " + vehicle->getVehicleInfo();
}
