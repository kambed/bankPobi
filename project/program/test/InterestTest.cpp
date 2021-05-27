#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include <memory>
#include "model/Interest.h"
struct TestSuiteInterestFixture {
    InterestPtr interest = std::make_shared<Interest>(0.05,0.19);
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteInterest,TestSuiteInterestFixture)

    BOOST_AUTO_TEST_CASE(InterestConstructorTest) {
        BOOST_CHECK_EQUAL(interest->getPercentage(),0.05);
        BOOST_CHECK_EQUAL(interest->getTax(),0.19);
    }
    BOOST_AUTO_TEST_CASE(TaxSetterTest) {
        interest->setTax(0.1);
        BOOST_CHECK_EQUAL(interest->getTax(),0.1);
    }
    BOOST_AUTO_TEST_CASE(PrecentageSetterTest) {
        interest->setPercentage(0.01);
        BOOST_CHECK_EQUAL(interest->getPercentage(),0.01);
    }
    BOOST_AUTO_TEST_CASE(TaxSetterNegativeTest) {
        interest->setTax(-0.1);
        BOOST_CHECK_EQUAL(interest->getTax(),0.19);
    }
    BOOST_AUTO_TEST_CASE(PrecentageSetterNegativeTest) {
        interest->setPercentage(-0.01);
        BOOST_CHECK_EQUAL(interest->getPercentage(),0.05);
    }
    BOOST_AUTO_TEST_CASE(CalculateInterestTest) {
        BOOST_CHECK_EQUAL(interest->calculate(100,boost::posix_time::second_clock::local_time()
        -boost::posix_time::hours(24)),1/365*100*interest->getPercentage()*(1-interest->getTax()));
    }

BOOST_AUTO_TEST_SUITE_END()