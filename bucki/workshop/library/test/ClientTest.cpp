#include <boost/test/unit_test.hpp>
#include <model/client.h>
#include <model/Address.h>
#include "typedefs.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowalski";
    const std::string testPersonalID = "12345678900";
    AddressPtr testAddress;

    TestSuiteClientFixture() {
        testAddress = new Address("Lodz", "Politechniki", "38");
    }

    ~TestSuiteClientFixture() {
        delete testAddress;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0 / 3.0 == 0.333,boost::test_tools::tolerance(0.002));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        ClientPtr client = new Client(testFirstName,testLastName,testPersonalID,testAddress);
        BOOST_CHECK_EQUAL(client->getFirstName(),testFirstName);
        BOOST_CHECK_EQUAL(client->getLastName(),testLastName);
        BOOST_CHECK_EQUAL(client->getPersonalId(),testPersonalID);
        BOOST_CHECK_EQUAL(client->getAddress(),testAddress);
    }

    BOOST_AUTO_TEST_CASE(ClientSetFirstNameTest) {
       ClientPtr client = new Client(testFirstName,testLastName,testPersonalID,testAddress);
        client->setFirstName("Mariusz");
        BOOST_CHECK_EQUAL(client->getFirstName(),"Mariusz");
    }

    BOOST_AUTO_TEST_CASE(ClientSetEmptyFirstNameTest) {
       ClientPtr client = new Client(testFirstName,testLastName,testPersonalID,testAddress);
        client->setFirstName("");
        BOOST_CHECK_EQUAL(client->getFirstName(),"Jan");
    }

    BOOST_AUTO_TEST_CASE(ClientSetLastNameTest) {
       ClientPtr client = new Client(testFirstName,testLastName,testPersonalID,testAddress);
        client->setLastName("Nowak");
        BOOST_CHECK_EQUAL(client->getLastName(),"Nowak");
    }

    BOOST_AUTO_TEST_CASE(ClientSetEmptyLastNameTest) {
       ClientPtr client = new Client(testFirstName,testLastName,testPersonalID,testAddress);
        client->setLastName("");
        BOOST_CHECK_EQUAL(client->getLastName(),"Kowalski");
    }

    BOOST_AUTO_TEST_CASE(ClientSetEmptyAddressTest) {
       ClientPtr client = new Client(testFirstName,testLastName,testPersonalID,testAddress);
        client->setAddress(nullptr);
        BOOST_CHECK_EQUAL(client->getAddress(),testAddress);
    }

BOOST_AUTO_TEST_SUITE_END()