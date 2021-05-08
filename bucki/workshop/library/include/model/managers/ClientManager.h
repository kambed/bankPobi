#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H


#include "typedefs.h"
#include <vector>

class ClientManager {
private:
    ClientRepositoryPtr clientRepository;
public:
    /// CONSTRUCTOR
    ClientManager();

    /// GETTERS

    /// \param personalId
    /// \return
    ClientPtr getClient(std::string personalId);

    ///METHODS

    /// \param firstName
    /// \param lastName
    /// \param personalID
    /// \param adres
    /// \param clientType
    /// \return
    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr adres,
                             ClientTypePtr clientType);

    /// \param personalId
    void unregisterClient(std::string personalId);

    /// \param predicate
    /// \return
    std::vector<ClientPtr> findClients(ClientPredicate predicate) const;

    /// \return
    std::vector<ClientPtr> findAllClients() const;
};


#endif //CARRENTAL_CLIENTMANAGER_H
