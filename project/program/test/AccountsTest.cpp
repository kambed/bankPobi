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
struct TestSuiteAccountFixture {
    ClientPtr client = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
    CurrentAccountPtr acc = std::make_shared<CurrentAccount>(client,1);
    SavingsAccountPtr savacc = std::make_shared<SavingsAccount>(client,acc,2);
    ClientPtr client2 = std::make_shared<Client>("12345678901","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1999,4,10)));
    CurrentAccountPtr acc2 = std::make_shared<CurrentAccount>(client2,1);
    CurrentAccountPtr acc3 = std::make_shared<CurrentAccount>(client2,133);
};
struct SendMoneyFixture {
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    AccountManagerPtr AM = std::make_shared<AccountManager>(turboLogger);
    TransactionManagerPtr TM = std::make_shared<TransactionManager>(turboLogger);
    ClientManagerPtr CM = std::make_shared<ClientManager>(turboLogger);
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
        BOOST_TEST(acc->getAccountNumber()=="11246813570"+acc->getOwner()->getPersonalId()+"1001");
        BOOST_TEST(savacc->getCurrentAccount()==acc);
        BOOST_TEST(savacc->getLastInterest()==savacc->getCreationDate());
        BOOST_TEST(savacc->getWasTransferThisMonth()==false);
    }
    BOOST_AUTO_TEST_CASE(AccountGettersTests) {
        BOOST_TEST(acc->getBalance()==0);
        BOOST_TEST(acc->getCreationDate()==boost::posix_time::second_clock::local_time());
        BOOST_TEST(acc->getOwner()==client);
        BOOST_TEST(acc->getAccountNumber()=="11246813570"+acc->getOwner()->getPersonalId()+"1001");
        BOOST_TEST(savacc->getCurrentAccount()==acc);
        BOOST_TEST(savacc->getLastInterest()==savacc->getCreationDate());
        BOOST_TEST(savacc->getWasTransferThisMonth()==false);
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
        BOOST_TEST(savacc->getAccountInfo()=="KONTO OSZCZEDNOSCIOWE Numer konta: "+savacc->getAccountNumber()+" Wlasciciel: "+savacc->getOwner()->getClientInfo()+" Stan konta: "+std::to_string(acc->getBalance())+"zl Data zalozenia: "+creation+" Transfer w tym miesiacu: " + std::to_string(savacc->getWasTransferThisMonth()) + " Ostatnie naliczenie odsetek: " + interest);
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(TestSuiteAccountSendMoney,SendMoneyFixture)
    BOOST_AUTO_TEST_CASE(AccountSendMoneyTests){
        CM->addClient("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
        AM->createCurrentAccount(CM->getClient("01234567891"));
        CM->addClient("12345678912","Michal","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
        AM->createCurrentAccount(CM->getClient("12345678912"));
        AccountPtr acc=AM->getAccount(AM->findAll()[0]->getAccountNumber());
        AccountPtr acc2=AM->getAccount(AM->findAll()[1]->getAccountNumber());
        AM->setBalance(AM->findAll()[0]->getAccountNumber(),1000);
        AM->setBalance(AM->findAll()[1]->getAccountNumber(),200);
        bool status=acc->sendMoney(acc2->getAccountNumber(),200,"Testowy przelew",TM,AM);
        BOOST_TEST(status==true);
        BOOST_TEST(AM->getAccount(AM->findAll()[0]->getAccountNumber())->getBalance()==800);
        BOOST_TEST(AM->getAccount(AM->findAll()[1]->getAccountNumber())->getBalance()==400);
    }
    BOOST_AUTO_TEST_CASE(AccountSendMoneyTestsNegative){
        CM->addClient("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
        AM->createCurrentAccount(CM->getClient("01234567891"));
        CM->addClient("12345678912","Michal","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
        AM->createCurrentAccount(CM->getClient("12345678912"));
        AccountPtr acc=AM->getAccount(AM->findAll()[0]->getAccountNumber());
        AccountPtr acc2=AM->getAccount(AM->findAll()[1]->getAccountNumber());
        AM->setBalance(AM->findAll()[0]->getAccountNumber(),1000);
        AM->setBalance(AM->findAll()[1]->getAccountNumber(),200);
        bool status=acc->sendMoney(acc2->getAccountNumber(),2000,"Testowy przelew",TM,AM);
        BOOST_TEST(status==false);
        BOOST_TEST(AM->getAccount(AM->findAll()[0]->getAccountNumber())->getBalance()==1000);
        BOOST_TEST(AM->getAccount(AM->findAll()[1]->getAccountNumber())->getBalance()==200);
        status=acc->sendMoney("LOSOWYBLEDNY",200,"Testowy przelew",TM,AM);
        BOOST_TEST(status==false);
        BOOST_TEST(AM->getAccount(AM->findAll()[0]->getAccountNumber())->getBalance()==1000);
        BOOST_TEST(AM->getAccount(AM->findAll()[1]->getAccountNumber())->getBalance()==200);
    }
BOOST_AUTO_TEST_SUITE_END()

