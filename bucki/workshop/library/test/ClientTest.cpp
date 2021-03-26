#include <boost/test/unit_test.hpp>
#include <model/Client.h>

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0 / 3.0 == 0.333,boost::test_tools::tolerance(0.002));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        Client client("Jan","Kowalski","12345678900");
        BOOST_CHECK_EQUAL(client.getFirstName(),"Jan");
        BOOST_CHECK_EQUAL(client.getLastName(),"Kowalski");
        BOOST_CHECK_EQUAL(client.getPersonalId(),"12345678900");
    }

    BOOST_AUTO_TEST_CASE(ClientSetFirstNameTest) {
        Client client("Jan","Kowalski","12345678900");
        client.setFirstName("Mariusz");
        BOOST_CHECK_EQUAL(client.getFirstName(),"Mariusz");
    }

    BOOST_AUTO_TEST_CASE(ClientSetEmptyFirstNameTest) {
        Client client("Jan","Kowalski","12345678900");
        client.setFirstName("");
        BOOST_CHECK_EQUAL(client.getFirstName(),"Jan");
    }

    BOOST_AUTO_TEST_CASE(ClientSetLastNameTest) {
        Client client("Jan","Kowalski","12345678900");
        client.setLastName("Nowak");
        BOOST_CHECK_EQUAL(client.getLastName(),"Nowak");
    }

    BOOST_AUTO_TEST_CASE(ClientSetEmptyLastNameTest) {
        Client client("Jan","Kowalski","12345678900");
        client.setLastName("");
        BOOST_CHECK_EQUAL(client.getLastName(),"Kowalski");
    }

BOOST_AUTO_TEST_SUITE_END()