#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
struct TestSuiteRentFixture {
    Address *adres;
    Vehicle *vehicle;
    Client *client;

    TestSuiteRentFixture() {
        adres= new Address("Lodz", "Zielona", "22");
        vehicle= new Vehicle("EL42354",100);
        client= new Client("Jan","Kowalski","12345678901",adres);
    }

    ~TestSuiteRentFixture() {
        delete adres;
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(RentConstructorTests) {
        BOOST_TEST(vehicle->isRented() == false);
        Rent rent(1,client,vehicle);
        BOOST_TEST(rent.getId() == 1);
        BOOST_TEST(rent.getClient() == client);
        BOOST_TEST(rent.getVehicle() == vehicle);
        std::string currrents = " ";
        currrents = currrents + "\n" + rent.getRentInfo();
        BOOST_TEST(vehicle->isRented() == true);
        BOOST_TEST(currrents == client->getCurrentRents());
    }

    BOOST_AUTO_TEST_CASE(RentGettersTests) {
        Rent rent(1,client,vehicle);
        BOOST_TEST(rent.getId() == 1);
        BOOST_TEST(rent.getClient() == client);
        BOOST_TEST(rent.getVehicle() == vehicle);
    }

BOOST_AUTO_TEST_SUITE_END()



