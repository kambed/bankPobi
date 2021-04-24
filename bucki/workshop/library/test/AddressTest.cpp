#include <boost/test/unit_test.hpp>
#include <model/Address.h>
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest){
        AddressPtr address = std::make_shared<Address>("Lodz","Politechniki","38");
        BOOST_CHECK_EQUAL(address->getCity(),"Lodz");
        BOOST_CHECK_EQUAL(address->getStreet(),"Politechniki");
        BOOST_CHECK_EQUAL(address->getNumber(),"38");
    }

BOOST_AUTO_TEST_SUITE_END()