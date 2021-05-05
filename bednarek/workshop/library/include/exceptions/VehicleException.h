//
// Created by student on 03.05.2021.
//

#ifndef CARRENTAL_VEHICLEEXCEPTION_H
#define CARRENTAL_VEHICLEEXCEPTION_H


#include <stdexcept>
#include <ostream>

class VehicleException : public std::logic_error{
public:
    VehicleException(const std::string &arg);
};


#endif //CARRENTAL_VEHICLEEXCEPTION_H
