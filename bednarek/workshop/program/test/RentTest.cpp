#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <model/Bicycle.h>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
struct TestSuiteRentFixture {
    AddressPtr adres=std::make_shared<Address>("Lodz", "Zielona", "22");
    VehiclePtr vehicle=std::make_shared<Bicycle>("EL42354",100);
    ClientPtr client=std::make_shared<Client>("Jan","Kowalski","12345678901",adres);
    RentPtr rent=std::make_shared<Rent>(1,client,vehicle,boost::posix_time::not_a_date_time,vehicle->getBasePrice());

};
BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(RentConstructorTests) {
        //BOOST_TEST(vehicle->isRented() == false);
        RentPtr rent=std::make_shared<Rent>(1,client,vehicle,boost::posix_time::not_a_date_time,vehicle->getBasePrice());
        BOOST_TEST(rent->getId() == 1);
        BOOST_TEST(rent->getClient() == client);
        BOOST_TEST(rent->getVehicle() == vehicle);
        //std::vector<RentPtr> testRents;
        //testRents.push_back(rent);
        //BOOST_TEST(vehicle->isRented() == true);
        //BOOST_TEST(testRents == client->getCurrentRents());
    }

    BOOST_AUTO_TEST_CASE(RentTimesDefaultConstructorTests) {
        BOOST_TEST_REQUIRE(!rent->getBeginTime().is_not_a_date_time());
        BOOST_TEST(rent->getBeginTime() == boost::posix_time::second_clock::local_time());
        BOOST_TEST(rent->getEndTime() == boost::posix_time::not_a_date_time);
    }
    BOOST_AUTO_TEST_CASE(RentTimesGivenConstructorTests) {
        RentPtr rent1 = std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)),vehicle->getBasePrice());
        BOOST_TEST_REQUIRE(!rent1->getBeginTime().is_not_a_date_time());
        BOOST_TEST(rent1->getBeginTime() == boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        BOOST_TEST(rent1->getEndTime() == boost::posix_time::not_a_date_time);
    }

    BOOST_AUTO_TEST_CASE(RentGettersTests) {
        BOOST_TEST(rent->getId() == 1);
        BOOST_TEST(rent->getClient() == client);
        BOOST_TEST(rent->getVehicle() == vehicle);
        BOOST_TEST(rent->getBeginTime() == boost::posix_time::second_clock::local_time());
        BOOST_TEST(rent->getEndTime() == boost::posix_time::not_a_date_time);
    }
//    BOOST_AUTO_TEST_CASE(EndRentRemoveisRentedTests) {
//        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time,vehicle->getBasePrice());
//        BOOST_TEST(rent.getVehicle()->isRented() == true);
//        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
//        BOOST_TEST(rent.getVehicle()->isRented() == false);
//    }
//    BOOST_AUTO_TEST_CASE(EndRentRemoveClientRentedTests) {
//        Rent *rent = new Rent(1,client,vehicle,boost::posix_time::not_a_date_time,vehicle->getBasePrice());
//        std::vector<Rent *> testRents;
//        testRents.push_back(rent);
//        BOOST_TEST(testRents == client->getCurrentRents());
//        rent->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
//        std::vector<Rent *> emptyRents;
//        BOOST_TEST(emptyRents == client->getCurrentRents());
//    }
    BOOST_AUTO_TEST_CASE(EndRentGivenTimeTests) {
        BOOST_TEST(rent->getEndTime() == boost::posix_time::not_a_date_time);
        rent->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        BOOST_TEST_REQUIRE(rent->getEndTime() == boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
    }
    BOOST_AUTO_TEST_CASE(EndRentNotOverwriteTests) {
        BOOST_TEST(rent->getEndTime() == boost::posix_time::not_a_date_time);
        rent->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        BOOST_TEST_REQUIRE(rent->getEndTime() == boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        rent->endRent(boost::posix_time::ptime(boost::gregorian::date(2022,6,14),boost::posix_time::hours(10)));
        BOOST_TEST(rent->getEndTime() == boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
    }
    BOOST_AUTO_TEST_CASE(EndRentNowTests) {
        rent->endRent(boost::posix_time::second_clock::local_time());
        BOOST_TEST(rent->getEndTime() == boost::posix_time::second_clock::local_time());
    }
    BOOST_AUTO_TEST_CASE(EndRentPastTests) {
        rent->endRent(boost::posix_time::ptime(boost::gregorian::date(1999,6,14),boost::posix_time::hours(10)));
        BOOST_TEST(rent->getEndTime() == boost::posix_time::second_clock::local_time());
    }
    BOOST_AUTO_TEST_CASE(EndRentDefaultTests) {
        rent->endRent(boost::posix_time::not_a_date_time);
        BOOST_TEST(rent->getEndTime() == boost::posix_time::second_clock::local_time());
    }
    BOOST_AUTO_TEST_CASE(RentDaysNotEndedTests) {
        RentPtr rent2 = std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)),vehicle->getBasePrice());
        BOOST_TEST(rent2->getRentdays() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentDaysEndedlessthen1minTests) {
        RentPtr rent3 = std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)),vehicle->getBasePrice());
        rent3->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10))+boost::posix_time::seconds(59));
        BOOST_TEST(rent3->getRentdays() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentDaysEnded1minTests) {
        RentPtr rent4= std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)),vehicle->getBasePrice());
        rent4->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10))+boost::posix_time::minutes(1));
        BOOST_TEST(rent4->getRentdays() == 1);
    }
    BOOST_AUTO_TEST_CASE(RentDaysEnded23h59mTests) {
        RentPtr rent5= std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)),vehicle->getBasePrice());
        rent5->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,7),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rent5->getRentdays() == 1);
    }
    BOOST_AUTO_TEST_CASE(RentDaysEnded24hTests) {
        RentPtr rent6= std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)),vehicle->getBasePrice());
        rent6->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,7),boost::posix_time::hours(10)));
        BOOST_TEST(rent6->getRentdays() == 2);
    }
    BOOST_AUTO_TEST_CASE(RentCost0Tests) {
        RentPtr rent7= std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)),vehicle->getBasePrice());
        rent7->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        BOOST_TEST(rent7->getRentcost() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentCostTests) {
        RentPtr rent8= std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)),vehicle->getBasePrice());
        rent8->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,7),boost::posix_time::hours(10)));
        BOOST_TEST(rent8->getRentcost() == vehicle->getBasePrice() * rent8->getRentdays());
    }
    BOOST_AUTO_TEST_CASE(RentCostChangeBasePriceTests) {
        RentPtr rent9= std::make_shared<Rent>(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)),vehicle->getBasePrice());
        rent9->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,8),boost::posix_time::hours(9)));
        int cost=rent9->getRentcost();
        vehicle->setBasePrice(500);
        BOOST_TEST(rent9->getRentcost() == cost);
    }

BOOST_AUTO_TEST_SUITE_END()