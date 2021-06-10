#include "managers/ClientManager.h"
#include "model/Client.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"
#include "exceptions/ClientManagerException.h"
#include "typedefs.h"
#include <boost/date_time.hpp>
#include "templates.h"
ClientManager::ClientManager(const TurboLoggerPtr &turboLogger, const TurboSaverPtr &turboSaver) : turboLogger(
        turboLogger), turboSaver(turboSaver) {
    clientRepository = std::make_shared<ClientRepository>();
    if(turboLogger == nullptr) throw ClientManagerException("Empty TurboLogger");
    if(turboSaver == nullptr) throw ClientManagerException("Empty TurboSaver");
}

ClientPtr ClientManager::getClient(std::string personalId) {
    return clientRepository->getClient(personalId);
}

void ClientManager::addClient(std::string personalId, std::string firstName, std::string lastName,
                              boost::posix_time::ptime birthDate) {
    ClientPtr client = std::make_shared<Client>(personalId,firstName,lastName,birthDate);
    if (clientRepository->getClient(personalId) == nullptr){
        clientRepository->addClient(client);
        turboLogger->addLog("Create client: "+client->getClientInfo());
        turboSaver->saveClient(client);
    }else{
        turboLogger->addLog("Create client fail: "+client->getClientInfo());
    }
}

std::vector<ClientPtr> ClientManager::findAll() {
    return findAllTemplate<ClientPtr,ClientRepositoryPtr>(clientRepository);
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) {
    return findClients(predicate);
}

void ClientManager::changeClientFirstName(std::string personalId,std::string newFirstName) {
    clientRepository->getClient(personalId)->changeFirstName(newFirstName);
    turboSaver->saveClient(clientRepository->getClient(personalId));
    turboLogger->addLog("Client change first name: "+clientRepository->getClient(personalId)->getClientInfo());
}

void ClientManager::changeClientLastName(std::string personalId,std::string newLastName) {
    clientRepository->getClient(personalId)->changeLastName(newLastName);
    turboSaver->saveClient(clientRepository->getClient(personalId));
    turboLogger->addLog("Client change last name: "+clientRepository->getClient(personalId)->getClientInfo());
}


