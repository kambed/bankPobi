#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(AddressConstructorTests) {
        Address adres("Lodz","Zielona","23");
        BOOST_TEST(adres.getCity() == "Lodz");
        BOOST_TEST(adres.getStreet() == "Zielona");
        BOOST_TEST(adres.getNumber() == "23");
    }
    BOOST_AUTO_TEST_CASE(AddressCityGetterTests) {
        Address adres("Lodz","Zielona","23");
        BOOST_TEST(adres.getCity() == "Lodz");
    }
    BOOST_AUTO_TEST_CASE(AddressStreetGetterTests) {
        Address adres("Lodz","Zielona","23");
        BOOST_TEST(adres.getStreet() == "Zielona");
    }
    BOOST_AUTO_TEST_CASE(AddressNumberGetterTests) {
        Address adres("Lodz","Zielona","23");
        BOOST_TEST(adres.getNumber() == "23");
    }
BOOST_AUTO_TEST_SUITE_END()

