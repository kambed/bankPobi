//
// Created by student on 25.04.2021.
//

#include "managers/RentManager.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <boost/uuid/random_generator.hpp>

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client) const {
    std::vector<RentPtr> found;
    for(int i=0;i<currentRents.sizeRent();i++)
    {
        if(currentRents.getRent(i)->getClient()->getPersonalId()==client->getPersonalId())
        {
            found.push_back(currentRents.getRent(i));
        }
    }
    return found;
}
RentPtr RentManager::getVehicleRent(VehiclePtr vehicle) const {
    for(int i=0;i<currentRents.sizeRent();i++)
    {
        if(currentRents.getRent(i)->getVehicle()->getPlateNumber()==vehicle->getPlateNumber())
        {
            return currentRents.getRent(i);
        }
    }
    return nullptr;
}
std::vector<RentPtr> RentManager::findRents(RentPredicate predicate) const {
    auto function = [&](const RentPtr &ptr)->bool{return(predicate(ptr)&&!ptr->isArchive());};
    return currentRents.findBy(function);
}
bool predicateTrue(RentPtr ptr)
{
    return ptr != nullptr;
}
std::vector<RentPtr> RentManager::findAllRents() const {
    auto function = [&](const RentPtr &ptr)->bool{return(predicateTrue(ptr)&&!ptr->isArchive());};
    return currentRents.findBy(function);
}

double RentManager::checkClientRentBalance(ClientPtr client) const {
    double rentbalance=0;
    for(int i=0;i<archiveRents.sizeRent();i++)
    {
        if(archiveRents.getRent(i)->getClient()->getPersonalId()==client->getPersonalId())
        {
            rentbalance=rentbalance+archiveRents.getRent(i)->getRentcost();
        }
    }
    return rentbalance;
}

RentPtr RentManager::rentVehicle(ClientPtr client, VehiclePtr vehicle, boost::posix_time::ptime beginTime) {
    if(client->isArchive()==false && vehicle->isArchive()==false && client->getMaxVehicles()>getAllClientRents(client).size() && getVehicleRent(vehicle)==nullptr)
    {
        boost::uuids::random_generator generator;
        RentPtr rent = std::make_shared<Rent>(generator(),client,vehicle,beginTime,vehicle->getBasePrice());
        currentRents.addRent(rent);
        return rent;
    }
    else
    {
        return nullptr;
    }
}
void RentManager::returnVehicle(VehiclePtr vehicle, boost::posix_time::ptime endTime) {
    if(getVehicleRent(vehicle)!=nullptr)
    {
        getVehicleRent(vehicle)->endRent(endTime);
        archiveRents.addRent(getVehicleRent(vehicle));
        currentRents.removeRent(getVehicleRent(vehicle));
    }
}

void RentManager::changeClientType(ClientPtr client) const {
    DefaultPtr defaultt = std::make_shared<Default>();
    BronzePtr bronze = std::make_shared<Bronze>();
    SilverPtr silver = std::make_shared<Silver>();
    GoldPtr gold = std::make_shared<Gold>();
    PlatinumPtr platinum = std::make_shared<Platinum>();
    DiamondPtr diamond = std::make_shared<Diamond>();
    if(checkClientRentBalance(client)<100)
    {
        client->setClientType(defaultt);
    }
    else if(checkClientRentBalance(client)>=100 && checkClientRentBalance(client)<200)
    {
        client->setClientType(bronze);
    }
    else if(checkClientRentBalance(client)>=200 && checkClientRentBalance(client)<400)
    {
        client->setClientType(silver);
    }
    else if(checkClientRentBalance(client)>=400 && checkClientRentBalance(client)<800)
    {
        client->setClientType(gold);
    }
    else if(checkClientRentBalance(client)>=800 && checkClientRentBalance(client)<1600)
    {
        client->setClientType(platinum);
    }
    else
    {
        client->setClientType(diamond);
    }
}
