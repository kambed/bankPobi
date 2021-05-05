#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H


#include "typedefs.h"
#include <vector>
#include <boost/date_time/posix_time/ptime.hpp>

class RentManager {
private:
    RentRepositoryPtr currentRents;
    RentRepositoryPtr archiveRents;
public:
    RentManager();

    std::vector<RentPtr> getAllClientRents(ClientPtr client) const;

    RentPtr getVehicleRent(VehiclePtr vehicle) const;

    std::vector<RentPtr> findRents(RentPredicate predicate) const;

    std::vector<RentPtr> findAllRents() const;

    double checkClientRentBalance(ClientPtr client);

    RentPtr rentVehicle(int id,ClientPtr client, VehiclePtr vehicle, boost::posix_time::ptime beginTime);

    void returnVehicle(VehiclePtr vehicle, boost::posix_time::ptime endTime);

    void changeClientType(ClientPtr client);
};


#endif //CARRENTAL_RENTMANAGER_H
