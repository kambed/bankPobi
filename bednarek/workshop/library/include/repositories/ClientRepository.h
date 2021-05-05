//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include "../model/Client.h"
#include "../typedefs.h"
#include <string>
#include <vector>
#include "repositories/Repository.h"

class ClientRepository : public Repository<Client>{
private:
    std::vector<ClientPtr> Clients;
public:
    ClientPtr getClient(int clientIndex) const;
    void addClient(ClientPtr client);
    void removeClient(ClientPtr client);
    std::string reportClient() const;
    int sizeClient() const;
    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;
    std::vector<ClientPtr> findAll();
    ClientPtr findByPersonalId(std::string Id);
    template<class P> std::vector<ClientPtr> findAllNew(const P &predicate) const
    {
        std::vector<ClientPtr> result;
        for(int i = 0; i<Clients.size(); ++i)
        {
            ClientPtr client = Clients[i];
            if(predicate(client))
            {
                result.push_back(client);
            }
        }
        return result;
    }
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
