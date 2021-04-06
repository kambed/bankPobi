#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
struct TestSuiteRentFixture {
    Address *adres;
    Vehicle *vehicle;
    Client *client;

    TestSuiteRentFixture() {
        adres= new Address("Lodz", "Zielona", "22");
        vehicle= new Vehicle("EL42354",100);
        client= new Client("Jan","Kowalski","12345678901",adres);
    }

    ~TestSuiteRentFixture() {
        delete adres;
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(RentConstructorTests) {
        BOOST_TEST(vehicle->isRented() == false);
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        BOOST_TEST(rent.getId() == 1);
        BOOST_TEST(rent.getClient() == client);
        BOOST_TEST(rent.getVehicle() == vehicle);
        std::string currrents = " ";
        currrents = currrents + "\n" + rent.getRentInfo();
        BOOST_TEST(vehicle->isRented() == true);
        BOOST_TEST(currrents == client->getCurrentRents());
    }

    BOOST_AUTO_TEST_CASE(RentTimesDefaultConstructorTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        BOOST_TEST_REQUIRE(!rent.getBeginTime().is_not_a_date_time());
        BOOST_TEST(rent.getBeginTime() == boost::posix_time::second_clock::local_time());
        BOOST_TEST(rent.getEndTime() == boost::posix_time::not_a_date_time);
    }
    BOOST_AUTO_TEST_CASE(RentTimesGivenConstructorTests) {
        Rent rent1(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        BOOST_TEST_REQUIRE(!rent1.getBeginTime().is_not_a_date_time());
        BOOST_TEST(rent1.getBeginTime() == boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        BOOST_TEST(rent1.getEndTime() == boost::posix_time::not_a_date_time);
    }

    BOOST_AUTO_TEST_CASE(RentGettersTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        BOOST_TEST(rent.getId() == 1);
        BOOST_TEST(rent.getClient() == client);
        BOOST_TEST(rent.getVehicle() == vehicle);
        BOOST_TEST(rent.getBeginTime() == boost::posix_time::second_clock::local_time());
        BOOST_TEST(rent.getEndTime() == boost::posix_time::not_a_date_time);
    }
    BOOST_AUTO_TEST_CASE(EndRentRemoveisRentedTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        BOOST_TEST(rent.getVehicle()->isRented() == true);
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        BOOST_TEST(rent.getVehicle()->isRented() == false);
    }
    BOOST_AUTO_TEST_CASE(EndRentRemoveClientRentedTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        std::string currrents = " ";
        currrents = currrents + "\n" + rent.getRentInfo();
        BOOST_TEST(currrents == client->getCurrentRents());
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        currrents = " ";
        BOOST_TEST(currrents == client->getCurrentRents());
    }
    BOOST_AUTO_TEST_CASE(EndRentGivenTimeTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        BOOST_TEST(rent.getEndTime() == boost::posix_time::not_a_date_time);
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        BOOST_TEST_REQUIRE(rent.getEndTime() == boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
    }
    BOOST_AUTO_TEST_CASE(EndRentNotOverwriteTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        BOOST_TEST(rent.getEndTime() == boost::posix_time::not_a_date_time);
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        BOOST_TEST_REQUIRE(rent.getEndTime() == boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2022,6,14),boost::posix_time::hours(10)));
        BOOST_TEST(rent.getEndTime() == boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
    }
    BOOST_AUTO_TEST_CASE(EndRentNowTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        rent.endRent(boost::posix_time::second_clock::local_time());
        BOOST_TEST(rent.getEndTime() == boost::posix_time::second_clock::local_time());
    }
    BOOST_AUTO_TEST_CASE(EndRentPastTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(1999,6,14),boost::posix_time::hours(10)));
        BOOST_TEST(rent.getEndTime() == boost::posix_time::second_clock::local_time());
    }
    BOOST_AUTO_TEST_CASE(EndRentDefaultTests) {
        Rent rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        rent.endRent(boost::posix_time::not_a_date_time);
        BOOST_TEST(rent.getEndTime() == boost::posix_time::second_clock::local_time());
    }
    BOOST_AUTO_TEST_CASE(RentDaysNotEndedTests) {
        Rent rent(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        BOOST_TEST(rent.getRentdays() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentDaysEndedlessthen1minTests) {
        Rent rent(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10))+boost::posix_time::seconds(59));
        BOOST_TEST(rent.getRentdays() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentDaysEnded1minTests) {
        Rent rent(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10))+boost::posix_time::minutes(1));
        BOOST_TEST(rent.getRentdays() == 1);
    }
    BOOST_AUTO_TEST_CASE(RentDaysEnded23h59mTests) {
        Rent rent(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,7),boost::posix_time::hours(9))+boost::posix_time::minutes(59));
        BOOST_TEST(rent.getRentdays() == 1);
    }
    BOOST_AUTO_TEST_CASE(RentDaysEnded24hTests) {
        Rent rent(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,7),boost::posix_time::hours(10)));
        BOOST_TEST(rent.getRentdays() == 2);
    }
    BOOST_AUTO_TEST_CASE(RentCost0Tests) {
        Rent rent(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        BOOST_TEST(rent.getRentcost() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentCostTests) {
        Rent rent(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,7),boost::posix_time::hours(10)));
        BOOST_TEST(rent.getRentcost() == vehicle->getBasePrice() * rent.getRentdays());
    }
    BOOST_AUTO_TEST_CASE(RentCostChangeBasePriceTests) {
        Rent rent(1,client,vehicle,boost::posix_time::ptime(boost::gregorian::date(2021,4,6),boost::posix_time::hours(10)));
        rent.endRent(boost::posix_time::ptime(boost::gregorian::date(2021,4,8),boost::posix_time::hours(9)));
        int cost=rent.getRentcost();
        vehicle->setBasePrice(500);
        BOOST_TEST(rent.getRentcost() == cost);
    }

BOOST_AUTO_TEST_SUITE_END()