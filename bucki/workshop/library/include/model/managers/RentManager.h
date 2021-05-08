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
    /// CONSTRUCTOR

    RentManager();

    /// GETTERS

    /// \param client
    /// \return
    std::vector<RentPtr> getAllClientRents(ClientPtr client) const;

    /// \param vehicle
    /// \return
    RentPtr getVehicleRent(VehiclePtr vehicle) const;

    /// METHODS

    /// \param predicate
    /// \return
    std::vector<RentPtr> findRents(RentPredicate predicate) const;

    /// \return
    std::vector<RentPtr> findAllRents() const;

    /// \param client
    /// \return
    double checkClientRentBalance(ClientPtr client);

    /// \param client
    /// \param vehicle
    /// \param beginTime
    /// \return
    RentPtr rentVehicle(ClientPtr client, VehiclePtr vehicle, boost::posix_time::ptime beginTime);

    /// \param vehicle
    /// \param endTime
    void returnVehicle(VehiclePtr vehicle, boost::posix_time::ptime endTime);

    /// \param client
    void changeClientType(ClientPtr client);
};


#endif //CARRENTAL_RENTMANAGER_H
