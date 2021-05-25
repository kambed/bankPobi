#ifndef BANK_CLIENTMANAGER_H
#define BANK_CLIENTMANAGER_H

#include "repositories/ClientRepository.h"
#include <boost/date_time.hpp>

class ClientManager {
private:
    ClientRepositoryPtr clientRepository;
public:
    ///CONSTRUCTOR
    ClientManager();
    ///METHODS
    ClientPtr getClient(std::string personalId);
    void addClient(std::string personalId, std::string firstName, std::string lastName,
                   boost::posix_time::ptime birthDate);
    std::vector<ClientPtr> findAll();
    std::vector<ClientPtr> findClients(ClientPredicate predicate);
};


#endif //BANK_CLIENTMANAGER_H
