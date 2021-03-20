//
// Created by student on 20.03.2021.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H


class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Client();
public:
    Client(std::string firstName,std::string lastName,std::string personalID);
    virtual ~Client();

    std::string getClientInfo();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

};


#endif //CARRENTAL_CLIENT_H
