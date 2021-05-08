#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include <memory>
#include <functors/IdPredicate.h>
#include <model/clients/Default.h>
#include <functors/FirstNamePredicate.h>
#include <functors/LastNamePredicate.h>
#include "model/managers/LogicContainer.h"
#include "model/managers/ClientManager.h"
#include "model/managers/RentManager.h"
#include "model/managers/VehicleManager.h"
#include "model/Address.h"
#include "typedefs.h"
#include "functors/IdPredicate.h"

struct TestSuiteFunctorsFixture {
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

    ClientManagerPtr clientManager = logicContainer->getClientManager();
    VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
    RentManagerPtr rentManager = logicContainer->getRentManager();

    AddressPtr address = std::make_shared<Address>("Lodz", "Politechniki", "38");
    ClientTypePtr defaultType = std::make_shared<Default>();

    ClientPtr client = clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
    VehiclePtr vehicle = vehicleManager->registerBicycle("AB1234",100);

    RentPtr rent1 = rentManager->rentVehicle(client,vehicle,now);
};

BOOST_FIXTURE_TEST_SUITE(FunctorsTest, TestSuiteFunctorsFixture)

    BOOST_AUTO_TEST_CASE(ClientIdPredicateTest) {
        IdPredicate predicate(rent1->getId());
        BOOST_CHECK_EQUAL(rentManager->findRents(predicate)[0],rent1);
    }

    BOOST_AUTO_TEST_CASE(ClientFirstNamePredicateTest) {
        FirstNamePredicate predicate2("J");
        BOOST_CHECK_EQUAL( clientManager->findClients(predicate2)[0],rent1->getClient());
    }

    BOOST_AUTO_TEST_CASE(ClientLastNamePredicateTest) {
        LastNamePredicate predicate3("K");
        BOOST_CHECK_EQUAL( clientManager->findClients(predicate3)[0],rent1->getClient());
    }


BOOST_AUTO_TEST_SUITE_END()