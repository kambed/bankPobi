#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"
#include "typedefs.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "repositories/ClientRepository.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RentRepository.h"

BOOST_AUTO_TEST_SUITE(TestSuiteStorageContainer)

    BOOST_AUTO_TEST_CASE(StorageContainerConstructorTest){
        StorageContainerPtr storage = new StorageContainer();
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(),1);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(),1);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(),1);
        delete storage;
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestSuiteClientRepository)

    BOOST_AUTO_TEST_CASE(ClientRepositoryGetClientTest){
        StorageContainerPtr storage = new StorageContainer();
        AddressPtr address = new Address("Pacanow","Kozia","12");
        ClientPtr client = new Client("Ala","Kot","01010101010",address);
        storage->getClientsRepo().addClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClient(1),client);
        delete client;
        delete address;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryGetClientTooBigIdTest){
        StorageContainerPtr storage = new StorageContainer();
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClient(5),nullptr);
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddClientTest){
        StorageContainerPtr storage = new StorageContainer();
        AddressPtr address = new Address("Pacanow","Kozia","12");
        ClientPtr client = new Client("Ala","Kot","01010101010",address);
        storage->getClientsRepo().addClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(),2);
        delete client;
        delete address;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddClientNullPtrTest){
        StorageContainerPtr storage = new StorageContainer();
        storage->getClientsRepo().addClient(nullptr);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(),1);
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveClientTest){
        StorageContainerPtr storage = new StorageContainer();
        AddressPtr address = new Address("Pacanow","Kozia","12");
        ClientPtr client = new Client("Ala","Kot","01010101010",address);
        storage->getClientsRepo().addClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(),2);
        storage->getClientsRepo().removeClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(),1);
        delete client;
        delete address;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveClientNullPtrTest){
        StorageContainerPtr storage = new StorageContainer();
        AddressPtr address = new Address("Pacanow","Kozia","12");
        ClientPtr client = new Client("Ala","Kot","01010101010",address);
        storage->getClientsRepo().addClient(client);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(),2);
        storage->getClientsRepo().removeClient(nullptr);
        BOOST_CHECK_EQUAL(storage->getClientsRepo().getClientsSize(),2);
        delete client;
        delete address;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(ReportClientTest){
        StorageContainerPtr storage = new StorageContainer();
        std::string report = "";
        for(int i=0;i<storage->getClientsRepo().getClientsSize();i++){
            report += storage->getClientsRepo().getClient(i)->getClientInfo() + "\n";
        }
        BOOST_CHECK_EQUAL(storage->getClientsRepo().reportClients(),report);
        delete storage;
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestSuiteVehicleRepository)

    BOOST_AUTO_TEST_CASE(VehicleRepositoryGetVehicleTest){
        StorageContainerPtr storage = new StorageContainer();
        VehiclePtr vehicle = new Vehicle("AB1234",100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehicle(1),vehicle);
        delete vehicle;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryGetVehicleTooBigIdTest){
        StorageContainerPtr storage = new StorageContainer();
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehicle(5),nullptr);
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryAddVehicleTest){
        StorageContainerPtr storage = new StorageContainer();
        VehiclePtr vehicle = new Vehicle("AB1234",100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(),2);
        delete vehicle;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryAddVehicleNullPtrTest){
        StorageContainerPtr storage = new StorageContainer();
        storage->getVehiclesRepo().addVehicle(nullptr);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(),1);
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveVehicleTest){
        StorageContainerPtr storage = new StorageContainer();
        VehiclePtr vehicle = new Vehicle("AB1234",100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(),2);
        storage->getVehiclesRepo().removeVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(),1);
        delete vehicle;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveVehicleNullPtrTest){
        StorageContainerPtr storage = new StorageContainer();
        VehiclePtr vehicle = new Vehicle("AB1234",100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(),2);
        storage->getVehiclesRepo().removeVehicle(nullptr);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(),2);
        delete vehicle;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(ReportVehicleTest){
        StorageContainerPtr storage = new StorageContainer();
        std::string report = "";
        for(int i=0;i<storage->getVehiclesRepo().getVehiclesSize();i++){
            report += storage->getVehiclesRepo().getVehicle(i)->getVehicleInfo() + "\n";
        }
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().reportVehicles(),report);
        delete storage;
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestSuiteRentRepository)

    BOOST_AUTO_TEST_CASE(RentRepositoryGetRentTest){
        StorageContainerPtr storage = new StorageContainer();
        AddressPtr address = new Address("Pacanow","Kozia","12");
        ClientPtr client = new Client("Ala","Kot","01010101010",address);
        storage->getClientsRepo().addClient(client);
        VehiclePtr vehicle = new Vehicle("AB1234",100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        RentPtr rent = new Rent(2,client,vehicle,boost::posix_time::second_clock::local_time());
        storage->getRentsRepo().addRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRent(1),rent);
        delete address;
        delete client;
        delete vehicle;
        delete rent;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryGetRentTooBigIdTest){
        StorageContainerPtr storage = new StorageContainer();
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRent(5),nullptr);
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryAddRentTest){
        StorageContainerPtr storage = new StorageContainer();
        AddressPtr address = new Address("Pacanow","Kozia","12");
        ClientPtr client = new Client("Ala","Kot","01010101010",address);
        storage->getClientsRepo().addClient(client);
        VehiclePtr vehicle = new Vehicle("AB1234",100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        RentPtr rent = new Rent(2,client,vehicle,boost::posix_time::second_clock::local_time());
        storage->getRentsRepo().addRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(),2);
        delete address;
        delete client;
        delete vehicle;
        delete rent;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryAddRentNullPtrTest){
        StorageContainerPtr storage = new StorageContainer();
        storage->getRentsRepo().addRent(nullptr);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(),1);
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryRemoveRentTest){
        StorageContainerPtr storage = new StorageContainer();
        AddressPtr address = new Address("Pacanow","Kozia","12");
        ClientPtr client = new Client("Ala","Kot","01010101010",address);
        storage->getClientsRepo().addClient(client);
        VehiclePtr vehicle = new Vehicle("AB1234",100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        RentPtr rent = new Rent(2,client,vehicle,boost::posix_time::second_clock::local_time());
        storage->getRentsRepo().addRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(),2);
        storage->getRentsRepo().removeRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(),1);
        delete address;
        delete client;
        delete vehicle;
        delete rent;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryRemoveRentNullPtrTest){
        StorageContainerPtr storage = new StorageContainer();
        AddressPtr address = new Address("Pacanow","Kozia","12");
        ClientPtr client = new Client("Ala","Kot","01010101010",address);
        storage->getClientsRepo().addClient(client);
        VehiclePtr vehicle = new Vehicle("AB1234",100);
        storage->getVehiclesRepo().addVehicle(vehicle);
        RentPtr rent = new Rent(2,client,vehicle,boost::posix_time::second_clock::local_time());
        storage->getRentsRepo().addRent(rent);
        BOOST_CHECK_EQUAL(storage->getRentsRepo().getRentsSize(),2);
        storage->getRentsRepo().removeRent(nullptr);
        BOOST_CHECK_EQUAL(storage->getVehiclesRepo().getVehiclesSize(),2);
        delete address;
        delete client;
        delete vehicle;
        delete rent;
        delete storage;
    }

    BOOST_AUTO_TEST_CASE(ReportRentTest){
        StorageContainerPtr storage = new StorageContainer();
        std::string report = "";
        for(int i=0;i<storage->getRentsRepo().getRentsSize();i++){
            report += storage->getRentsRepo().getRent(i)->getRentInfo() + "\n";
        }
        BOOST_CHECK_EQUAL(storage->getRentsRepo().reportRents(),report);
        delete storage;
    }

BOOST_AUTO_TEST_SUITE_END()