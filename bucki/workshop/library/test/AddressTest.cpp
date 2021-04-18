#include <boost/test/unit_test.hpp>
#include <model/Address.h>

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest){
        Address address("Lodz","Politechniki","38");
        BOOST_CHECK_EQUAL(address.getCity(),"Lodz");
        BOOST_CHECK_EQUAL(address.getStreet(),"Politechniki");
        BOOST_CHECK_EQUAL(address.getNumber(),"38");
    }

//    BOOST_AUTO_TEST_CASE(AddressSetCityTest){
//        Address address("Lodz","Politechniki","38");
//        address.setCity("Wroclaw");
//        BOOST_CHECK_EQUAL(address.getCity(),"Wroclaw");
//    }
//
//    BOOST_AUTO_TEST_CASE(AddressSetStreetTest){
//        Address address("Lodz","Politechniki","38");
//        address.setStreet("Mickiewicza");
//        BOOST_CHECK_EQUAL(address.getStreet(),"Mickiewicza");
//    }
//
//    BOOST_AUTO_TEST_CASE(AddressSetNumberTest){
//        Address address("Lodz","Politechniki","38");
//        address.setNumber("39");
//        BOOST_CHECK_EQUAL(address.getNumber(),"39");
//    }

BOOST_AUTO_TEST_SUITE_END()