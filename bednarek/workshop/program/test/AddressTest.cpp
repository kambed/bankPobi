#include <boost/test/unit_test.hpp>
#include <typedefs.h>
#include "model/Address.h"
struct TestSuiteAddressFixture {
    AddressPtr adres = std::make_shared<Address>("Lodz","Zielona","23");
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress,TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(AddressConstructorTests) {
        BOOST_TEST(adres->getCity() == "Lodz");
        BOOST_TEST(adres->getStreet() == "Zielona");
        BOOST_TEST(adres->getNumber() == "23");
    }
    BOOST_AUTO_TEST_CASE(AddressCityGetterTests) {
        BOOST_TEST(adres->getCity() == "Lodz");
    }
    BOOST_AUTO_TEST_CASE(AddressStreetGetterTests) {
        BOOST_TEST(adres->getStreet() == "Zielona");
    }
    BOOST_AUTO_TEST_CASE(AddressNumberGetterTests) {
        BOOST_TEST(adres->getNumber() == "23");
    }
BOOST_AUTO_TEST_SUITE_END()

