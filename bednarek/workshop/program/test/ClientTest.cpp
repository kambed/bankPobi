#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowalski";
    const std::string testPersonalID = "12345678901";
    AddressPtr adres = std::make_shared<Address>("Lodz", "Zielona", "22");
    AddressPtr adres2 = std::make_shared<Address>("Lodz2", "Zielona2", "222");
    ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID, adres);
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTests) {
        BOOST_TEST(client->getFirstName() == testFirstName);
        BOOST_TEST(client->getLastName() == testLastName);
        BOOST_TEST(client->getPersonalId() == testPersonalID);
        BOOST_TEST(client->getAddress() == adres);
        std::vector<Rent *> testRents;
        //BOOST_TEST(client->getCurrentRents() == testRents);
    }

    BOOST_AUTO_TEST_CASE(FirstNameSetterTests) {
        client->setFirstName("Mariusz");
        BOOST_TEST(client->getFirstName() == "Mariusz");
    }
    BOOST_AUTO_TEST_CASE(FirstNameSetterEmptyTests) {
        client->setFirstName("");
        BOOST_TEST(client->getFirstName() != "");
    }
    BOOST_AUTO_TEST_CASE(LastNameSetterTests) {
        client->setLastName("Nowak");
        BOOST_TEST(client->getLastName() == "Nowak");
    }
    BOOST_AUTO_TEST_CASE(LastNameSetterEmptyTests) {
        client->setLastName("");
        BOOST_TEST(client->getLastName() != "");
    }
    BOOST_AUTO_TEST_CASE(FirstNameGetterTests) {
        BOOST_TEST(client->getFirstName() == testFirstName);
    }
    BOOST_AUTO_TEST_CASE(LastNameGetterTests) {
        BOOST_TEST(client->getLastName() == testLastName);
    }
    BOOST_AUTO_TEST_CASE(PersonalIDGetterTests) {
        BOOST_TEST(client->getPersonalId() == testPersonalID);
    }
    BOOST_AUTO_TEST_CASE(AddressSetterTests) {
        client->setAddress(adres2);
        BOOST_TEST(client->getAddress() == adres2);
    }
    BOOST_AUTO_TEST_CASE(AddressSetterEmptyTests) {
        client->setAddress(nullptr);
        BOOST_TEST(client->getAddress() != nullptr);
    }
    BOOST_AUTO_TEST_CASE(AddressGetterTests) {
        BOOST_TEST(client->getAddress() == adres);
    }

BOOST_AUTO_TEST_SUITE_END()

