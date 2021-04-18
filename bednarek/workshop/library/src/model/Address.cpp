//
// Created by student on 05.04.2021.
//

#include <iostream>
#include <string>
#include "model/Address.h"

using namespace std;

//CONSTRUCTOR
Address::Address(const std::string &city, const std::string &street, const std::string &number) : city(city),street(street),number(number) {

};

//GETTERS
const std::string Address::getAddressInfo() const {
    return "Adres:" + city + ", " + street + " " + number;
}
const std::string &Address::getCity() const {
    return city;
}
const std::string &Address::getStreet() const {
    return street;
}
const std::string &Address::getNumber() const {
    return number;
}
