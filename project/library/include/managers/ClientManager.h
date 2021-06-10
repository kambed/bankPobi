#ifndef BANK_CLIENTMANAGER_H
#define BANK_CLIENTMANAGER_H

#include "typedefs.h"
#include <boost/date_time.hpp>

class ClientManager {
private:
    ClientRepositoryPtr clientRepository;
    TurboLoggerPtr turboLogger;
    TurboSaverPtr turboSaver;
public:
    ///CONSTRUCTOR

    /// \param turboLogger
    /// \param turboSaver
    ClientManager(const TurboLoggerPtr &turboLogger, const TurboSaverPtr &turboSaver);

    ///METHODS

    /// \param personalId
    /// \return ClientPtr
    ClientPtr getClient(std::string personalId);

    /// \param personalId
    /// \param firstName
    /// \param lastName
    /// \param birthDate
    void addClient(std::string personalId, std::string firstName, std::string lastName,
                   boost::posix_time::ptime birthDate);

    /// \param personalId
    /// \param newFirstName
    void changeClientFirstName(std::string personalId,std::string newFirstName);

    /// \param personalId
    /// \param newLastName
    void changeClientLastName(std::string personalId,std::string newLastName);

    /// \return std::vector<ClientPtr>
    std::vector<ClientPtr> findAll();

    /// \param predicate
    /// \return std::vector<ClientPtr>
    std::vector<ClientPtr> findClients(ClientPredicate predicate);
};


#endif //BANK_CLIENTMANAGER_H
