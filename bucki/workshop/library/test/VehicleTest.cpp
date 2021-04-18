#include <boost/test/unit_test.hpp>
#include <model/Vehicle.h>

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    BOOST_AUTO_TEST_CASE(VehicleConstructorTest){
       Vehicle vehicle("AB1234",10000);
       BOOST_CHECK_EQUAL(vehicle.getPlateNumber(),"AB1234");
       BOOST_CHECK_EQUAL(vehicle.getBasePrice(),10000);
    }

    BOOST_AUTO_TEST_CASE(VehicleSetPlateNumberTest){
        Vehicle vehicle("AB1234",10000);
        vehicle.setPlateNumber("CD5678");
        BOOST_CHECK_EQUAL(vehicle.getPlateNumber(),"CD5678");
    }

    BOOST_AUTO_TEST_CASE(VehicleSetEmptyPlateNumberTest){
        Vehicle vehicle("AB1234",10000);
        vehicle.setPlateNumber("");
        BOOST_CHECK_EQUAL(vehicle.getPlateNumber(),"AB1234");
    }

    BOOST_AUTO_TEST_CASE(VehicleBasePriceTest){
        Vehicle vehicle("AB1234",10000);
        vehicle.setBasePrice(12000);
        BOOST_CHECK_EQUAL(vehicle.getBasePrice(),12000);
    }

    BOOST_AUTO_TEST_CASE(VehicleSetRentedTest){
        Vehicle vehicle("AB1234",10000);
        vehicle.setRented(true);
        BOOST_CHECK_EQUAL(vehicle.isRented(),true);
    }



BOOST_AUTO_TEST_SUITE_END()