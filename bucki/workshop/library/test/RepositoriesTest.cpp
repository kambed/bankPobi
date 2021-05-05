#include <boost/test/unit_test.hpp>
#include <model/Clients/Bronze.h>
#include "repositories/StorageContainer.h"
#include "typedefs.h"
#include "model/Address.h"
#include "model/Clients/Client.h"
#include "model/Vehicles/Vehicle.h"
#include "model/Rent.h"
#include "repositories/ClientRepository.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RentRepository.h"

bool testPredicateClient(ClientPtr client) {
    return client->getFirstName() == "Jan";
}

bool testPredicateVehicle(VehiclePtr vehicle) {
    return vehicle->getPlateNumber() == "AB1234";
}

bool testPredicateRent(RentPtr rent) {
    return rent->getId() == 1;
}

BOOST_AUTO_TEST_SUITE(TestSuiteStorageContainer)

    BOOST_AUTO_TEST_CASE(StorageContainerConstructorTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(), 1);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(), 1);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(), 1);

    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestSuiteClientRepository)

    BOOST_AUTO_TEST_CASE(ClientRepositoryGetClientTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        AddressPtr address = std::make_shared<Address>("Pacanow", "Kozia", "12");
        ClientTypePtr bronze = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>("Ala", "Kot", "01010101010", address, bronze);
        storage->getClientsRepo().addClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClient(1), client);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryGetClientTooBigIdTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClient(5), nullptr);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddClientTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        AddressPtr address = std::make_shared<Address>("Pacanow", "Kozia", "12");
        ClientTypePtr bronze = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>("Ala", "Kot", "01010101010", address, bronze);
        storage->getClientsRepo().addClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(), 2);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddClientNullPtrTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        storage->getClientsRepo().addClient(nullptr);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveClientTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        AddressPtr address = std::make_shared<Address>("Pacanow", "Kozia", "12");
        ClientTypePtr bronze = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>("Ala", "Kot", "01010101010", address, bronze);
        storage->getClientsRepo().addClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(), 2);
        storage->getClientsRepo().removeClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveClientNullPtrTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        AddressPtr address = std::make_shared<Address>("Pacanow", "Kozia", "12");
        ClientTypePtr bronze = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>("Ala", "Kot", "01010101010", address, bronze);
        storage->getClientsRepo().addClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(), 2);
        storage->getClientsRepo().removeClient(nullptr);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(), 2);
    }

    BOOST_AUTO_TEST_CASE(ReportClientTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        std::string report = "";
        for (int i = 0; i < storage->getClientsRepo().getClientsSize(); i++) {
            report +=storage->getClientsRepo().getClient(i)->getClientInfo()+"\n";
        }
        BOOST_CHECK_EQUAL(storage->getClientsRepo().reportClients(), report);
    }

    BOOST_AUTO_TEST_CASE(FindByClientTest){
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        std::vector<ClientPtr> findByName;
        for (unsigned int i = 0; i < storage->getClientsRepo().getClientsSize(); i++) {
            ClientPtr client = storage->getClientsRepo().getClient(i);
            if (client != nullptr && client->getFirstName() == "Jan") {
                findByName.push_back(client);
            }
        }

        BOOST_CHECK(findByName == storage->getClientsRepo().findBy(testPredicateClient));

    }

    BOOST_AUTO_TEST_CASE(FindAllClientTest){
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        std::vector<ClientPtr> findAll;
        for(int i=0;i<storage->getClientsRepo().getClientsSize();i++){
            if(storage->getClientsRepo().getClient(i) != nullptr)
                findAll.push_back(storage->getClientsRepo().getClient(i));
        }
        BOOST_CHECK(findAll == storage->getClientsRepo().findAll());

    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestSuiteVehicleRepository)

    BOOST_AUTO_TEST_CASE(VehicleRepositoryGetVehicleTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        VehiclePtr vehicle = std::make_shared<Vehicle>("AB1234", 100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehicle(1), vehicle);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryGetVehicleTooBigIdTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehicle(5), nullptr);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryAddVehicleTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        VehiclePtr vehicle = std::make_shared<Vehicle>("AB1234", 100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(), 2);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryAddVehicleNullPtrTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        storage->getVehiclesRepo().addVehicle(nullptr);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveVehicleTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        VehiclePtr vehicle = std::make_shared<Vehicle>("AB1234", 100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(), 2);
        storage->getVehiclesRepo().removeVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveVehicleNullPtrTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        VehiclePtr vehicle = std::make_shared<Vehicle>("AB1234", 100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(), 2);
        storage->getVehiclesRepo().removeVehicle(nullptr);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(), 2);
    }

    BOOST_AUTO_TEST_CASE(ReportVehicleTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        std::string report = "";
        for (int i = 0; i < storage->getVehiclesRepo().getVehiclesSize(); i++) {
            report += storage->getVehiclesRepo().getVehicle(i)->getVehicleInfo() + "\n";
        }
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().reportVehicles(), report);
    }

    BOOST_AUTO_TEST_CASE(FindByVehicleTest){
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        std::vector<VehiclePtr> findByPlate;
        for (unsigned int i = 0; i < storage->getVehiclesRepo().getVehiclesSize(); i++) {
            VehiclePtr vehicle= storage->getVehiclesRepo().getVehicle(i);
            if (vehicle != nullptr && vehicle->getPlateNumber() == "AB1234") {
                findByPlate.push_back(vehicle);
            }
        }

        BOOST_CHECK(findByPlate == storage->getVehiclesRepo().findBy(testPredicateVehicle));

    }

    BOOST_AUTO_TEST_CASE(FindAllVEhicleTest){
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        std::vector<VehiclePtr> findAll;
        for(int i=0;i<storage->getVehiclesRepo().getVehiclesSize();i++){
            if(storage->getVehiclesRepo().getVehicle(i) != nullptr)
                findAll.push_back(storage->getVehiclesRepo().getVehicle(i));
        }
        BOOST_CHECK(findAll == storage->getVehiclesRepo().findAll());

    }


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestSuiteRentRepository)

    BOOST_AUTO_TEST_CASE(RentRepositoryGetRentTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        AddressPtr address = std::make_shared<Address>("Pacanow", "Kozia", "12");
        ClientTypePtr bronze = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>("Ala", "Kot", "01010101010", address, bronze);
        storage->getClientsRepo().addClient(client);
        VehiclePtr vehicle = std::make_shared<Vehicle>("AB1234", 100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        RentPtr rent = std::make_shared<Rent>(2, client, vehicle, boost::posix_time::second_clock::local_time());
        storage->getRentsRepo().addRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRent(1), rent);

    }

    BOOST_AUTO_TEST_CASE(RentRepositoryGetRentTooBigIdTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRent(5), nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryAddRentTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        AddressPtr address = std::make_shared<Address>("Pacanow", "Kozia", "12");
        ClientTypePtr bronze = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>("Ala", "Kot", "01010101010", address, bronze);
        storage->getClientsRepo().addClient(client);
        VehiclePtr vehicle = std::make_shared<Vehicle>("AB1234", 100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        RentPtr rent = std::make_shared<Rent>(2, client, vehicle, boost::posix_time::second_clock::local_time());
        storage->getRentsRepo().addRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(), 2);

    }

    BOOST_AUTO_TEST_CASE(RentRepositoryAddRentNullPtrTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        storage->getRentsRepo().addRent(nullptr);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryRemoveRentTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        AddressPtr address = std::make_shared<Address>("Pacanow", "Kozia", "12");
        ClientTypePtr bronze = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>("Ala", "Kot", "01010101010", address, bronze);
        storage->getClientsRepo().addClient(client);
        VehiclePtr vehicle = std::make_shared<Vehicle>("AB1234", 100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        RentPtr rent = std::make_shared<Rent>(2, client, vehicle, boost::posix_time::second_clock::local_time());
        storage->getRentsRepo().addRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(), 2);
        storage->getRentsRepo().removeRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(), 1);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryRemoveRentNullPtrTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        AddressPtr address = std::make_shared<Address>("Pacanow", "Kozia", "12");
        ClientTypePtr bronze = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>("Ala", "Kot", "01010101010", address, bronze);
        storage->getClientsRepo().addClient(client);
        VehiclePtr vehicle = std::make_shared<Vehicle>("AB1234", 100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        RentPtr rent = std::make_shared<Rent>(2, client, vehicle, boost::posix_time::second_clock::local_time());
        storage->getRentsRepo().addRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(), 2);
        storage->getRentsRepo().removeRent(nullptr);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(), 2);
    }

    BOOST_AUTO_TEST_CASE(ReportRentTest) {
        StorageContainerPtr storage = std::make_shared<StorageContainer>();
        std::string report = "";
        for (int i = 0; i < storage->getRentsRepo().getRentsSize(); i++) {
            report += storage->getRentsRepo().getRent(i)->getRentInfo() + "\n";
        }
        BOOST_CHECK_EQUAL(storage->getRentsRepo().reportRents(), report);
    }

//    BOOST_AUTO_TEST_CASE(FindByRentTest){
//        StorageContainerPtr storage = std::make_shared<StorageContainer>();
//        std::vector<RentPtr> findById;
//        for (unsigned int i = 0; i < storage->getRentsRepo().getRentsSize(); i++) {
//            RentPtr rent = storage->getRentsRepo().getRent(i);
//            if (rent != nullptr && rent->getId() == 1) {
//                findById.push_back(rent);
//            }
//        }
//
//        BOOST_CHECK(findById == storage->getRentsRepo().findBy(testPredicateRent));
//
//    }
//
//    BOOST_AUTO_TEST_CASE(FindAllRentTest){
//        StorageContainerPtr storage = std::make_shared<StorageContainer>();
//        std::vector<RentPtr> findAll;
//        for(int i=0;i<storage->getRentsRepo().getRentsSize();i++){
//            if(storage->getRentsRepo().getRent(i) != nullptr)
//                findAll.push_back(storage->getRentsRepo().getRent(i));
//        }
//        BOOST_CHECK(findAll == storage->getRentsRepo().findAll());
//
//    }

BOOST_AUTO_TEST_SUITE_END()