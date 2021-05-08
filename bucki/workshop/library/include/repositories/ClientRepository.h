#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H


#include <typedefs.h>
#include <vector>
#include <string>
#include <repositories/Repository.h>

class ClientRepository : public Repository<Client>{
private:
    std::vector<ClientPtr> clients;
public:
    /// GETTERS

    /// \param id
    /// \return
    ClientPtr getClient(unsigned int id);

    /// \return
    unsigned int getClientsSize();

    /// METHODS

    /// \param client
    void addClient(ClientPtr client);

    /// \param client
    void removeClient(ClientPtr client);

    /// \return
    const std::string reportClients() const;

    /// \param personalId
    /// \return
    ClientPtr findByPersonalId(std::string personalId);

    /// \param predicate
    /// \return
    std::vector<ClientPtr> findBy(ClientPredicate predicate);

    /// \return
    std::vector<ClientPtr> findAll();
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
