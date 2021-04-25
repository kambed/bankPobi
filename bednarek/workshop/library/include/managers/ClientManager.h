//
// Created by student on 25.04.2021.
//

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H


#include <typedefs.h>
#include "repositories/ClientRepository.h"
class ClientManager {
private:
    ClientRepository clientRepository;
public:
    ClientPtr getClient(std::string Id);
    ClientPtr registerClient(std::string firstName,std::string lastName,std::string PersonalId,AddressPtr address,ClientTypePtr clientType);
    void unregisterClient(ClientPtr client);
    std::vector<ClientPtr> findClients(ClientPredicate predicate) const;
    std::vector<ClientPtr> findAllClients() const;
};


#endif //CARRENTAL_CLIENTMANAGER_H
