#include <boost/test/unit_test.hpp>
#include <typedefs.h>
#include <managers/VehicleManager.h>
struct TestSuiteClientManagerFixture {
    VehicleManager vehiclemanager;
};
bool predicateTest(VehiclePtr ptr)
{
    return ptr->getPlateNumber()=="EL12345";
}
BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleManager,TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(VehicleManagerTests) {
        BOOST_TEST(vehiclemanager.getVehicle("EL12345")==nullptr);
        vehiclemanager.registerBicycle("EL12345",100);
        BOOST_TEST(vehiclemanager.getVehicle("EL12345")!=nullptr);
        BOOST_TEST(vehiclemanager.getVehicle("EL12345")->getBasePrice()==100);
        BOOST_TEST(vehiclemanager.getVehicle("EL12345")->getPlateNumber()=="EL12345");
    }
    BOOST_AUTO_TEST_CASE(VehicleunRegisterTests) {
        vehiclemanager.registerBicycle("EL12345",100);
        vehiclemanager.unregisterVehicle(vehiclemanager.getVehicle("EL12345"));
        BOOST_TEST(vehiclemanager.getVehicle("EL12345")->isArchive()==true);
    }
    BOOST_AUTO_TEST_CASE(VehiclefindTests) {
        vehiclemanager.registerBicycle("EL12345",100);
        BOOST_TEST(vehiclemanager.findVehicles(predicateTest)[0]->getPlateNumber()=="EL12345");
        vehiclemanager.unregisterVehicle(vehiclemanager.getVehicle("EL12345"));
        BOOST_TEST(vehiclemanager.findVehicles(predicateTest).size()==0);
        BOOST_TEST(vehiclemanager.findAllVehicles().size()==0);
        vehiclemanager.registerBicycle("EL123456",100);
        BOOST_TEST(vehiclemanager.findAllVehicles().size()==1);
        BOOST_TEST(vehiclemanager.findAllVehicles()[0]->getPlateNumber()=="EL123456");
    }
BOOST_AUTO_TEST_SUITE_END()