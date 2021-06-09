#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H

#include <string>
#include <boost/date_time.hpp>
#include <typedefs.h>

class Client{
private:
    std::string personalID;
    std::string firstName;
    std::string lastName;
    boost::posix_time::ptime birthDate;
public:
    ///CONSTRUCTOR
    Client(std::string personalId, std::string firstName, std::string lastName,
           boost::posix_time::ptime birthDate);
    ///DESTRUCTOR
    virtual ~Client();
    ///GETTERS
    const std::string &getPersonalId() const;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const boost::posix_time::ptime &getBirthDate() const;
    ///METHODS
    void changeFirstName(const std::string &firstName);

    void changeLastName(const std::string &lastName);

    std::string getClientInfo() const;
};


#endif //BANK_CLIENT_H
