#include <string>

#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H


class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    /// CONSTRUCTOR

    /// \param city
    /// \param street
    /// \param number
    Address(const std::string &city, const std::string &street, const std::string &number);

    /// GETTERS

    /// \return
    const std::string getAddressInfo() const;

    /// \return
    const std::string &getCity() const;

    /// \return
    const std::string &getStreet() const;

    /// \return
    const std::string &getNumber() const;
};


#endif //CARRENTAL_ADDRESS_H
