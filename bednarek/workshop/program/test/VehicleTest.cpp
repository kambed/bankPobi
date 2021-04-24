#include <boost/test/unit_test.hpp>
#include <model/Bicycle.h>
#include <typedefs.h>
#include "model/Vehicle.h"
struct TestSuiteVehicleFixture {
    BicyclePtr pojazd = std::make_shared<Bicycle>("EL990LN",100);
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle,TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(VehicleConstructorTests) {
        BOOST_TEST(pojazd->getBasePrice() == 100);
        BOOST_TEST(pojazd->getPlateNumber() == "EL990LN");
    }
    BOOST_AUTO_TEST_CASE(VehicleGetterBasePriceTests) {
        BOOST_TEST(pojazd->getBasePrice() == 100);
    }
    BOOST_AUTO_TEST_CASE(VehicleGetterPlateNumberTests) {
        BOOST_TEST(pojazd->getPlateNumber() == "EL990LN");
    }
    BOOST_AUTO_TEST_CASE(VehicleSetterPNTests) {
        pojazd->setPlateNumber("EL43434");
        BOOST_TEST(pojazd->getPlateNumber() == "EL43434");
    }
    BOOST_AUTO_TEST_CASE(VehicleSetterPNEmptyTests) {
        pojazd->setPlateNumber("");
        BOOST_TEST(pojazd->getPlateNumber() != "");
    }
    BOOST_AUTO_TEST_CASE(VehicleSetterBPTests) {
        pojazd->setBasePrice(200);
        BOOST_TEST(pojazd->getBasePrice() == 200);
    }
//    BOOST_AUTO_TEST_CASE(VehicleIsRentedTests) {
//        BOOST_TEST(pojazd->isRented() == false);
//    }
//    BOOST_AUTO_TEST_CASE(VehicleSetRentedTests) {
//        BOOST_TEST(pojazd->isRented() == false);
//        pojazd->setRented(true);
//        BOOST_TEST(pojazd->isRented() == true);
//    }
BOOST_AUTO_TEST_SUITE_END()

