#include <boost/test/unit_test.hpp>
#include <model/Rent.h>
#include <model/Client.h>
#include <model/Vehicle.h>
#include "typedefs.h"

struct TestSuiteRentFixture {
    AddressPtr address;
    VehiclePtr vehicle;
    ClientPtr client;

    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();

    TestSuiteRentFixture() {
        address = new Address("Lodz", "Politechniki", "38");
        client = new Client("Jan","Kowalski","12345678900", address);
        vehicle = new Vehicle("AB1234",10000);
    }

    ~TestSuiteRentFixture() {
        delete address;
        delete client;
        delete vehicle;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(RentConstructor_not_a_day_time_Test){
        BOOST_CHECK_EQUAL(vehicle->isRented(),false);
        RentPtr rent = new Rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        BOOST_CHECK_EQUAL(rent->getId(),1);
        BOOST_CHECK_EQUAL(rent->getClient(),client);
        BOOST_CHECK_EQUAL(rent->getVehicle(),vehicle);

        BOOST_CHECK_EQUAL(vehicle->isRented(),true);
        BOOST_CHECK_EQUAL(client->getCurrentRents()[0],rent);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(RentConstructorWithBeginTimeTest){
        BOOST_CHECK_EQUAL(vehicle->isRented(),false);
        RentPtr rent = new Rent(1,client,vehicle,boost::posix_time::not_a_date_time);
        BOOST_CHECK_EQUAL(rent->getId(),1);
        BOOST_CHECK_EQUAL(rent->getClient(),client);
        BOOST_CHECK_EQUAL(rent->getVehicle(),vehicle);

        BOOST_CHECK_EQUAL(vehicle->isRented(),true);
        BOOST_CHECK_EQUAL(client->getCurrentRents()[0],rent);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(EndRentTest) {
        RentPtr rent = new Rent(1, client, vehicle, now);
        rent->endRent(now+boost::posix_time::hours(1));
        BOOST_CHECK_EQUAL(rent->getEndTime(), now+boost::posix_time::hours(1));
        BOOST_CHECK_EQUAL(vehicle->isRented(), false);
        BOOST_CHECK(client->getCurrentRents().empty());

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(EndRent_not_a_date_time_Test) {
        RentPtr rent = new Rent(1, client, vehicle, now);
        rent->endRent(boost::posix_time::not_a_date_time);
        BOOST_CHECK_EQUAL(rent->getEndTime(), now);
        BOOST_CHECK_EQUAL(vehicle->isRented(), false);
        BOOST_CHECK(client->getCurrentRents().empty());

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(EndRentLessThanBeginTest) {
        RentPtr rent = new Rent(1, client, vehicle, now);
        rent->endRent(now-boost::posix_time::hours(1));
        BOOST_CHECK_EQUAL(rent->getEndTime(), rent->getBeginTime());
        BOOST_CHECK_EQUAL(vehicle->isRented(), false);
        BOOST_CHECK(client->getCurrentRents().empty());

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysTest) {     //And after 1 hour
        RentPtr rent = new Rent(1, client, vehicle, now-boost::posix_time::hours(1));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentDays(), 1);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysNotEndTest) {
        RentPtr rent = new Rent(1, client, vehicle, now);
        BOOST_CHECK_EQUAL(rent->getRentDays(),0);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndAfterUnderMinuteTest) {
        RentPtr rent = new Rent(1, client, vehicle, now);
        rent->endRent(now+boost::posix_time::seconds(59));
        BOOST_CHECK_EQUAL(rent->getRentDays(),0);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndAfterMinuteTest) {
        RentPtr rent = new Rent(1, client, vehicle, now);
        rent->endRent(now+boost::posix_time::minutes(1));
        BOOST_CHECK_EQUAL(rent->getRentDays(),1);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndAfter23h59minTest) {
        RentPtr rent = new Rent(1, client, vehicle, now-boost::posix_time::minutes(59)-boost::posix_time::hours(23));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentDays(),1);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndAfter24hTest) {
        RentPtr rent = new Rent(1, client, vehicle, now-boost::posix_time::hours(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentDays(),2);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndRentAlreadyEndedTest) {
        RentPtr rent = new Rent(1, client, vehicle, now-boost::posix_time::hours(25));
        rent->endRent(now-boost::posix_time::hours(23));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentDays(),1);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(getRentCostTest) {
        RentPtr rent = new Rent(1, client, vehicle, now-boost::posix_time::hours(23));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(),vehicle->getBasePrice() * rent->getRentDays());

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(getRentCostWhenRentDaysIs0Test) {
        RentPtr rent = new Rent(1, client, vehicle, now-boost::posix_time::seconds(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(),0);

        delete rent;
    }

    BOOST_AUTO_TEST_CASE(getRentCostChangeVehicleRentPriceTest) {
        RentPtr rent = new Rent(1, client, vehicle, now-boost::posix_time::hours(24));
        rent->endRent(now);
        vehicle->setBasePrice(100);
        BOOST_CHECK_EQUAL(rent->getRentCost(),20000);

        delete rent;
    }



BOOST_AUTO_TEST_SUITE_END()