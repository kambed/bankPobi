#include <boost/test/unit_test.hpp>
#include <typedefs.h>
#include <managers/RentManager.h>
#include <managers/VehicleManager.h>
#include <managers/ClientManager.h>
#include <boost/date_time.hpp>
#include <boost/uuid/random_generator.hpp>

struct TestSuiteRentManagerFixture {
    RentManager rentmanager;
    VehicleManager vehiclemanager;
    ClientManager clientmanager;
    AddressPtr adres = std::make_shared<Address>("Lodz","Zielona","23");
    GoldPtr gold = std::make_shared<Gold>();
    DefaultPtr defaultt = std::make_shared<Default>();
    boost::uuids::random_generator generator;
};
bool predicateTest(RentPtr ptr)
{
    return ptr->getVehicle()->getPlateNumber()=="EL12345";
}
//bool predicateTest2(RentPtr ptr)
//{
//    return ptr->getRentcost()==1;
//}
BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager,TestSuiteRentManagerFixture)

    BOOST_AUTO_TEST_CASE(GetVehicleRentTests) {
    clientmanager.registerClient("Anna","Nowak","123123123",adres,gold);
    vehiclemanager.registerBicycle("EL12345",100);
    rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL12345"),boost::posix_time::not_a_date_time);
    BOOST_TEST(rentmanager.getVehicleRent(vehiclemanager.getVehicle("EL12345"))==rentmanager.findRents(predicateTest)[0]);
    }
    BOOST_AUTO_TEST_CASE(GetAllClientsRentsTests) {
        clientmanager.registerClient("Anna","Nowak","123123123",adres,gold);
        vehiclemanager.registerBicycle("EL12345",100);
        vehiclemanager.registerBicycle("EL12346",200);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL12345"),boost::posix_time::not_a_date_time);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL12346"),boost::posix_time::not_a_date_time);
        BOOST_TEST(rentmanager.getAllClientRents(clientmanager.getClient("123123123")) == rentmanager.findAllRents());
    }
    BOOST_AUTO_TEST_CASE(findRentsTests) {
        clientmanager.registerClient("Anna","Nowak","123123123",adres,gold);
        vehiclemanager.registerBicycle("EL12345",100);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL12345"),boost::posix_time::not_a_date_time);
        //BOOST_TEST(rentmanager.findRents(predicateTest2)==rentmanager.findAllRents());
    }
    BOOST_AUTO_TEST_CASE(checkClientRentBalanceTest){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,gold);
        vehiclemanager.registerBicycle("EL12345",100);
        vehiclemanager.registerBicycle("EL12346",200);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL12345"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL12346"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL12345"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL12346"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==285);
        BOOST_TEST(rentmanager.findAllRents().size()==0);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeDefaultTest){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",99);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==99);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==1);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeBronze1Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",100);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==100);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==2);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeBronze2Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",199);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==199);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==2);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeSilver1Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",200);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==200);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==3);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeSilver2Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",399);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==399);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==3);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeGold1Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",400);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==400);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==4);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeGold2Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",799);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==799);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==4);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypePlatinum1Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",800);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==800);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==5);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypePlatinum2Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",1599);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==1599);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==5);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeDiamond1Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",1600);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==1600);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==10);
    }
    BOOST_AUTO_TEST_CASE(changeClientTypeDiamond2Test){
        clientmanager.registerClient("Anna","Nowak","123123123",adres,defaultt);
        vehiclemanager.registerBicycle("EL1",2000);
        rentmanager.rentVehicle(clientmanager.getClient("123123123"),vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,26),boost::posix_time::hours(10)));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==0);
        rentmanager.returnVehicle(vehiclemanager.getVehicle("EL1"),boost::posix_time::ptime(boost::gregorian::date(2021,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rentmanager.checkClientRentBalance(clientmanager.getClient("123123123"))==2000);
        rentmanager.changeClientType(clientmanager.getClient("123123123"));
        BOOST_TEST(clientmanager.getClient("123123123")->getMaxVehicles()==10);
    }
BOOST_AUTO_TEST_SUITE_END()

