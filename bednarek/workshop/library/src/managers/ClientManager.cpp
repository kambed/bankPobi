//
// Created by student on 25.04.2021.
//

#include "managers/ClientManager.h"

ClientPtr ClientManager::getClient(std::string Id) {
    return clientRepository.findByPersonalId(Id);
}
ClientPtr ClientManager::registerClient(std::string firstName, std::string lastName, std::string PersonalId, AddressPtr address,ClientTypePtr clientType) {
    if(clientRepository.findByPersonalId(PersonalId)==nullptr)
    {
        ClientPtr client = std::make_shared<Client>(firstName,lastName,PersonalId,address,clientType);
        clientRepository.addClient(client);
        return clientRepository.findByPersonalId(PersonalId);
    }
    else
    {
        return clientRepository.findByPersonalId(PersonalId);
    }
}

void ClientManager::unregisterClient(ClientPtr client) {
    if(clientRepository.findByPersonalId(client->getPersonalId())!=nullptr)
    {
        client->setArchive(true);
    }
}
std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) const {
    auto function = [&](const ClientPtr &ptr)->bool{return(predicate(ptr)&&!ptr->isArchive());};
    return clientRepository.findBy(function);
}
bool predicateTrue(ClientPtr ptr)
{
    return ptr != nullptr;
}
std::vector<ClientPtr> ClientManager::findAllClients() const {
    auto function = [&](const ClientPtr &ptr)->bool{return(predicateTrue(ptr)&&!ptr->isArchive());};
    return clientRepository.findBy(function);
}
