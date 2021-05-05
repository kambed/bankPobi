#include <memory>
#include "model/managers/RentManager.h"
#include "model/Rent.h"
#include "model/vehicles/Vehicle.h"
#include "model/clients/Client.h"
#include "repositories/RentRepository.h"
#include "typedefs.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <model/clients/Default.h>
#include <model/clients/Bronze.h>
#include <model/clients/Silver.h>
#include <model/clients/Gold.h>
#include <model/clients/Diamond.h>
#include <model/clients/Platinum.h>

RentManager::RentManager() {
    currentRents = std::make_shared<RentRepository>();
    archiveRents = std::make_shared<RentRepository>();
}

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client) const {
    std::vector<RentPtr> clientRents;
    for(int i=0;i<currentRents->getRentsSize();i++)
        if(currentRents->getRent(i)->getClient() == client)
            clientRents.push_back(currentRents->getRent(i));
    return clientRents;
}

RentPtr RentManager::getVehicleRent(VehiclePtr vehicle) const {
    for(int i=0;i<currentRents->getRentsSize();i++)
        if(currentRents->getRent(i)->getVehicle() == vehicle)
            return currentRents->getRent(i);
    return nullptr;
}

std::vector<RentPtr> RentManager::findRents(RentPredicate predicate) const {
    return currentRents->findBy(predicate);
}

std::vector<RentPtr> RentManager::findAllRents() const {
    return currentRents->findAll();
}

double RentManager::checkClientRentBalance(ClientPtr client) {
    double suma=0;
    for (unsigned int i = 0; i < archiveRents->getRentsSize(); i++)
        if(archiveRents->getRent(i)->getClient() == client)
            suma += archiveRents->getRent(i)->getRentCost();
    return suma;
}

RentPtr RentManager::rentVehicle(int id,ClientPtr client, VehiclePtr vehicle, boost::posix_time::ptime beginTime) {
    if(client->isArchive() == false && vehicle->isArchive() == false && client->getMaxVehicles()>getAllClientRents
    (client).size() && getVehicleRent(vehicle) == nullptr) {
        RentPtr rent = std::make_shared<Rent>(id,client,vehicle,beginTime);
        currentRents->addRent(rent);
        return rent;
    }else return nullptr;
}

void RentManager::returnVehicle(VehiclePtr vehicle, boost::posix_time::ptime endTime) {
    if(getVehicleRent(vehicle)!=nullptr){
        changeClientType(getVehicleRent(vehicle)->getClient());
        getVehicleRent(vehicle)->endRent(endTime);
        archiveRents->addRent(getVehicleRent(vehicle));
        currentRents->removeRent(getVehicleRent(vehicle));
    }
}

void RentManager::changeClientType(ClientPtr client) {
    double balance = checkClientRentBalance(client);
    if(balance >= 0 && balance < 100.0)
        client->setClientType(std::make_shared<Default>());
    else if(balance < 200.0)
        client->setClientType(std::make_shared<Bronze>());
    else if(balance < 400.0)
        client->setClientType(std::make_shared<Silver>());
    else if(balance < 800.0)
        client->setClientType(std::make_shared<Gold>());
    else if(balance < 1600.0)
        client->setClientType(std::make_shared<Diamond>());
    else
        client->setClientType(std::make_shared<Platinum>());

}


