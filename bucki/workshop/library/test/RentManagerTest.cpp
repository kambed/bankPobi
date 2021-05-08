#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include <memory>
#include <model/clients/Bronze.h>
#include "model/Rent.h"
#include "model/clients/Client.h"
#include "model/vehicles/Vehicle.h"
#include "model/clients/Default.h"
#include "model/vehicles/Bicycle.h"
#include "model/managers/LogicContainer.h"
#include "model/managers/ClientManager.h"
#include "model/managers/VehicleManager.h"
#include "model/managers/RentManager.h"
#include "typedefs.h"

bool rentPredicate(RentPtr rent) {
    return rent->getClient()->getFirstName() == "Jan";
}

struct TestSuiteRentManagerTestFixture {
    AddressPtr address;
    VehiclePtr vehicle;
    ClientPtr client;
    ClientTypePtr defaultType;

    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();

    boost::uuids::random_generator generator;

    TestSuiteRentManagerTestFixture() {
        address = std::make_shared<Address>("Lodz", "Politechniki", "38");
        defaultType = std::make_shared<Default>();
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManagerTest, TestSuiteRentManagerTestFixture)

    BOOST_AUTO_TEST_CASE(RentManagerGetAllClientRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicleManager->registerBicycle("AB1234",100);
        rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),
                                 now);

        BOOST_TEST(rentManager->getAllClientRents(clientManager->getClient("12345678900")).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentManagerGetVehicleRentRentsTest) {
            LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

            ClientManagerPtr clientManager = logicContainer->getClientManager();
            VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
            RentManagerPtr rentManager = logicContainer->getRentManager();

            clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
            vehicleManager->registerBicycle("AB1234",100);
            rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),
            now);

            BOOST_TEST(rentManager->getVehicleRent(vehicleManager->getVehicle("AB1234")) ==
            rentManager->findAllRents()[0]);
    }

    BOOST_AUTO_TEST_CASE(ManagerFindRentsTest) {
            LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

            ClientManagerPtr clientManager = logicContainer->getClientManager();
            VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
            RentManagerPtr rentManager = logicContainer->getRentManager();

            clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
            vehicleManager->registerBicycle("AB1234",100);
            rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),
            now);

            BOOST_TEST(rentManager->findRents(rentPredicate)[0]->getClient()->getFirstName() == "Jan");
    }

    BOOST_AUTO_TEST_CASE(ManagerFindAllRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        clientManager->registerClient("Adam", "Nowak", "98765432100", address, defaultType);
        vehicleManager->registerBicycle("AB1234",100);
        vehicleManager->registerBicycle("CD5678",200);

        rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),
                                now);
        rentManager->rentVehicle(2,clientManager->getClient("98765432100"),vehicleManager->getVehicle("CD5678"),
                                 now);

        BOOST_TEST(rentManager->findAllRents().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RentManagerCheckClientRentBalanceRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicleManager->registerBicycle("AB1234",10);

        rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),now -
                                                                                                                boost::posix_time::hours(48));
        rentManager->returnVehicle(vehicleManager->getVehicle("AB1234"),now-boost::posix_time::hours(25));
        rentManager->rentVehicle(2,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),now -
                                                                                                                boost::posix_time::hours(20));
        rentManager->returnVehicle(vehicleManager->getVehicle("AB1234"),now);

        BOOST_CHECK_EQUAL(rentManager->checkClientRentBalance(clientManager->getClient("12345678900")),20);
    }

    BOOST_AUTO_TEST_CASE(ManagerCheckClientRentsRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicleManager->registerBicycle("AB1234",100);
        rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),
                                now-boost::posix_time::hours(16));

        BOOST_TEST(rentManager->checkClientRentBalance(clientManager->getClient("12345678900")) == 0);

        rentManager->returnVehicle(vehicleManager->getVehicle("AB1234"),now);

        BOOST_TEST(rentManager->checkClientRentBalance(clientManager->getClient("12345678900")) == 100);
    }

    BOOST_AUTO_TEST_CASE(RentManagerRentVehicleRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicleManager->registerBicycle("AB1234",100);
        BOOST_CHECK_EQUAL(rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),
                                now)->getVehicle(),vehicleManager->getVehicle("AB1234"));
    }

    BOOST_AUTO_TEST_CASE(RentManagerRentVehicleArchivalVehicleRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicleManager->registerBicycle("AB1234",100);
        vehicleManager->unregisterVehicle("AB1234");
        BOOST_CHECK_EQUAL(rentManager->rentVehicle(1,clientManager->getClient("12345678900"),
                                                    vehicleManager->getVehicle("AB1234"),now),nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentManagerRentVehicleArchivalClientRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicleManager->registerBicycle("AB1234",100);
        clientManager->unregisterClient("12345678900");
        BOOST_CHECK_EQUAL(rentManager->rentVehicle(1,clientManager->getClient("12345678900"),
                                                    vehicleManager->getVehicle("AB1234"),now),nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentManagerChangeClientTypeRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicleManager->registerBicycle("AB1234",100);
        rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),now-
                                                                                                                boost::posix_time::hours(25));
        rentManager->returnVehicle(vehicleManager->getVehicle("AB1234"),now);
        rentManager->changeClientType(clientManager->getClient("12345678900"));
        BOOST_CHECK_EQUAL(clientManager->getClient("12345678900")->applyDiscount(100),6.0);
        BOOST_CHECK_EQUAL(clientManager->getClient("12345678900")->getMaxVehicles(),3);
    }

    BOOST_AUTO_TEST_CASE(RentManagerChangeClientTypeByReturnVehicleRentsTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

        ClientManagerPtr clientManager = logicContainer->getClientManager();
        VehicleManagerPtr vehicleManager = logicContainer->getVehicleManager();
        RentManagerPtr rentManager = logicContainer->getRentManager();

        clientManager->registerClient("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicleManager->registerBicycle("AB1234",100);

        rentManager->rentVehicle(1,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),now-
                                                                                                                boost::posix_time::hours(49));
        rentManager->returnVehicle(vehicleManager->getVehicle("AB1234"),now-boost::posix_time::hours(24));

        rentManager->rentVehicle(2,clientManager->getClient("12345678900"),vehicleManager->getVehicle("AB1234"),now-
                                                                                                                boost::posix_time::hours(2));
        rentManager->returnVehicle(vehicleManager->getVehicle("AB1234"),now);
        BOOST_CHECK_EQUAL(clientManager->getClient("12345678900")->applyDiscount(100),6.0);
        BOOST_CHECK_EQUAL(clientManager->getClient("12345678900")->getMaxVehicles(),3);
    }

BOOST_AUTO_TEST_SUITE_END()
