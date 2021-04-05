#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowalski";
    const std::string testPersonalID = "12345678901";
    Address *adres;
    Address *adres2;

    TestSuiteClientFixture() {
        adres= new Address("Lodz", "Zielona", "22");
        adres2= new Address("Lodz2", "Zielona2", "222");
    }

    ~TestSuiteClientFixture() {
        delete adres;
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        BOOST_TEST(client.getFirstName() == testFirstName);
        BOOST_TEST(client.getLastName() == testLastName);
        BOOST_TEST(client.getPersonalId() == testPersonalID);
        BOOST_TEST(client.getAddress() == adres);
        BOOST_TEST(client.getCurrentRents() == " ");
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
    BOOST_AUTO_TEST_CASE(FirstNameGetterTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        BOOST_TEST(client.getFirstName() == testFirstName);
    }
    BOOST_AUTO_TEST_CASE(LastNameGetterTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        BOOST_TEST(client.getLastName() == testLastName);
    }
    BOOST_AUTO_TEST_CASE(PersonalIDGetterTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        BOOST_TEST(client.getPersonalId() == testPersonalID);
    }
    BOOST_AUTO_TEST_CASE(AddressSetterTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        client.setAddress(adres2);
        BOOST_TEST(client.getAddress() == adres2);
    }
    BOOST_AUTO_TEST_CASE(AddressSetterEmptyTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        client.setAddress(nullptr);
        BOOST_TEST(client.getAddress() != nullptr);
    }
    BOOST_AUTO_TEST_CASE(AddressGetterTests) {
        Client client(testFirstName,testLastName,testPersonalID, adres);
        BOOST_TEST(client.getAddress() == adres);
    }

BOOST_AUTO_TEST_SUITE_END()

