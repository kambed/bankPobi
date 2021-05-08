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
    /// CONSTRUCTOR

    /// \param id
    /// \param client
    /// \param vehicle
    /// \param beginTime
    Rent(boost::uuids::uuid id, ClientPtr client, VehiclePtr vehicle, const boost::posix_time::ptime &beginTime);

    /// GETTERS

    /// \return
    const ClientPtr getClient() const;

    /// \return
    const VehiclePtr getVehicle() const;

    /// \return
    const std::string getInfo() const;

    /// \return
    const std::string getRentInfo() const;

    /// \return
    boost::uuids::uuid getId() const;

    /// \return
    const boost::posix_time::ptime &getBeginTime() const;

    /// \return
    const boost::posix_time::ptime &getEndTime() const;

    /// \return
    const int getRentDays() const;

    /// \return
    const int &getRentCost() const;

    /// METHODS

    /// \param endTime
    void endRent(const boost::posix_time::ptime &endTime);




};


#endif //CARRENTAL_RENT_H
