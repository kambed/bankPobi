#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowalski";
    const std::string testPersonalID = "12345678901";
    Address *adres;

    TestSuiteClientFixture() {
        adres= new Address("Lodz", "Zielona", "22");
    }

    ~TestSuiteClientFixture() {
        delete adres;
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        BOOST_TEST(client.getFirstName() == "Jan");
        BOOST_TEST(client.getLastName() == "Kowalski");
        BOOST_TEST(client.getPersonalId() == "12345678901");
    }

    BOOST_AUTO_TEST_CASE(FirstNameSetterTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        client.setFirstName("Mariusz");
        BOOST_TEST(client.getFirstName() == "Mariusz");
    }
    BOOST_AUTO_TEST_CASE(FirstNameSetterEmptyTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        client.setFirstName("");
        BOOST_TEST(client.getFirstName() != "");
    }
    BOOST_AUTO_TEST_CASE(LastNameSetterTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        client.setLastName("Nowak");
        BOOST_TEST(client.getLastName() == "Nowak");
    }
    BOOST_AUTO_TEST_CASE(LastNameSetterEmptyTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        client.setLastName("");
        BOOST_TEST(client.getLastName() != "");
    }

BOOST_AUTO_TEST_SUITE_END()

