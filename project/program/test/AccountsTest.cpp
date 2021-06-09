#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <typedefs.h>
#include "model/Client.h"
#include "model/Account.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "managers/ClientManager.h"
#include "managers/AccountManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"
#include "model/Interest.h"
struct TestSuiteAccountFixture {
    TurboSaverPtr turboSaver = std::make_shared<TurboSaver>();
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    InterestPtr interest = std::make_shared<Interest>(0.05,0.19);
    TransactionManagerPtr TM = std::make_shared<TransactionManager>(turboLogger,turboSaver);
    AccountManagerPtr AM = std::make_shared<AccountManager>(turboLogger,turboSaver,interest);
    ClientManagerPtr CM = std::make_shared<ClientManager>(turboLogger,turboSaver);
    ClientPtr client = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2000,5,13)));
    AccountPtr acc = std::make_shared<CurrentAccount>(client,1,0,boost::posix_time::not_a_date_time,interest);
    AccountPtr savacc = std::make_shared<SavingsAccount>(client,2,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time,acc,interest);
    ClientPtr client2 = std::make_shared<Client>("12345678901","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1999,4,10)));
    AccountPtr acc2 = std::make_shared<CurrentAccount>(client2,1,0,boost::posix_time::not_a_date_time,interest);
    AccountPtr acc3 = std::make_shared<CurrentAccount>(client2,133,0,boost::posix_time::not_a_date_time,interest);
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteAccount,TestSuiteAccountFixture)

    BOOST_AUTO_TEST_CASE(AccountConstructorTests) {
        BOOST_TEST(acc->getOwner()==client);
        BOOST_TEST(acc->getOwner()->getFirstName()=="Marcin");
        BOOST_TEST(acc->getOwner()->getLastName()=="Nowak");
        BOOST_TEST(acc->getOwner()->getPersonalId()=="01234567891");
        BOOST_TEST(acc->getOwner()->getBirthDate()==boost::posix_time::ptime(boost::gregorian::date(2000,5,13)));
        BOOST_TEST(acc->getBalance()==0);
        BOOST_TEST(acc->getCreationDate()==boost::posix_time::second_clock::local_time());
        BOOST_TEST(acc->getAccountNumber()=="11246813570"+acc->getOwner()->getPersonalId()+"1001");
        BOOST_TEST(savacc->getConnectedAccount()==acc);
        BOOST_TEST(savacc->getLastInterest()==savacc->getCreationDate());
    }
    BOOST_AUTO_TEST_CASE(AccountGettersTests) {
        BOOST_TEST(acc->getBalance()==0);
        BOOST_TEST(acc->getCreationDate()==boost::posix_time::second_clock::local_time());
        BOOST_TEST(acc->getOwner()==client);
        BOOST_TEST(acc->getAccountNumber()=="11246813570"+acc->getOwner()->getPersonalId()+"1001");
        BOOST_TEST(savacc->getConnectedAccount()==acc);
        BOOST_TEST(savacc->getLastInterest()==savacc->getCreationDate());
    }
    BOOST_AUTO_TEST_CASE(AccountNumberGeneratorTest) {
        BOOST_TEST(acc3->getAccountNumber()=="33246813570"+acc3->getOwner()->getPersonalId()+"1133");
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
        BOOST_TEST(savacc->getAccountInfo()=="KONTO OSZCZEDNOSCIOWE Numer konta: "+savacc->getAccountNumber()+" Wlasciciel: "+savacc->getOwner()->getClientInfo()+" Stan konta: "+std::to_string(acc->getBalance())+"zl Data zalozenia: "+creation+ " Ostatnie naliczenie odsetek: " + interest);
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(TestSuiteChargeInterest,TestSuiteAccountFixture)
    BOOST_AUTO_TEST_CASE(AccountChargeInterestTests){
        double before = savacc->getBalance();
        savacc->chargeInterest();
        BOOST_CHECK_EQUAL(savacc->getBalance(),before+interest->calculate(before,savacc->getLastInterest()));
    }
BOOST_AUTO_TEST_SUITE_END()