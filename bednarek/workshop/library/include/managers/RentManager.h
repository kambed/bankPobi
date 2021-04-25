//
// Created by student on 25.04.2021.
//

#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H

#include "typedefs.h"
#include "repositories/RentRepository.h"
#include <boost/date_time/posix_time/ptime.hpp>

class RentManager {
public:
    RentRepository currentRents;
    RentRepository archiveRents;
public:
    std::vector<RentPtr> getAllClientRents(ClientPtr client) const;
    RentPtr getVehicleRent(VehiclePtr vehicle) const;
    std::vector<RentPtr> findRents(RentPredicate predicate) const;
    std::vector<RentPtr> findAllRents() const;
    double checkClientRentBalance(ClientPtr client) const;
    RentPtr rentVehicle(int id,ClientPtr client,VehiclePtr vehicle,boost::posix_time::ptime beginTime);
    void returnVehicle(VehiclePtr vehicle,boost::posix_time::ptime endTime);
    void changeClientType(ClientPtr client) const;
};


#endif //CARRENTAL_RENTMANAGER_H
