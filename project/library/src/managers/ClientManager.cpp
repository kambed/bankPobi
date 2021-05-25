#include "managers/ClientManager.h"
#include "Client.h"
#include "typedefs.h"
#include <boost/date_time.hpp>

ClientManager::ClientManager(const ClientRepositoryPtr &clientRepository) : clientRepository(clientRepository) {}

ClientPtr ClientManager::getClient(std::string personalId) {
    return ClientPtr();
}

void ClientManager::addClient(const std::string &personalId, const std::string &firstName, const std::string &lastName,
                              const boost::posix_time::ptime &birthDate) {
    if (clientRepository->getClient(personalId) != nullptr){
        ClientPtr client = std::make_shared<Client>(personalId,firstName,lastName,birthDate);
        clientRepository->addClient(client);
    }
}

bool predicateTrueManager(ClientPtr client){
    return client != nullptr;
}

std::vector<ClientPtr> ClientManager::findAll() {
    return findClients(predicateTrueManager);
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) {
    return findClients(predicate);
}
