#ifndef BANK_CLIENTMANAGER_H
#define BANK_CLIENTMANAGER_H

#include "typedefs.h"
#include <boost/date_time.hpp>

class ClientManager {
private:
    ClientRepositoryPtr clientRepository;
    TurboLoggerPtr turboLogger;
    TurboSaverPtr turboSaver;
public:
    ///CONSTRUCTOR
    ClientManager(const TurboLoggerPtr &turboLogger, const TurboSaverPtr &turboSaver);
    ///METHODS
    ClientPtr getClient(std::string personalId);
    void addClient(std::string personalId, std::string firstName, std::string lastName,
                   boost::posix_time::ptime birthDate);
    void changeClientFirstName(std::string personalId,std::string newFirstName);
    void changeClientLastName(std::string personalId,std::string newLastName);
    std::vector<ClientPtr> findAll();
    std::vector<ClientPtr> findClients(ClientPredicate predicate);
};


#endif //BANK_CLIENTMANAGER_H
