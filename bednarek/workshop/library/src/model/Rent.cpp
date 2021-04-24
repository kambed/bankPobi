//
// Created by student on 05.04.2021.
//

#include <string>
#include <iostream>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
//CONSTRUCTOR
Rent::Rent(unsigned int id, ClientPtr client, VehiclePtr vehicle, const boost::posix_time::ptime &beginTime,int rentCost) : id(id), client(client), vehicle(vehicle), beginTime(beginTime), rentCost(rentCost){
    if(beginTime == boost::posix_time::not_a_date_time)
    {
        this->beginTime = boost::posix_time::second_clock::local_time();
    }
}

//GETTERS
unsigned int Rent::getId() const {
    return id;
}
const ClientPtr Rent::getClient() const {
    return client;
}
const VehiclePtr Rent::getVehicle() const {
    return vehicle;
}
const boost::posix_time::ptime &Rent::getBeginTime() const {
    return beginTime;
}
const boost::posix_time::ptime &Rent::getEndTime() const {
    return endTime;
}
const std::string Rent::getRentInfo() const{
    std::stringstream ss;
    ss << beginTime;
    std::string begin = ss.str();
    std::stringstream ss2;
    ss2 << endTime;
    std::string end = ss2.str();
    return "Rent ID:" + std::to_string(id) + "Time: from:" + begin + " to: " + end + " " + client->getClientInfo() + " " + vehicle->getVehicleInfo();
}
int Rent::getRentdays() {
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    if(endTime == boost::posix_time::not_a_date_time)
    {
        return 0;
    }
    else
    {
        boost::posix_time::time_period period(beginTime,endTime);
        if(period.length().hours() == 0 && period.length().minutes() == 0)
        {
            return 0;
        }
        else
        {
            return (period.length().hours()/24)+1;
        }
    }
}
int Rent::getRentcost() {
    return getRentdays()*rentCost;
}

//METHODS
void Rent::endRent(const boost::posix_time::ptime &endTime) {
    if(this->endTime == boost::posix_time::not_a_date_time)
    {
        if(endTime == boost::posix_time::not_a_date_time) {
            this->endTime = boost::posix_time::second_clock::local_time();
        }
        else
        {
            if(endTime<beginTime)
                this->endTime = beginTime;
            else
                this->endTime = endTime;
        }
    }
    rentCost=client->applyDiscount(rentCost);
}
