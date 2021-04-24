#include <boost/test/unit_test.hpp>
#include <model/Bicycle.h>
#include <repositories/StorageContainer.h>
#include "model/Moped.h"
#include "model/Car.h"
#include "typedefs.h"
struct TestSuiteVehicleClassesFixture {
//Bicycle *bicycle = new Bicycle("EL95353",100)0;
//Moped *moped1 = new Moped("WE11",210,900)2;
//Moped *moped2 = new Moped("WE11",210,1000)3;
//Moped *moped3 = new Moped("WE11",210,1100);
//Moped *moped4 = new Moped("WE11",210,2000);
//Moped *moped5 = new Moped("WE11",210,2100);
//Car *car1 = new Car("EL990LN",210,1600,Car::A);
//Car *car2 = new Car("EL990LN",210,1600,Car::B);
//Car *car3 = new Car("EL990LN",210,1600,Car::C);
//Car *car4 = new Car("EL990LN",210,1600,Car::D);
//Car *car5 = new Car("EL990LN",210,1600,Car::E);
    StorageContainerPtr st = std::make_shared<StorageContainer>();
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleClassesPrice,TestSuiteVehicleClassesFixture)

    BOOST_AUTO_TEST_CASE(BicyclePrice) {
        BOOST_TEST(st->getVehiclerepository().getVehicle(0)->getActualRentalPrice()==100);
    }
    BOOST_AUTO_TEST_CASE(MopedPrice) {
        BOOST_TEST(st->getVehiclerepository().getVehicle(1)->getActualRentalPrice()==210);
        BOOST_TEST(st->getVehiclerepository().getVehicle(2)->getActualRentalPrice()==210);
        BOOST_TEST(st->getVehiclerepository().getVehicle(3)->getActualRentalPrice()==220.5);
        BOOST_TEST(st->getVehiclerepository().getVehicle(4)->getActualRentalPrice()==315);
        BOOST_TEST(st->getVehiclerepository().getVehicle(5)->getActualRentalPrice()==315);
    }
    BOOST_AUTO_TEST_CASE(CarPrice) {
        BOOST_TEST(st->getVehiclerepository().getVehicle(6)->getActualRentalPrice()==273);
        BOOST_TEST(st->getVehiclerepository().getVehicle(7)->getActualRentalPrice()==300.3,boost::test_tools::tolerance(0.1));
        BOOST_TEST(st->getVehiclerepository().getVehicle(8)->getActualRentalPrice()==327.6,boost::test_tools::tolerance(0.1));
        BOOST_TEST(st->getVehiclerepository().getVehicle(9)->getActualRentalPrice()==354.9,boost::test_tools::tolerance(0.1));
        BOOST_TEST(st->getVehiclerepository().getVehicle(10)->getActualRentalPrice()==409.5,boost::test_tools::tolerance(0.1));
    }
BOOST_AUTO_TEST_SUITE_END()

