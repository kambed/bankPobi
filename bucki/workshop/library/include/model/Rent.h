#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "model/clients/Client.h"
#include "model/vehicles/Vehicle.h"
#include <boost/date_time.hpp>
#include <typedefs.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

class Client;

class Rent {
private:
    boost::uuids::uuid id;
    ClientPtr client;
    VehiclePtr vehicle;
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime = boost::posix_time::not_a_date_time;
    int rentCost = 0;
public:
    Rent(boost::uuids::uuid id, ClientPtr client, VehiclePtr vehicle, const boost::posix_time::ptime &beginTime);

    const ClientPtr getClient() const;

    const VehiclePtr getVehicle() const;

    const std::string getInfo() const;

    const std::string getRentInfo() const;

    boost::uuids::uuid getId() const;

    const boost::posix_time::ptime &getBeginTime() const;

    const boost::posix_time::ptime &getEndTime() const;

    void endRent(const boost::posix_time::ptime &endTime);

    const int getRentDays() const;

    const int &getRentCost() const;


};


#endif //CARRENTAL_RENT_H
