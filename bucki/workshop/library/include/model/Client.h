#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H


class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Client();
public:
    Client(std::string firstName,std::string nastName,std::string personalID);

    ~Client();

    std::string getClientInfo();

    const std::string &getFirstName() const;
    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;
    void setLastName(const std::string &lastName);

    const std::string &getPersonalId() const;
};


#endif //CARRENTAL_CLIENT_H
