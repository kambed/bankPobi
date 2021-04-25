#include <memory>
#include <functional>
#include "model/managers/ClientManager.h"
#include "typedefs.h"
#include <model/clients/Client.h>
#include "repositories/ClientRepository.h"

ClientPtr ClientManager::getClient(std::string personalId) {
    return clientRepository->findByPersonalId(personalId);
}

ClientPtr ClientManager::registerClient(const std::string &firstName, const std::string &lastName, const std::string
&personalID, AddressPtr adres, ClientTypePtr clientType) {
    if (clientRepository->findByPersonalId(personalID) != nullptr)
        return clientRepository->findByPersonalId(personalID);
    else {
        ClientPtr client = std::make_shared<Client>(firstName, lastName, personalID, adres, clientType);
        clientRepository->addClient(client);
        return client;
    }
}

ClientManager::ClientManager(const ClientRepositoryPtr &clientRepository) : clientRepository(clientRepository) {}

ClientManager::ClientManager() {
    clientRepository = std::make_shared<ClientRepository>();
}

void ClientManager::unregisterClient(std::string personalId) {
    if (getClient(personalId) != nullptr)
        getClient(personalId)->setArchive(true);
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) const {
    auto function = [&](const ClientPtr client) -> bool {
        return (predicate(client) && client->isArchive()) == false;
    };

    return clientRepository->findBy(function);
}

bool predicateTrueManager(ClientPtr client){
    return client != nullptr;
}

std::vector<ClientPtr> ClientManager::findAllClients() const {
    return findClients(predicateTrueManager);
}
