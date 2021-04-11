#include <string>
#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H


class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    Address(const std::string &city, const std::string &street, const std::string &number);

    const std::string getAddressInfo() const;

    const std::string &getCity() const;

//    void setCity(const std::string &city);

    const std::string &getStreet() const;

//    void setStreet(const std::string &street);

    const std::string &getNumber() const;

//    void setNumber(const std::string &number);
};


#endif //CARRENTAL_ADDRESS_H
