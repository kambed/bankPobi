#include "model/Rent.h"

Rent::Rent(unsigned int id, Client *client, Vehicle *vehicle,const boost::posix_time::ptime &beginTime): id(id),
           client(client), vehicle(vehicle),  beginTime(beginTime) {
    client->addRent(this);
    vehicle->setRented(true);
    if(beginTime == boost::posix_time::not_a_date_time)
        this->beginTime = boost::posix_time::second_clock::local_time();
    else this->beginTime = beginTime;
    rentCost = vehicle->getBasePrice();
}

const Client *Rent::getClient() const {
    return client;
}

const Vehicle *Rent::getVehicle() const {
    return vehicle;
}

const std::string Rent::getRentInfo() const {
    return id + ", klient: " + client->getClientInfo() + ", pojazd: " + vehicle->getVehicleInfo() +
           ", Rozpoczecie wyporzyczenia: " + beginTime.zone_as_posix_string() + ", Zakonczenie wyporzyczenia: " +
           endTime.zone_as_posix_string();
}

unsigned int Rent::getId() const {
    return id;
}

const boost::posix_time::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const boost::posix_time::ptime &Rent::getEndTime() const {
    return endTime;
}

const boost::posix_time::ptime &Rent::endRent(const boost::posix_time::ptime &endTime) {
    if(this->endTime == boost::posix_time::not_a_date_time) {
        if (endTime < beginTime)
            this->endTime = beginTime;
        else if (endTime == boost::posix_time::not_a_date_time)
            this->endTime = boost::posix_time::second_clock::local_time();
        else this->endTime = endTime;
        vehicle->setRented(false);
        client->removeRent(this);
    }
    rentCost=rentCost*getRentDays();
}

const int Rent::getRentDays() const {
    boost::posix_time::time_period period(beginTime,endTime);
    if(endTime == boost::posix_time::not_a_date_time || (period.length().minutes() == 0 && period.length().hours() ==
    0))
        return 0;
    else
        return period.length().hours() / 24 + 1;
}

const int &Rent::getRentCost() const {
    return rentCost;
}