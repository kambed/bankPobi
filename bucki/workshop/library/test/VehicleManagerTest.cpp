#include <boost/test/unit_test.hpp>
#include "model/vehicles/Vehicle.h"
#include "model/vehicles/Bicycle.h"
#include "model/vehicles/Moped.h"
#include "model/vehicles/Car.h"
#include "model/managers/LogicContainer.h"
#include "model/managers/VehicleManager.h"
#include "typedefs.h"

bool vehiclePredicate(VehiclePtr vehicle) {
    return vehicle->getPlateNumber() == "AB1234";
}

struct TestSuiteVehicleFixture {
    const std::string testPlateNumber = "AB1234";
    unsigned int testBasePrice = 100;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleManager, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(VehicleMananagerRegisterAndGetBicycleTest) {
        VehiclePtr Vehicle = std::make_shared<Bicycle>(testPlateNumber,testBasePrice);
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->getVehicle(testPlateNumber), nullptr);
        logicContainer->getVehicleManager()->registerBicycle(testPlateNumber,testBasePrice);
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->getVehicle(testPlateNumber)->getPlateNumber(),
                          Vehicle->getPlateNumber());
    }

    BOOST_AUTO_TEST_CASE(VehicleMananagerRegisterAndGetMopedTest) {
        VehiclePtr Vehicle = std::make_shared<Moped>(testPlateNumber,testBasePrice,1000);
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->getVehicle(testPlateNumber), nullptr);
        logicContainer->getVehicleManager()->registerMoped(testPlateNumber,testBasePrice,1000);
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->getVehicle(testPlateNumber)->getPlateNumber(),
                          Vehicle->getPlateNumber());
    }

    BOOST_AUTO_TEST_CASE(VehicleMananagerRegisterAndGetCarTest) {
        VehiclePtr Vehicle = std::make_shared<Car>(testPlateNumber,testBasePrice,1000,Car::A);
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->getVehicle(testPlateNumber), nullptr);
        logicContainer->getVehicleManager()->registerCar(testPlateNumber,testBasePrice,1000,Car::A);
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->getVehicle(testPlateNumber)->getPlateNumber(),
                          Vehicle->getPlateNumber());
    }

    BOOST_AUTO_TEST_CASE(VehicleMananagerFindVehiclesTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        logicContainer->getVehicleManager()->registerBicycle(testPlateNumber,testBasePrice);
        logicContainer->getVehicleManager()->registerBicycle("CD5678",200);
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->findVehicles(vehiclePredicate)[0]->getPlateNumber(),
                          testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(VehicleMananagerFindVehiclesIfIsArchiveTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        logicContainer->getVehicleManager()->registerBicycle(testPlateNumber,testBasePrice);
        logicContainer->getVehicleManager()->unregisterVehicle(testPlateNumber);
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->findVehicles(vehiclePredicate).size(), 0);
    }

    BOOST_AUTO_TEST_CASE(VehicleMananagerFindAllVehiclesTest) {
        LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();
        logicContainer->getVehicleManager()->registerBicycle(testPlateNumber,testBasePrice);
        logicContainer->getVehicleManager()->registerBicycle("CD5678",200);
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->findAllVehicles()[0]->getPlateNumber(),
                          testPlateNumber);
        BOOST_CHECK_EQUAL(logicContainer->getVehicleManager()->findAllVehicles()[1]->getPlateNumber(),
                          "CD5678");
    }

BOOST_AUTO_TEST_SUITE_END()