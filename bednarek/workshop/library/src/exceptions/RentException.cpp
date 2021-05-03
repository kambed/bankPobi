//
// Created by student on 03.05.2021.
//

#include "exceptions/RentException.h"

RentException::RentException(const std::string &arg) : logic_error(arg) {}
