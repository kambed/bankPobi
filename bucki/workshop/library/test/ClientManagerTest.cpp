#include <boost/test/unit_test.hpp>
#include <model/clients/client.h>
#include <model/Address.h>
#include <model/Clients/Bronze.h>
#include <model/Clients/Default.h>
#include <model/Clients/Silver.h>
#include <model/Clients/Gold.h>
#include <model/Clients/Platinum.h>
#include <model/Clients/Diamond.h>
#include <model/managers/LogicContainer.h>
#include <model/managers/ClientManager.h>
#include "typedefs.h"

bool clientPredicate(ClientPtr client) {
    return client->getLastName() == "Kowalski";
}

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowalski";
    const std::string testPersonalID = "12345678900";
    AddressPtr testAddress;
    ClientTypePtr bronze;

    TestSuiteClientFixture() {
        testAddress = std::make_shared<Address>("Lodz", "Politechniki", "38");
        bronze = std::make_shared<Bronze>();
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientMananagerRegisterAndGetClientTest) {
        ClientPtr client = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testAddress, bronze);
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        BOOST_CHECK_EQUAL(logicContainer->getClientManager()->getClient(testPersonalID), nullptr);
        logicContainer->getClientManager()->registerClient(testFirstName, testLastName, testPersonalID, testAddress,
                                                           bronze);
        BOOST_CHECK_EQUAL(logicContainer->getClientManager()->getClient(testPersonalID)->getPersonalId(),
                          client->getPersonalId());
    }

    BOOST_AUTO_TEST_CASE(ClientMananagerFindClientsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        logicContainer->getClientManager()->registerClient(testFirstName, testLastName, testPersonalID, testAddress,
                                                           bronze);
        logicContainer->getClientManager()->registerClient(testFirstName, "Nowak", "11002233445", testAddress, bronze);
        BOOST_CHECK_EQUAL(logicContainer->getClientManager()->findClients(clientPredicate)[0]->getPersonalId(),
                          testPersonalID);
    }

    BOOST_AUTO_TEST_CASE(ClientMananagerFindClientsIfIsArchiveTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        logicContainer->getClientManager()->registerClient(testFirstName, testLastName, testPersonalID, testAddress,
                                                           bronze);
        logicContainer->getClientManager()->unregisterClient(testPersonalID);
        BOOST_CHECK_EQUAL(logicContainer->getClientManager()->findClients(clientPredicate).size(), 0);
    }

    BOOST_AUTO_TEST_CASE(ClientMananagerFindAllClientsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        logicContainer->getClientManager()->registerClient(testFirstName, testLastName, testPersonalID, testAddress,
                                                           bronze);
        logicContainer->getClientManager()->registerClient(testFirstName, "Nowak", "11002233445", testAddress, bronze);
        BOOST_CHECK_EQUAL(logicContainer->getClientManager()->findAllClients()[0]->getPersonalId(),
                          testPersonalID);
        BOOST_CHECK_EQUAL(logicContainer->getClientManager()->findAllClients()[1]->getPersonalId(),
                          "11002233445");
    }

BOOST_AUTO_TEST_SUITE_END()