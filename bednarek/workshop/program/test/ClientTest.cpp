#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
struct TestSuiteClientFixture {
    DefaultPtr defaultt = std::make_shared<Default>();
    BronzePtr bronze = std::make_shared<Bronze>();
    SilverPtr silver = std::make_shared<Silver>();
    GoldPtr gold = std::make_shared<Gold>();
    PlatinumPtr platinum = std::make_shared<Platinum>();
    DiamondPtr diamond = std::make_shared<Diamond>();
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowalski";
    const std::string testPersonalID = "12345678901";
    AddressPtr adres = std::make_shared<Address>("Lodz", "Zielona", "22");
    AddressPtr adres2 = std::make_shared<Address>("Lodz2", "Zielona2", "222");
    ClientPtr client = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,adres,gold);
    ClientPtr clientdefault = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,adres,defaultt);
    ClientPtr clientbronze = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,adres,bronze);
    ClientPtr clientsilver = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,adres,silver);
    ClientPtr clientplatinum = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,adres,platinum);
    ClientPtr clientdiamond = std::make_shared<Client>(testFirstName,testLastName,testPersonalID,adres,diamond);
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
    BOOST_AUTO_TEST_CASE(ClientDefaultDiscountTest) {
        BOOST_TEST(clientdefault->applyDiscount(100) == 100);
    }
    BOOST_AUTO_TEST_CASE(ClientDefaultMaxRentTest) {
        BOOST_TEST(clientdefault->getMaxVehicles() == 1);
    }
    BOOST_AUTO_TEST_CASE(ClientDefaultTypeTest) {
        BOOST_TEST(clientdefault->getClientInfo() == "Client:" + testFirstName + " " + testLastName + " " + testPersonalID + " " + adres->getAddressInfo() + " " + "Default");
    }
    BOOST_AUTO_TEST_CASE(ClientBronzeDiscountTest) {
        BOOST_TEST(clientbronze->applyDiscount(100) == 97);
    }
    BOOST_AUTO_TEST_CASE(ClientBronzeMaxRentTest) {
        BOOST_TEST(clientbronze->getMaxVehicles() == 2);
    }
    BOOST_AUTO_TEST_CASE(ClientBronzeTypeTest) {
        BOOST_TEST(clientbronze->getClientInfo() == "Client:" + testFirstName + " " + testLastName + " " + testPersonalID + " " + adres->getAddressInfo() + " " + "Bronze");
    }
    BOOST_AUTO_TEST_CASE(ClientSilverDiscountTest) {
        BOOST_TEST(clientsilver->applyDiscount(100) == 94);
    }
    BOOST_AUTO_TEST_CASE(ClientSilverMaxRentTest) {
        BOOST_TEST(clientsilver->getMaxVehicles() == 3);
    }
    BOOST_AUTO_TEST_CASE(ClientSilverTypeTest) {
        BOOST_TEST(clientsilver->getClientInfo() == "Client:" + testFirstName + " " + testLastName + " " + testPersonalID + " " + adres->getAddressInfo() + " " + "Silver");
    }
    BOOST_AUTO_TEST_CASE(ClientGoldDiscountTest) {
        BOOST_TEST(client->applyDiscount(100) == 95);
    }
    BOOST_AUTO_TEST_CASE(ClientGoldMaxRentTest) {
        BOOST_TEST(client->getMaxVehicles() == 4);
    }
    BOOST_AUTO_TEST_CASE(ClientGoldTypeTest) {
        BOOST_TEST(client->getClientInfo() == "Client:" + testFirstName + " " + testLastName + " " + testPersonalID + " " + adres->getAddressInfo() + " " + "Gold");
    }
    BOOST_AUTO_TEST_CASE(ClientPlatinumDiscountTest) {
        BOOST_TEST(clientplatinum->applyDiscount(100) == 90);
    }
    BOOST_AUTO_TEST_CASE(ClientPlatinumMaxRentTest) {
        BOOST_TEST(clientplatinum->getMaxVehicles() == 5);
    }
    BOOST_AUTO_TEST_CASE(ClientPlatinumTypeTest) {
        BOOST_TEST(clientplatinum->getClientInfo() == "Client:" + testFirstName + " " + testLastName + " " + testPersonalID + " " + adres->getAddressInfo() + " " + "Platinum");
    }
    BOOST_AUTO_TEST_CASE(ClientDiamondDiscountTest) {
        BOOST_TEST(clientdiamond->applyDiscount(100) == 90);
        BOOST_TEST(clientdiamond->applyDiscount(125) == 112.5);
        BOOST_TEST(clientdiamond->applyDiscount(200) == 160);
        BOOST_TEST(clientdiamond->applyDiscount(250) == 200);
        BOOST_TEST(clientdiamond->applyDiscount(300) == 210);
        BOOST_TEST(clientdiamond->applyDiscount(500) == 350);
        BOOST_TEST(clientdiamond->applyDiscount(1000) == 600);
    }
    BOOST_AUTO_TEST_CASE(ClientDiamondMaxRentTest) {
        BOOST_TEST(clientdiamond->getMaxVehicles() == 10);
    }
    BOOST_AUTO_TEST_CASE(ClientDiamondTypeTest) {
        BOOST_TEST(clientdiamond->getClientInfo() == "Client:" + testFirstName + " " + testLastName + " " + testPersonalID + " " + adres->getAddressInfo() + " " + "Diamond");
    }
    BOOST_AUTO_TEST_CASE(ClientSetTypeTest) {
        BOOST_TEST(clientdiamond->getClientInfo() == "Client:" + testFirstName + " " + testLastName + " " + testPersonalID + " " + adres->getAddressInfo() + " " + "Diamond");
        clientdiamond->setClientType(platinum);
        BOOST_TEST(clientdiamond->getClientInfo() == "Client:" + testFirstName + " " + testLastName + " " + testPersonalID + " " + adres->getAddressInfo() + " " + "Platinum");
        BOOST_TEST(clientdiamond->getMaxVehicles() == 5);
        BOOST_TEST(clientdiamond->applyDiscount(100) == 90);

    }


BOOST_AUTO_TEST_SUITE_END()

