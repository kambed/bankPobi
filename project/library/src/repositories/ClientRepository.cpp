#include "repositories/ClientRepository.h"
#include "model/Client.h"

ClientRepository::ClientRepository() {}

ClientPtr ClientRepository::getClient(std::string personalId) {
    for (int i = 0; i < clients.size(); i++) {
        ClientPtr client = clients[i];
        if (client->getPersonalId() == personalId)
            return client;
    }
    return nullptr;
}

void ClientRepository::addClient(ClientPtr client) {
    if (client != nullptr)
        clients.push_back(client);
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate){
    std::vector<ClientPtr> found;
    for (int i = 0; i < clients.size(); i++) {
        ClientPtr client = clients[i];
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}