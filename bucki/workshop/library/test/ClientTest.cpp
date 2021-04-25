#include <boost/test/unit_test.hpp>
#include <model/clients/client.h>
#include <model/Address.h>
#include <model/Clients/Bronze.h>
#include <model/Clients/Default.h>
#include <model/Clients/Silver.h>
#include <model/Clients/Gold.h>
#include <model/Clients/Platinum.h>
#include <model/Clients/Diamond.h>
#include "typedefs.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowalski";
    const std::string testPersonalID = "12345678900";
    AddressPtr testAddress;
    ClientTypePtr bronze;

    TestSuiteClientFixture() {
        testAddress = std::make_shared<Address>("Lodz", "Politechniki", "38");
        bronze = std::make_shared<Bronze>();
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0 / 3.0 == 0.333,boost::test_tools::tolerance(0.002));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,bronze);
        BOOST_CHECK_EQUAL(client->getFirstName(),testFirstName);
        BOOST_CHECK_EQUAL(client->getLastName(),testLastName);
        BOOST_CHECK_EQUAL(client->getPersonalId(),testPersonalID);
        BOOST_CHECK_EQUAL(client->getAddress(),testAddress);
    }

    BOOST_AUTO_TEST_CASE(ClientSetFirstNameTest) {
       ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,bronze);
        client->setFirstName("Mariusz");
        BOOST_CHECK_EQUAL(client->getFirstName(),"Mariusz");
    }

    BOOST_AUTO_TEST_CASE(ClientSetEmptyFirstNameTest) {
       ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,bronze);
        client->setFirstName("");
        BOOST_CHECK_EQUAL(client->getFirstName(),"Jan");
    }

    BOOST_AUTO_TEST_CASE(ClientSetLastNameTest) {
       ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,bronze);
        client->setLastName("Nowak");
        BOOST_CHECK_EQUAL(client->getLastName(),"Nowak");
    }

    BOOST_AUTO_TEST_CASE(ClientSetEmptyLastNameTest) {
       ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,bronze);
        client->setLastName("");
        BOOST_CHECK_EQUAL(client->getLastName(),"Kowalski");
    }

    BOOST_AUTO_TEST_CASE(ClientSetEmptyAddressTest) {
       ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,bronze);
        client->setAddress(nullptr);
        BOOST_CHECK_EQUAL(client->getAddress(),testAddress);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeDefaultTest){
        ClientTypePtr type = std::make_shared<Default>();
        ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,type);
        BOOST_CHECK_EQUAL(client->getMaxVehicles(),1);
        BOOST_CHECK_EQUAL(client->applyDiscount(100),0);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeBronzeTest){
        ClientTypePtr type = std::make_shared<Bronze>();
        ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,type);
        //BOOST_CHECK_EQUAL(client->getMaxVehicles(),2);
        BOOST_CHECK_EQUAL(client->applyDiscount(100),3);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeSilverTest){
        ClientTypePtr type = std::make_shared<Silver>();
        ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,type);
        BOOST_CHECK_EQUAL(client->getMaxVehicles(),3);
        BOOST_CHECK_EQUAL(client->applyDiscount(100),6);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeGoldTest){
        ClientTypePtr type = std::make_shared<Gold>();
        ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,type);
        BOOST_CHECK_EQUAL(client->getMaxVehicles(),4);
        BOOST_CHECK_EQUAL(client->applyDiscount(100),5);
    }

    BOOST_AUTO_TEST_CASE(ClientTypePlatinumTest){
        ClientTypePtr type = std::make_shared<Platinum>();
        ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,type);
        BOOST_CHECK_EQUAL(client->getMaxVehicles(),5);
        BOOST_CHECK_EQUAL(client->applyDiscount(100),10);
    }

    BOOST_AUTO_TEST_CASE(ClientTypeDiamondTest){
        ClientTypePtr type = std::make_shared<Diamond>();
        ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress,type);
        BOOST_CHECK_EQUAL(client->getMaxVehicles(),10);
        BOOST_CHECK_EQUAL(client->applyDiscount(100),10);
        BOOST_TEST(client->applyDiscount(125.0) == 12.5,boost::test_tools::tolerance(0.01));
        BOOST_TEST(client->applyDiscount(126.0) == 25.2,boost::test_tools::tolerance(0.01));
        BOOST_CHECK_EQUAL(client->applyDiscount(250),50);
        BOOST_TEST(client->applyDiscount(251.0) == 75.3,boost::test_tools::tolerance(0.01));
        BOOST_CHECK_EQUAL(client->applyDiscount(500),150);
        BOOST_TEST(client->applyDiscount(501.0) == 200.4,boost::test_tools::tolerance(0.01));
        BOOST_CHECK_EQUAL(client->applyDiscount(1000),400);
    }

BOOST_AUTO_TEST_SUITE_END()