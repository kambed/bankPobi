#include "model/Rent.h"
#include "typedefs.h"
#include "exceptions/RentException.h"
#include <string>
#include <boost/uuid/uuid_io.hpp>

Rent::Rent(boost::uuids::uuid id, ClientPtr client, VehiclePtr vehicle, const boost::posix_time::ptime &beginTime)
           try : id(id),client(client),vehicle(vehicle),beginTime(beginTime) {

    if (beginTime == boost::posix_time::not_a_date_time)
        this->beginTime = boost::posix_time::second_clock::local_time();
    else this->beginTime = beginTime;

    if(client == nullptr) throw RentException("Client not received");
    if(vehicle == nullptr) throw RentException("Vehicle not received");

    rentCost = vehicle->getBasePrice();
}
catch(const RentException &exception){
    std::cout <<" Exception: " << exception.what() << std::endl;
}

const ClientPtr Rent::getClient() const {
    return client;
}

const VehiclePtr Rent::getVehicle() const {
    return vehicle;
}

const std::string Rent::getInfo() const {
    return getRentInfo();
}

const std::string Rent::getRentInfo() const {
    std::stringstream ss;
    ss << beginTime;
    std::string begin = ss.str();
    std::stringstream ss2;
    ss2 << endTime;
    std::string end = ss2.str();
    if (end == "not-a-date-time")
        end = "nie zakonczono";
    return to_string(id) + ", klient: " + client->getClientInfo() + ", pojazd: " + vehicle->getVehicleInfo() +
           ", Rozpoczecie wypozyczenia: " + begin + ", Zakonczenie wypozyczenia: " + end;
}

boost::uuids::uuid Rent::getId() const {
    return id;
}

const boost::posix_time::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const boost::posix_time::ptime &Rent::getEndTime() const {
    return endTime;
}

void Rent::endRent(const boost::posix_time::ptime &endTime) {
    if (this->endTime == boost::posix_time::not_a_date_time) {
        if (endTime < beginTime)
            this->endTime = beginTime;
        else if (endTime == boost::posix_time::not_a_date_time)
            this->endTime = boost::posix_time::second_clock::local_time();
        else this->endTime = endTime;
//        vehicle->setRented(false);
//        client->removeRent(this);
    }
    rentCost = (rentCost - client->applyDiscount(rentCost)) * getRentDays();
}

const int Rent::getRentDays() const {
    boost::posix_time::time_period period(beginTime, endTime);
    if (endTime == boost::posix_time::not_a_date_time || (period.length().minutes() == 0 && period.length().hours() ==
                                                                                            0))
        return 0;
    else
        return period.length().hours() / 24 + 1;
}

const int &Rent::getRentCost() const {
    return rentCost;
}