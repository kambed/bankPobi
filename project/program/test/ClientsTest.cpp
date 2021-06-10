#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/TurboSaver.h"
struct TestSuiteClientFixture {
    TurboSaverPtr turboSaver = std::make_shared<TurboSaver>();
    ClientPtr client = std::make_shared<Client>("54321123456","Marcin","Nowak",boost::posix_time::ptime
    (boost::gregorian::date(2000,5,13)));
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient,TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTests) {
        BOOST_TEST(client->getFirstName()=="Marcin");
        BOOST_TEST(client->getLastName()=="Nowak");
        BOOST_TEST(client->getPersonalId()=="54321123456");
        BOOST_TEST(client->getBirthDate()==boost::posix_time::ptime(boost::gregorian::date(2000,5,13)));
    }
    BOOST_AUTO_TEST_CASE(SettersAndGettersTests) {
        BOOST_TEST(client->getFirstName()=="Marcin");
        BOOST_TEST(client->getLastName()=="Nowak");
        BOOST_TEST(client->getPersonalId()=="54321123456");
        BOOST_TEST(client->getBirthDate()==boost::posix_time::ptime(boost::gregorian::date(2000,5,13)));
        client->changeFirstName("Michal");
        BOOST_TEST(client->getFirstName()=="Michal");
        client->changeLastName("Kowalski");
        BOOST_TEST(client->getLastName()=="Kowalski");
        client->changeFirstName("");
        BOOST_TEST(client->getFirstName()=="Michal");
        client->changeLastName("");
        BOOST_TEST(client->getLastName()=="Kowalski");
    }
    BOOST_AUTO_TEST_CASE(ClientInfoTests) {
        std::stringstream ss;
        ss << client->getBirthDate();
        std::string birthdate = ss.str();
        BOOST_TEST(client->getClientInfo()==client->getPersonalId()+", "+client->getFirstName()+" "+client->getLastName()+" Data urodzenia: "+birthdate);
    }



BOOST_AUTO_TEST_SUITE_END()