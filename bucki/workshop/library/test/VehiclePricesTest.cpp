#include <boost/test/unit_test.hpp>
#include <model/vehicle.h>
#include <model/Bicycle.h>
#include <model/Moped.h>
#include <model/Car.h>
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    BOOST_AUTO_TEST_CASE(VehiclePriceTest){
        VehiclePtr vehicle = new Vehicle("AB1234",100);
       BOOST_TEST(vehicle->getActualRentalPrice() == 100.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(BicyclePriceTest){
        VehiclePtr vehicle = new Bicycle("AB1234",100);
       BOOST_TEST(vehicle->getActualRentalPrice() == 100.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(MopedPriceLess1000Test){
        VehiclePtr vehicle = new Moped("AB1234",100,900);
       BOOST_TEST(vehicle->getActualRentalPrice() == 100.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(MopedPrice1000Test){
        VehiclePtr vehicle = new Moped("AB1234",100,1000);
       BOOST_TEST(vehicle->getActualRentalPrice() == 100.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(MopedPrice1100Test){
        VehiclePtr vehicle = new Moped("AB1234",100,1100);
       BOOST_TEST(vehicle->getActualRentalPrice() == 105.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(MopedPrice1200Test){
        VehiclePtr vehicle = new Moped("AB1234",100,1200);
       BOOST_TEST(vehicle->getActualRentalPrice() == 110.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(MopedPrice1300Test){
        VehiclePtr vehicle = new Moped("AB1234",100,1300);
       BOOST_TEST(vehicle->getActualRentalPrice() == 115.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(MopedPrice1900Test){
        VehiclePtr vehicle = new Moped("AB1234",100,1900);
       BOOST_TEST(vehicle->getActualRentalPrice() == 145.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(MopedPrice2000Test){
        VehiclePtr vehicle = new Moped("AB1234",100,2000);
       BOOST_TEST(vehicle->getActualRentalPrice() == 150.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(MopedPriceOver2000Test){
        VehiclePtr vehicle = new Moped("AB1234",100,2500);
       BOOST_TEST(vehicle->getActualRentalPrice() == 150.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(CarPriceASegmenetTest){
        VehiclePtr vehicle = new Car("AB1234",100,1000,Car::A);
       BOOST_TEST(vehicle->getActualRentalPrice() == 100.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(CarPriceBSegmenetTest){
        VehiclePtr vehicle = new Car("AB1234",100,1100,Car::B);
       BOOST_TEST(vehicle->getActualRentalPrice() == 115.5,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(CarPriceCSegmenetTest){
        VehiclePtr vehicle = new Car("AB1234",100,1200,Car::C);
       BOOST_TEST(vehicle->getActualRentalPrice() == 132.0,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(CarPriceDSegmenetTest){
        VehiclePtr vehicle = new Car("AB1234",100,1300,Car::D);
       BOOST_TEST(vehicle->getActualRentalPrice() == 149.5,boost::test_tools::tolerance(0.02));
    }

    BOOST_AUTO_TEST_CASE(CarPriceESegmenetTest){
        VehiclePtr vehicle = new Car("AB1234",100,2500,Car::E);
       BOOST_TEST(vehicle->getActualRentalPrice() == 225.0,boost::test_tools::tolerance(0.02));
    }

BOOST_AUTO_TEST_SUITE_END()