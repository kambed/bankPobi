#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H


#include "typedefs.h"
#include <vector>

class ClientManager {
private:
    ClientRepositoryPtr clientRepository;
public:
    ClientManager();

    ClientPtr getClient(std::string personalId);
    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr adres,
                             ClientTypePtr clientType);
    void unregisterClient(std::string personalId);

    std::vector<ClientPtr> findClients(ClientPredicate predicate) const;

    std::vector<ClientPtr> findAllClients() const;
};


#endif //CARRENTAL_CLIENTMANAGER_H
