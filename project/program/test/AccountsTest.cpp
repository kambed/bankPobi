#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <typedefs.h>
#include "model/Client.h"
#include "model/Account.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
struct TestSuiteAccountFixture {
    ClientPtr client = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
    CurrentAccountPtr acc = std::make_shared<CurrentAccount>(client,"12345");
    SavingsAccountPtr savacc = std::make_shared<SavingsAccount>(client,acc);
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
        BOOST_TEST(savacc->getCurrentAccount()==acc);
        BOOST_TEST(savacc->getLastInterest()==savacc->getCreationDate());
        BOOST_TEST(savacc->getWasTransferThisMonth()==false);
    }
    BOOST_AUTO_TEST_CASE(AccountGettersTests) {
        BOOST_TEST(acc->getBalance()==0);
        BOOST_TEST(acc->getCreationDate()==boost::posix_time::second_clock::local_time());
        BOOST_TEST(acc->getOwner()==client);
        std::string fullnrkonta=acc->getAccountNumber();
        std::string nrkonta=fullnrkonta.substr(2,24);
        BOOST_TEST(nrkonta=="246813570"+acc->getOwner()->getPersonalId()+"TO B");
        BOOST_TEST(savacc->getCurrentAccount()==acc);
        BOOST_TEST(savacc->getLastInterest()==savacc->getCreationDate());
        BOOST_TEST(savacc->getWasTransferThisMonth()==false);
    }
    BOOST_AUTO_TEST_CASE(AccountSetBalancePositiveTest){
        acc->setBalance(5.5);
        BOOST_CHECK_EQUAL(acc->getBalance(),5.5);
    }
    BOOST_AUTO_TEST_CASE(AccountSetBalanceNegativeTest){
        acc->setBalance(-5.0);
        BOOST_CHECK_EQUAL(acc->getBalance(),0);
    }
    BOOST_AUTO_TEST_CASE(AccountInfoTests) {
        std::stringstream ss;
        ss << acc->getCreationDate();
        std::string creation = ss.str();
        BOOST_TEST(acc->getAccountInfo()=="KONTO ROZLICZENIOWE Numer konta: "+acc->getAccountNumber()+" Wlasciciel: "+acc->getOwner()->getClientInfo()+" Stan konta: "+std::to_string(acc->getBalance())+"zl Data zalozenia: "+creation);
        std::stringstream ss2;
        ss2 << savacc->getLastInterest();
        std::string interest = ss2.str();
        BOOST_TEST(savacc->getAccountInfo()=="KONTO OSZCZEDNOSCIOWE Numer konta: "+savacc->getAccountNumber()+" Wlasciciel: "+savacc->getOwner()->getClientInfo()+" Stan konta: "+std::to_string(acc->getBalance())+"zl Data zalozenia: "+creation+" Transfer w tym miesiacu: " + std::to_string(
                savacc->getWasTransferThisMonth()) + " Ostatnie naliczenie odsetek: " + interest);
    }
BOOST_AUTO_TEST_SUITE_END()

