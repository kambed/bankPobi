#include <boost/test/unit_test.hpp>
#include <model/Bicycle.h>
#include "repositories/StorageContainer.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/ClientRepository.h"
#include "typedefs.h"
struct TestSuiteContainerFixture {
    Address *address = new Address("Lodz","Zielona","23");
    Address *address2 = new Address("Warszawa","Niezielona","12");
    Client *client1 = new Client("Anna","Nowak","98765432109",address);
    Client *client2 = new Client("Jan","Kowalski","95435345539",address2);
    Client *client3 = new Client("Ryszard","Kozak","11111111",address2);
    Bicycle *vehicle1 = new Bicycle("EL95353",100);
    Bicycle *vehicle2 = new Bicycle("EL94234",200);
    Rent *rent1 = new Rent(1,client1,vehicle1,boost::posix_time::not_a_date_time,vehicle1->getBasePrice());
    Rent *rent2 = new Rent(2,client1,vehicle2,boost::posix_time::not_a_date_time,vehicle1->getBasePrice());
};
bool testId1(ClientPtr ptr)
{
    return ptr->getPersonalId()=="11111111";
}
BOOST_FIXTURE_TEST_SUITE(TestSuiteRepositories,TestSuiteContainerFixture)
    BOOST_AUTO_TEST_CASE(StorageVehicleRepositoryTest) {
        StorageContainer* st = new StorageContainer();
        BOOST_TEST(st->getVehiclerepository().sizeVehicle() == 11);
        st->getVehiclerepository().addVehicle(vehicle2);
        BOOST_TEST(st->getVehiclerepository().sizeVehicle() == 12);
        BOOST_TEST(st->getVehiclerepository().getVehicle(11) == vehicle2);
        st->getVehiclerepository().removeVehicle(vehicle2);
        BOOST_TEST(st->getVehiclerepository().sizeVehicle() == 11);
        BOOST_TEST(st->getVehiclerepository().getVehicle(11) == nullptr);
        st->getVehiclerepository().addVehicle(nullptr);
        BOOST_TEST(st->getVehiclerepository().sizeVehicle() == 11);
        st->getVehiclerepository().removeVehicle(nullptr);
        BOOST_TEST(st->getVehiclerepository().sizeVehicle() == 11);
        delete st;
    }
    BOOST_AUTO_TEST_CASE(StorageClientRepositoryTest) {
        StorageContainer* st = new StorageContainer();
        BOOST_TEST(st->getClientrepository().sizeClient() == 2);
        st->getClientrepository().addClient(client2);
        BOOST_TEST(st->getClientrepository().sizeClient() == 3);
        BOOST_TEST(st->getClientrepository().getClient(2) == client2);
        st->getClientrepository().removeClient(client2);
        BOOST_TEST(st->getClientrepository().sizeClient() == 2);
        BOOST_TEST(st->getClientrepository().getClient(2) == nullptr);
        st->getClientrepository().addClient(nullptr);
        BOOST_TEST(st->getClientrepository().sizeClient() == 2);
        st->getClientrepository().removeClient(nullptr);
        BOOST_TEST(st->getClientrepository().sizeClient() == 2);
        delete st;
    }
    BOOST_AUTO_TEST_CASE(StorageRentRepositoryTest) {
        StorageContainer* st = new StorageContainer();
        BOOST_TEST(st->getRentrepository().sizeRent() == 1);
        st->getRentrepository().addRent(rent2);
        BOOST_TEST(st->getRentrepository().sizeRent() == 2);
        BOOST_TEST(st->getRentrepository().getRent(1) == rent2);
        st->getRentrepository().removeRent(rent2);
        BOOST_TEST(st->getRentrepository().sizeRent() == 1);
        BOOST_TEST(st->getRentrepository().getRent(1) == nullptr);
        st->getRentrepository().addRent(nullptr);
        BOOST_TEST(st->getRentrepository().sizeRent() == 1);
        st->getRentrepository().removeRent(nullptr);
        BOOST_TEST(st->getRentrepository().sizeRent() == 1);
        delete st;
    }
    BOOST_AUTO_TEST_CASE(PredicateTest) {
        StorageContainer* st = new StorageContainer();
        st->getClientrepository().addClient(client2);
        st->getClientrepository().addClient(client3);
        BOOST_TEST(st->getClientrepository().findBy(testId1)[0] == client3);
        BOOST_TEST(st->getClientrepository().findAll()[2] == client2);
        BOOST_TEST(st->getClientrepository().findAll()[3] == client3);
    }
    BOOST_AUTO_TEST_SUITE_END()

