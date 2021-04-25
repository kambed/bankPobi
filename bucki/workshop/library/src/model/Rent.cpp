#include "model/Rent.h"
#include "typedefs.h"

Rent::Rent(unsigned int id, ClientPtr client, VehiclePtr vehicle, const boost::posix_time::ptime &beginTime) : id(id),
                                                                                                               client(client),
                                                                                                               vehicle(vehicle),
                                                                                                               beginTime(
                                                                                                                       beginTime) {
//    client->addRent(this);
//    vehicle->setRented(true);
    if (beginTime == boost::posix_time::not_a_date_time)
        this->beginTime = boost::posix_time::second_clock::local_time();
    else this->beginTime = beginTime;
    rentCost = vehicle->getBasePrice();
}

const ClientPtr Rent::getClient() const {
    return client;
}

const VehiclePtr Rent::getVehicle() const {
    return vehicle;
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
    return id + ", klient: " + client->getClientInfo() + ", pojazd: " + vehicle->getVehicleInfo() +
           ", Rozpoczecie wypozyczenia: " + begin + ", Zakonczenie wypozyczenia: " + end;
}

unsigned int Rent::getId() const {
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