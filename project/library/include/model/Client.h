#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H

#include <boost/date_time.hpp>

class Client{
private:
    std::string personalID;
    std::string firstName;
    std::string lastName;
    boost::posix_time::ptime birthDate;
public:
    ///CONSTRUCTOR

    /// \param personalId
    /// \param firstName
    /// \param lastName
    /// \param birthDate
    Client(std::string personalId, std::string firstName, std::string lastName,
           boost::posix_time::ptime birthDate);

    ///DESTRUCTOR

    virtual ~Client();

    ///GETTERS

    /// \return string
    const std::string &getPersonalId() const;

    /// \return string
    const std::string &getFirstName() const;

    /// \return string
    const std::string &getLastName() const;

    /// \return string
    const boost::posix_time::ptime &getBirthDate() const;

    ///METHODS

    /// \param firstName
    void changeFirstName(const std::string &firstName);

    /// \param lastName
    void changeLastName(const std::string &lastName);

    /// \return string
    std::string getClientInfo() const;
};


#endif //BANK_CLIENT_H
