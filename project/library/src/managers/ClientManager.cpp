#include "managers/ClientManager.h"
#include "Client.h"
#include "typedefs.h"
#include <boost/date_time.hpp>

ClientManager::ClientManager(){
    clientRepository = std::make_shared<ClientRepository>();
}

ClientPtr ClientManager::getClient(std::string personalId) {
    return clientRepository->getClient(personalId);
}

void ClientManager::addClient(std::string personalId, std::string firstName, std::string lastName,
                              boost::posix_time::ptime birthDate) {
    if (clientRepository->getClient(personalId) == nullptr){
        ClientPtr client = std::make_shared<Client>(personalId,firstName,lastName,birthDate);
        clientRepository->addClient(client);
    }
}

std::vector<ClientPtr> ClientManager::findAll() {
    auto function = [&](const ClientPtr &ptr)->bool{return(true);};
    return clientRepository->findBy(function);
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) {
    return findClients(predicate);
}
