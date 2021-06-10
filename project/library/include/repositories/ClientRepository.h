#ifndef BANK_CLIENTREPOSITORY_H
#define BANK_CLIENTREPOSITORY_H


#include <vector>
#include "typedefs.h"

class ClientRepository {
private:
    std::vector<ClientPtr> clients;
public:
    /// CONTRUCTOR

    ClientRepository();

    /// METHODS

    /// \param personalId
    /// \return ClientPtr
    ClientPtr getClient(std::string personalId);

    /// \param client
    void addClient(ClientPtr client);

    /// \param predicate
    /// \return std::vector<ClientPtr>
    std::vector<ClientPtr> findBy(ClientPredicate predicate);
};


#endif //BANK_CLIENTREPOSITORY_H
