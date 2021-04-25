#include "model/Clients/Client.h"
#include "model/Vehicles/Vehicle.h"
#include <boost/date_time.hpp>
#include <typedefs.h>

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

class Client;

class ptime;

class Rent {
private:
    unsigned int id;
    ClientPtr client;
    VehiclePtr vehicle;
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime = boost::posix_time::not_a_date_time;
    int rentCost = 0;
public:
    Rent(unsigned int id, ClientPtr client, VehiclePtr vehicle, const boost::posix_time::ptime &beginTime);

    const ClientPtr getClient() const;

    const VehiclePtr getVehicle() const;

    const std::string getRentInfo() const;

    unsigned int getId() const;

    const boost::posix_time::ptime &getBeginTime() const;

    const boost::posix_time::ptime &getEndTime() const;

    void endRent(const boost::posix_time::ptime &endTime);

    const int getRentDays() const;

    const ptime &endRent(const ptime &endTime);

    const int &getRentCost() const;


};


#endif //CARRENTAL_RENT_H
