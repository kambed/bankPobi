#include <boost/test/unit_test.hpp>
#include <model/Bicycle.h>
#include "model/Vehicle.h"

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    BOOST_AUTO_TEST_CASE(VehicleConstructorTests) {
        Bicycle pojazd("EL990LN",100);
        BOOST_TEST(pojazd.getBasePrice() == 100);
        BOOST_TEST(pojazd.getPlateNumber() == "EL990LN");
    }
    BOOST_AUTO_TEST_CASE(VehicleGetterBasePriceTests) {
        Bicycle pojazd("EL990LN",100);
        BOOST_TEST(pojazd.getBasePrice() == 100);
    }
    BOOST_AUTO_TEST_CASE(VehicleGetterPlateNumberTests) {
        Bicycle pojazd("EL990LN",100);
        BOOST_TEST(pojazd.getPlateNumber() == "EL990LN");
    }
    BOOST_AUTO_TEST_CASE(VehicleSetterPNTests) {
        Bicycle pojazd("EL990LN",100);
        pojazd.setPlateNumber("EL43434");
        BOOST_TEST(pojazd.getPlateNumber() == "EL43434");
    }
    BOOST_AUTO_TEST_CASE(VehicleSetterPNEmptyTests) {
        Bicycle pojazd("EL990LN",100);
        pojazd.setPlateNumber("");
        BOOST_TEST(pojazd.getPlateNumber() != "");
    }
    BOOST_AUTO_TEST_CASE(VehicleSetterBPTests) {
        Bicycle pojazd("EL990LN",100);
        pojazd.setBasePrice(200);
        BOOST_TEST(pojazd.getBasePrice() == 200);
    }
    BOOST_AUTO_TEST_CASE(VehicleIsRentedTests) {
        Bicycle pojazd("EL990LN",100);
        BOOST_TEST(pojazd.isRented() == false);
    }
    BOOST_AUTO_TEST_CASE(VehicleSetRentedTests) {
        Bicycle pojazd("EL990LN",100);
        BOOST_TEST(pojazd.isRented() == false);
        pojazd.setRented(true);
        BOOST_TEST(pojazd.isRented() == true);
    }
BOOST_AUTO_TEST_SUITE_END()

