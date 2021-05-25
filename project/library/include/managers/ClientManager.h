#ifndef BANK_CLIENTMANAGER_H
#define BANK_CLIENTMANAGER_H

#include "repositories/ClientRepository.h"
#include <boost/date_time.hpp>

class ClientManager {
private:
    ClientRepositoryPtr clientRepository;
public:
    ///CONSTRUCTOR
    ClientManager(const ClientRepositoryPtr &clientRepository);
    ///METHODS
    ClientPtr getClient(std::string personalId);
    void addClient(const std::string &personalId, const std::string &firstName, const std::string &lastName,
                   const boost::posix_time::ptime &birthDate);
    std::vector<ClientPtr> findAll();
    std::vector<ClientPtr> findClients(ClientPredicate predicate);
};


#endif //BANK_CLIENTMANAGER_H
