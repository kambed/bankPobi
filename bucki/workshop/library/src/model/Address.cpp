#include <iostream>
#include "model/Address.h"

using namespace std;

Address::Address(const string &city, const string &street, const string &number) : city(city), street(street),
                                                                                   number(number) {}

const string Address::getAddressInfo() const{
    return street+" "+number+", "+city;
}

const string &Address::getCity() const {
    return city;
}

//void Address::setCity(const string &city) {
//    Address::city = city;
//}

const string &Address::getStreet() const {
    return street;
}

//void Address::setStreet(const string &street) {
//    Address::street = street;
//}

const string &Address::getNumber() const {
    return number;
}

//void Address::setNumber(const string &number) {
//    Address::number = number;
//}
