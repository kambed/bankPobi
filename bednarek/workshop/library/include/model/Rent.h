//
// Created by student on 05.04.2021.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "Client.h"
#include "Vehicle.h"
#include "../typedefs.h"
#include <boost/date_time/posix_time/ptime.hpp>
class Client;
class Rent {
private:
    unsigned int id;
    ClientPtr client;
    VehiclePtr vehicle;
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime = boost::posix_time::not_a_date_time;
    int rentCost=0;
    bool archive=false;
public:
    //CONSTRUCTOR
    Rent(unsigned int id, ClientPtr client, VehiclePtr vehicle, const boost::posix_time::ptime &beginTime,int rentCost);

    //GETTERS
    unsigned int getId() const;

    bool isArchive() const;

    void setArchive(bool archive);

    const ClientPtr getClient() const;
    const VehiclePtr getVehicle() const;

    const boost::posix_time::ptime &getBeginTime() const;
    const boost::posix_time::ptime &getEndTime() const;
    const std::string getInfo() const;
    const std::string getRentInfo() const;
    int getRentdays();
    int getRentcost();

    //METHODS
    void endRent(const boost::posix_time::ptime &endTime);
};


#endif //CARRENTAL_RENT_H
