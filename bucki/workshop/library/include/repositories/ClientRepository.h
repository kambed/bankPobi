#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H


#include <typedefs.h>
#include <vector>
#include <string>

class ClientRepository {
private:
    std::vector<ClientPtr> clients;
public:

    ClientPtr getClient(unsigned int id) const;

    void addClient(ClientPtr client);

    void removeClient(ClientPtr client);

    const std::string reportClients() const;

    unsigned int getClientsSize();

//    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;
//
//    std::vector<ClientPtr> findAll() const;
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
