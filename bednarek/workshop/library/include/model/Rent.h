//
// Created by student on 05.04.2021.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "Client.h"
#include "Vehicle.h"
#include <boost/date_time/posix_time/ptime.hpp>
class Client;
class Rent {
private:
    unsigned int id;
    Client *client;
    Vehicle *vehicle;
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime;
    int rentCost=0;
public:
    Rent(unsigned int id, Client *client, Vehicle *vehicle, const boost::posix_time::ptime &beginTime);

    unsigned int getId() const;

    Client *getClient() const;

    Vehicle *getVehicle() const;

    const std::string getRentInfo() const;

    const boost::posix_time::ptime &getBeginTime() const;

    const boost::posix_time::ptime &getEndTime() const;

    void endRent(const boost::posix_time::ptime &endTime);

    int getRentdays();

    int getRentcost() const;

};


#endif //CARRENTAL_RENT_H
