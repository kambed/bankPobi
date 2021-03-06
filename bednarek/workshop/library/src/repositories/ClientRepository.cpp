//
// Created by student on 18.04.2021.
//

#include "repositories/ClientRepository.h"
#include <vector>
//CONSTRUCTOR
ClientPtr ClientRepository::getClient(int clientIndex) const{
    if(Clients.size()>clientIndex)
    {
        return Clients[clientIndex];
    }
    else
    {
        return nullptr;
    }
}
void ClientRepository::addClient(ClientPtr client) {
    if(client!=nullptr){
        Clients.push_back(client);
    }
}
void ClientRepository::removeClient(ClientPtr client) {
    if(client!=nullptr){
        Clients.erase(std::remove(Clients.begin(),Clients.end(),client));
    }
}
std::string ClientRepository::reportClient() const{
    std::string rentlist=" ";
    for(int i=0;i<Clients.size();i++)
    {
        rentlist=rentlist + "\n" + Clients[i]->getClientInfo();
    }
    return rentlist;
}
int ClientRepository::sizeClient() const{
    return Clients.size();
}
std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < Clients.size(); i++) {
        ClientPtr client = Clients[i];
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}
bool testTrue(ClientPtr ptr)
{
    return ptr != nullptr;
}
std::vector<ClientPtr> ClientRepository::findAll() {
    return findBy(testTrue);
}
ClientPtr ClientRepository::findByPersonalId(std::string ID) {
    for(int i=0;i<Clients.size();i++)
    {
        if(Clients[i]->getPersonalId()==ID)
        {
            ClientPtr client = Clients[i];
            return client;
        }
    }
    return nullptr;
}
