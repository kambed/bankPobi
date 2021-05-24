#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <typedefs.h>
#include "Client.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
struct TestSuiteAccountFixture {
    ClientPtr client = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
    AccountPtr acc = std::make_shared<CurrentAccount>(client,"12345");
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteAccount,TestSuiteAccountFixture)

    BOOST_AUTO_TEST_CASE(AccountConstructorTests) {
        BOOST_TEST(acc->getOwner()==client);
        BOOST_TEST(acc->getOwner()->getFirstName()=="Marcin");
        BOOST_TEST(acc->getOwner()->getLastName()=="Nowak");
        BOOST_TEST(acc->getOwner()->getPersonalId()=="01234567891");
        BOOST_TEST(acc->getOwner()->getBirthDate()==boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
        BOOST_TEST(acc->getBalance()==0);
        BOOST_TEST(acc->getCreationDate()==boost::posix_time::second_clock::local_time());
        std::string fullnrkonta=acc->getAccountNumber();
        std::string nrkonta=fullnrkonta.substr(2,24);
        BOOST_TEST(nrkonta=="246813570"+acc->getOwner()->getPersonalId()+"TO B");
    }
    BOOST_AUTO_TEST_CASE(AccountGettersTests) {
        BOOST_TEST(acc->getBalance()==0);
        BOOST_TEST(acc->getCreationDate()==boost::posix_time::second_clock::local_time());
        BOOST_TEST(acc->getOwner()==client);
        std::string fullnrkonta=acc->getAccountNumber();
        std::string nrkonta=fullnrkonta.substr(2,24);
        BOOST_TEST(nrkonta=="246813570"+acc->getOwner()->getPersonalId()+"TO B");
    }
    BOOST_AUTO_TEST_CASE(AccountInfoTests) {
        std::stringstream ss;
        ss << acc->getCreationDate();
        std::string creation = ss.str();
        BOOST_TEST(acc->getAccountInfo()=="KONTO ROZLICZENIOWE Numer konta: "+acc->getAccountNumber()+" Wlasciciel: "+acc->getOwner()->getClientInfo()+" Stan konta: "+std::to_string(acc->getBalance())+"zl Data zalozenia: "+creation);
    }
BOOST_AUTO_TEST_SUITE_END()

