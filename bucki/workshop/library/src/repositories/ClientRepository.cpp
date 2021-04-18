#include <algorithm>
#include "repositories/ClientRepository.h"
#include "model/Client.h"
#include "typedefs.h"

ClientPtr ClientRepository::getClient(unsigned int id) const{
    if(clients.size()-1<id)
    return nullptr;
    if(clients.at(id) == nullptr)
        return nullptr;
    return clients.at(id);
}

void ClientRepository::addClient(ClientPtr client){
    if(client != nullptr)
        clients.push_back(client);
}

void ClientRepository::removeClient(ClientPtr client){
    if(client != nullptr)
        clients.erase(std::remove(clients.begin(), clients.end(), client));
}

const std::string ClientRepository::reportClients() const{
    std::string report;
//    for(int i=0;i<client->getCurrentRents().size();i++)
//        report += client->getCurrentRents()[i]->getRentInfo() + "/n";
//    return report;
    for(int i=0;i<clients.size();i++)
        report += clients[i]->getClientInfo() + "\n";
    return report;
}

unsigned int ClientRepository::getClientsSize(){
    return clients.size();
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < clients.size(); i++) {
        ClientPtr client = getClient(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

std::vector<ClientPtr> ClientRepository::findAll() const{
   return ClientRepository::findBy(reinterpret_cast<ClientPredicate>(true));
}