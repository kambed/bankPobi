#include <boost/test/unit_test.hpp>
#include <typedefs.h>
#include <managers/ClientManager.h>
#include "model/Address.h"
struct TestSuiteClientManagerFixture {
    ClientManager clientmanager;
    AddressPtr adres = std::make_shared<Address>("Lodz","Zielona","23");
    GoldPtr gold = std::make_shared<Gold>();
};
bool predicateTest(ClientPtr ptr)
{
    return ptr->getPersonalId()=="123123123";
}
BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager,TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ClientManagerTests) {
        BOOST_TEST(clientmanager.getClient("123123123")==nullptr);
        clientmanager.registerClient("Anna","Nowak","123123123",adres,gold);
        BOOST_TEST(clientmanager.getClient("123123123")!=nullptr);
        BOOST_TEST(clientmanager.getClient("123123123")->getPersonalId()=="123123123");
        BOOST_TEST(clientmanager.getClient("123123123")->getFirstName()=="Anna");
        BOOST_TEST(clientmanager.getClient("123123123")->getLastName()=="Nowak");
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==4);
    }
    BOOST_AUTO_TEST_CASE(ClientunRegisterTests) {
        clientmanager.registerClient("Anna","Nowak","123123123",adres,gold);
        clientmanager.unregisterClient(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getPersonalId()=="123123123");
        BOOST_TEST(clientmanager.getClient("123123123")->getFirstName()=="Anna");
        BOOST_TEST(clientmanager.getClient("123123123")->getLastName()=="Nowak");
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==4);
        BOOST_TEST(clientmanager.getClient("123123123")->isArchive()==true);
    }
    BOOST_AUTO_TEST_CASE(ClientfindTests) {
        clientmanager.registerClient("Anna","Nowak","123123123",adres,gold);
        BOOST_TEST(clientmanager.findClients(predicateTest)[0]->getPersonalId()=="123123123");
        clientmanager.unregisterClient(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.findClients(predicateTest).size()==0);
        BOOST_TEST(clientmanager.findAllClients().size()==0);
        clientmanager.registerClient("Anna","Nowak","12314223123",adres,gold);
        BOOST_TEST(clientmanager.findAllClients().size()==1);
        BOOST_TEST(clientmanager.findAllClients()[0]->getPersonalId()=="12314223123");
    }
BOOST_AUTO_TEST_SUITE_END()

