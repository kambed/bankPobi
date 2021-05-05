#include <boost/test/unit_test.hpp>
#include <model/Bicycle.h>
#include <boost/uuid/random_generator.hpp>
#include "repositories/StorageContainer.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/ClientRepository.h"
#include "typedefs.h"
struct TestSuiteContainerFixture {
    AddressPtr address = std::make_shared<Address>("Lodz","Zielona","23");
    AddressPtr address2 = std::make_shared<Address>("Warszawa","Niezielona","12");
    GoldPtr gold = std::make_shared<Gold>();
    ClientPtr client1 = std::make_shared<Client>("Anna","Nowak","98765432109",address,gold);
    ClientPtr client2 = std::make_shared<Client>("Jan","Kowalski","95435345539",address2,gold);
    ClientPtr client3 = std::make_shared<Client>("Ryszard","Kozak","11111111",address2,gold);
    BicyclePtr vehicle1 = std::make_shared<Bicycle>("EL95353",100);
    BicyclePtr vehicle2 = std::make_shared<Bicycle>("EL94234",200);
    boost::uuids::random_generator generator;
    RentPtr rent1 = std::make_shared<Rent>(generator(),client1,vehicle1,boost::posix_time::not_a_date_time,vehicle1->getBasePrice());
    RentPtr rent2 = std::make_shared<Rent>(generator(),client1,vehicle2,boost::posix_time::not_a_date_time,vehicle1->getBasePrice());
    StorageContainerPtr st = std::make_shared<StorageContainer>();
};
bool testId1(ClientPtr ptr)
{
    return ptr->getPersonalId()=="11111111";
}
BOOST_FIXTURE_TEST_SUITE(TestSuiteRepositories,TestSuiteContainerFixture)
    BOOST_AUTO_TEST_CASE(StorageVehicleRepositoryTest) {
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
    }
    BOOST_AUTO_TEST_CASE(StorageClientRepositoryTest) {
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
    }
    BOOST_AUTO_TEST_CASE(StorageRentRepositoryTest) {
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
    }
    BOOST_AUTO_TEST_CASE(PredicateTest) {
        st->getClientrepository().addClient(client2);
        st->getClientrepository().addClient(client3);
        BOOST_TEST(st->getClientrepository().findBy(testId1)[0] == client3);
        BOOST_TEST(st->getClientrepository().findAll()[2] == client2);
        BOOST_TEST(st->getClientrepository().findAll()[3] == client3);
    }
    BOOST_AUTO_TEST_SUITE_END()

