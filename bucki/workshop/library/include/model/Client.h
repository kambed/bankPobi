#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H


class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
public:
    Client();
    ~Client();

    std::string getClientInfo();
};


#endif //CARRENTAL_CLIENT_H
