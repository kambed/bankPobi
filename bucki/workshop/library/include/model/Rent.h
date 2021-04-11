#include "Client.h"
#include "Vehicle.h"
#include <boost/date_time.hpp>

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

class Client;

class ptime;

class Rent {
private:
    unsigned int id;
    Client *client;
    Vehicle *vehicle;
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime = boost::posix_time::not_a_date_time;
    int rentCost = 0;
public:
    Rent(unsigned int id, Client *client, Vehicle *vehicle, const boost::posix_time::ptime &beginTime);

    const Client *getClient() const;

    const Vehicle *getVehicle() const;

    const std::string getRentInfo() const;

    unsigned int getId() const;

    const boost::posix_time::ptime &getBeginTime() const;

    const boost::posix_time::ptime &getEndTime() const;

    const boost::posix_time::ptime &endRent(const boost::posix_time::ptime &endTime);

    const int getRentDays() const;

    const ptime &endRent(const ptime &endTime);

    const int &getRentCost() const;


};


#endif //CARRENTAL_RENT_H
