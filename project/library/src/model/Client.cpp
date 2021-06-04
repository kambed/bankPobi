#include "model/Client.h"
#include <string>
#include "functions.h"
#include "exceptions/ClientException.h"

Client::Client(std::string personalId, std::string firstName, std::string lastName,
               boost::posix_time::ptime birthDate) try : personalID(personalId), firstName(firstName),
                                                          lastName(lastName), birthDate(birthDate) {
    if(personalId.empty()) throw ClientException("Empty presonalId");
    if(personalId.length() != 11) throw ClientException("Bad length of presonalId");
    if(firstName.empty()) throw ClientException("Empty firstName");
    if(lastName.empty()) throw ClientException("Empty lastName");
    if(birthDate >= ( boost::posix_time::second_clock::local_time() - boost::gregorian::years(13) ))
        throw ClientException("Client don't have 13 years old");
}catch(const ClientException &exception){
    std::cout << "Exception: " << exception.what() << std::endl;
}

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

std::string Client::getClientInfo() const {
    return personalID+", "+firstName+" "+lastName+" Data urodzenia: "+dateTimeToString(birthDate);
}

