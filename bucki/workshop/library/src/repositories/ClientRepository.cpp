#include <algorithm>
#include "repositories/ClientRepository.h"
#include "model/Clients/Client.h"
#include "typedefs.h"

ClientPtr ClientRepository::getClient(unsigned int id) {
    if (clients.size() - 1 < id)
        return nullptr;
    if (clients.at(id) == nullptr)
        return nullptr;
    return clients.at(id);
}

void ClientRepository::addClient(ClientPtr client) {
    if (client != nullptr)
        clients.push_back(client);
}

void ClientRepository::removeClient(ClientPtr client) {
    if (client != nullptr)
        clients.erase(std::remove(clients.begin(), clients.end(), client));
}

const std::string ClientRepository::reportClients() const {
    std::string report;
//    for(int i=0;i<client->getCurrentRents().size();i++)
//        report += client->getCurrentRents()[i]->getRentInfo() + "/n";
//    return report;
    for (int i = 0; i < clients.size(); i++)
        report += clients[i]->getClientInfo() + "\n";
    return report;
}

unsigned int ClientRepository::getClientsSize() {
    return clients.size();
}

ClientPtr ClientRepository::findByPersonalId(std::string personalId){
    for (unsigned int i = 0; i < clients.size(); i++) {
        ClientPtr client = getClient(i);
        if (client->getPersonalId() == personalId)
            return client;
    }
    return nullptr;
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate){
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < clients.size(); i++) {
        ClientPtr client = getClient(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

bool predicateTrue(ClientPtr client){
    return client != nullptr;
}

std::vector<ClientPtr> ClientRepository::findAll(){
   return ClientRepository::findBy(predicateTrue);
}