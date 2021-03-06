#include <boost/test/unit_test.hpp>
#include <model/Rent.h>
#include <model/Clients/Client.h>
#include <model/Vehicles/Vehicle.h>
#include <model/Clients/Bronze.h>
#include <model/Clients/Default.h>
#include <model/Clients/Silver.h>
#include <model/Clients/Gold.h>
#include <model/Clients/Platinum.h>
#include <model/Clients/Diamond.h>
#include "typedefs.h"

struct TestSuiteRentFixture {
    AddressPtr address;
    VehiclePtr vehicle;
    ClientPtr client;
    ClientTypePtr defaultType;

    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();

    boost::uuids::random_generator generator;

    TestSuiteRentFixture() {
        address = std::make_shared<Address>("Lodz", "Politechniki", "38");
        defaultType = std::make_shared<Default>();
        client = std::make_shared<Client>("Jan", "Kowalski", "12345678900", address, defaultType);
        vehicle = std::make_shared<Vehicle>("AB1234", 10000);
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(RentConstructor_not_a_day_time_Test) {
        boost::uuids::random_generator generator;
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, boost::posix_time::not_a_date_time);
        BOOST_CHECK_EQUAL(rent->getClient(), client);
        BOOST_CHECK_EQUAL(rent->getVehicle(), vehicle);

        //BOOST_CHECK_EQUAL(vehicle->isRented(),true);
        //BOOST_CHECK_EQUAL(client->getCurrentRents()[0],rent);
    }

    BOOST_AUTO_TEST_CASE(RentConstructorWithBeginTimeTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, boost::posix_time::not_a_date_time);
        BOOST_CHECK_EQUAL(rent->getClient(), client);
        BOOST_CHECK_EQUAL(rent->getVehicle(), vehicle);

        //BOOST_CHECK_EQUAL(vehicle->isRented(),true);
        // BOOST_CHECK_EQUAL(client->getCurrentRents()[0],rent);
    }

    BOOST_AUTO_TEST_CASE(EndRentTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now);
        rent->endRent(now + boost::posix_time::hours(1));
        BOOST_CHECK_EQUAL(rent->getEndTime(), now + boost::posix_time::hours(1));
        //BOOST_CHECK_EQUAL(vehicle->isRented(), false);
        //BOOST_CHECK(client->getCurrentRents().empty());
    }

    BOOST_AUTO_TEST_CASE(EndRent_not_a_date_time_Test) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now);
        rent->endRent(boost::posix_time::not_a_date_time);
        BOOST_CHECK_EQUAL(rent->getEndTime(), now);
        //BOOST_CHECK_EQUAL(vehicle->isRented(), false);
        //BOOST_CHECK(client->getCurrentRents().empty());
    }

    BOOST_AUTO_TEST_CASE(EndRentLessThanBeginTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now);
        rent->endRent(now - boost::posix_time::hours(1));
        BOOST_CHECK_EQUAL(rent->getEndTime(), rent->getBeginTime());
        //BOOST_CHECK_EQUAL(vehicle->isRented(), false);
        //BOOST_CHECK(client->getCurrentRents().empty());
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysTest) {     //And after 1 hour
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(1));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentDays(), 1);
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysNotEndTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now);
        BOOST_CHECK_EQUAL(rent->getRentDays(), 0);
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndAfterUnderMinuteTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now);
        rent->endRent(now + boost::posix_time::seconds(59));
        BOOST_CHECK_EQUAL(rent->getRentDays(), 0);
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndAfterMinuteTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now);
        rent->endRent(now + boost::posix_time::minutes(1));
        BOOST_CHECK_EQUAL(rent->getRentDays(), 1);
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndAfter23h59minTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle,
                                              now - boost::posix_time::minutes(59) - boost::posix_time::hours(23));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentDays(), 1);
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndAfter24hTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentDays(), 2);
    }

    BOOST_AUTO_TEST_CASE(GetRentDaysEndRentAlreadyEndedTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(25));
        rent->endRent(now - boost::posix_time::hours(23));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentDays(), 1);
    }

    BOOST_AUTO_TEST_CASE(getRentCostTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(23));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(), vehicle->getBasePrice() * rent->getRentDays());
    }

    BOOST_AUTO_TEST_CASE(getRentCostWhenRentDaysIs0Test) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::seconds(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(), 0);
    }

    BOOST_AUTO_TEST_CASE(getRentCostChangeVehicleRentPriceTest) {
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(24));
        rent->endRent(now);
        vehicle->setBasePrice(100);
        BOOST_CHECK_EQUAL(rent->getRentCost(), 20000);
    }

    BOOST_AUTO_TEST_CASE(getRentCostBronzeClientPriceTest) {
        ClientTypePtr type = std::make_shared<Bronze>();
        client->setClientType(type);
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(), (10000 - 3) * 2);
    }

    BOOST_AUTO_TEST_CASE(getRentCostSilverClientPriceTest) {
        ClientTypePtr type = std::make_shared<Silver>();
        client->setClientType(type);
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(), (10000 - 6) * 2);
    }

    BOOST_AUTO_TEST_CASE(getRentCostGoldClientPriceTest) {
        ClientTypePtr type = std::make_shared<Gold>();
        client->setClientType(type);
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(), (10000 * 0.95) * 2);
    }

    BOOST_AUTO_TEST_CASE(getRentCostPlatinumClientPriceTest) {
        ClientTypePtr type = std::make_shared<Platinum>();
        client->setClientType(type);
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(), (10000 * 0.9) * 2);
    }

    BOOST_AUTO_TEST_CASE(getRentCostDiamondClientPriceTest) {
        ClientTypePtr type = std::make_shared<Diamond>();
        client->setClientType(type);
        RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, now - boost::posix_time::hours(24));
        rent->endRent(now);
        BOOST_CHECK_EQUAL(rent->getRentCost(), (10000 * 0.6) * 2);
    }


BOOST_AUTO_TEST_SUITE_END()