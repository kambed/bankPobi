#include "Client.h"

Client::Client(const std::string &personalId, const std::string &firstName, const std::string &lastName,
               const boost::posix_time::ptime &birthDate) : personalID(personalId), firstName(firstName),
                                                          lastName(lastName), birthDate(birthDate) {}

Client::~Client() {}

const std::string &Client::getPersonalId() const {
    return personalID;
}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const boost::posix_time::ptime &Client::getBirthDate() const {
    return birthDate;
}

void Client::changeFirstName(const std::string &firstName) {
    if(firstName != "")
        Client::firstName = firstName;
}

void Client::changeLastName(const std::string &lastName) {
    if(lastName != "")
        Client::lastName = lastName;
}

const std::string &Client::getClientInfo() const {
    std::stringstream ss;
    ss << birthDate;
    std::string birthdate = ss.str();
    return personalID+", "+firstName+" "+lastName+", data urodzenia: "+birthdate;
}

