#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(ConstructorTests) {
        Client client("Jan","Kowalski","12345678901");
        BOOST_TEST(client.getFirstName() == "Jan");
        BOOST_TEST(client.getLastName() == "Kowalski");
        BOOST_TEST(client.getPersonalId() == "12345678901");
    }

    BOOST_AUTO_TEST_CASE(FirstNameSetterTests) {
        Client client("Jan","Kowalski","12345678901");
        client.setFirstName("Mariusz");
        BOOST_TEST(client.getFirstName() == "Mariusz");
    }
    BOOST_AUTO_TEST_CASE(FirstNameSetterEmptyTests) {
        Client client("Jan","Kowalski","12345678901");
        client.setFirstName("");
        BOOST_TEST(client.getFirstName() != "");
    }
    BOOST_AUTO_TEST_CASE(LastNameSetterTests) {
        Client client("Jan","Kowalski","12345678901");
        client.setLastName("Nowak");
        BOOST_TEST(client.getLastName() == "Nowak");
    }
    BOOST_AUTO_TEST_CASE(LastNameSetterEmptyTests) {
        Client client("Jan","Kowalski","12345678901");
        client.setLastName("");
        BOOST_TEST(client.getLastName() != "");
    }
    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.01));
        BOOST_TEST(true);
    }

BOOST_AUTO_TEST_SUITE_END()

