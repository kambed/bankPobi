#ifndef BANK_CLIENTREPOSITORY_H
#define BANK_CLIENTREPOSITORY_H


#include <vector>
#include "typedefs.h"

class ClientRepository {
private:
    std::vector<ClientPtr> clients;
public:
    ///CONTRUCTOR
    ClientRepository();
    ///METHODS

    ClientPtr getClient(std::string personalId);

    void addClient(ClientPtr client);

    std::vector<ClientPtr> findBy(ClientPredicate predicate);
};


#endif //BANK_CLIENTREPOSITORY_H
