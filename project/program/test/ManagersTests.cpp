#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <typedefs.h>
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/Client.h"
#include "model/Account.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "repositories/ClientRepository.h"
#include "repositories/AccountRepository.h"
#include <algorithm>
#include <vector>
#include <memory>
struct TestSuiteManagerFixture {
    AccountManagerPtr AM = std::make_shared<AccountManager>();
    ClientManagerPtr CM = std::make_shared<ClientManager>();
    TransactionManagerPtr TM = std::make_shared<TransactionManager>();
    ClientPtr client1 = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
    ClientPtr client2 = std::make_shared<Client>("12345678901","Michal","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
    CurrentAccountPtr acc1 = std::make_shared<CurrentAccount>(client1,"12345");
    CurrentAccountPtr acc2 = std::make_shared<CurrentAccount>(client2,"54321");
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepo,TestSuiteManagerFixture)

    BOOST_AUTO_TEST_CASE(AccountManagerTests) {
        AM->createCurrentAccount(client1);
        BOOST_TEST(AM->findAll()[0]->getBalance()==0);
        AM->setBalance(AM->findAll()[0]->getAccountNumber(),100);
        BOOST_TEST(AM->findAll()[0]->getBalance()==100);
        BOOST_TEST(AM->getAccount(AM->findAll()[0]->getAccountNumber())==AM->findAll()[0]);
        std::vector<AccountPtr>testowy;
        testowy.push_back(AM->findAll()[0]);
        BOOST_TEST(AM->findAll()==testowy);
        AM->createCurrentAccount(client2);
        AM->createSavingsAccount(client2,AM->findAll()[1]->getAccountNumber());
        BOOST_TEST(AM->findAll()!=testowy);
        testowy.push_back(AM->findAll()[1]);
        testowy.push_back(AM->findAll()[2]);
        BOOST_TEST(AM->findAll()==testowy);
        AccountPtr deleteacc=AM->findAll()[1];
        testowy.erase(std::remove(testowy.begin(),testowy.end(),AM->findAll()[1]));
        BOOST_TEST(AM->findAll()!=testowy);
        bool status = AM->removeAccount(AM->findAll()[1]->getAccountNumber());
        BOOST_TEST(status==true);
        BOOST_TEST(AM->findAll()==testowy);
        BOOST_TEST(AM->findAll()[0]->getAccountInfo()==testowy[0]->getAccountInfo());
        status = AM->removeAccount("losowaNieprawidlowa");
        BOOST_TEST(status==false);
        BOOST_TEST(AM->findAll()==testowy);
    }
    BOOST_AUTO_TEST_CASE(ClientManagerAddClientTests){
        CM->addClient("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
        BOOST_CHECK_EQUAL(CM->findAll().size(),1);
    }
    BOOST_AUTO_TEST_CASE(ClientManagerAddClientNegativeTests){
        CM->addClient("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
        CM->addClient("01234567891","Michal","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
        BOOST_CHECK_EQUAL(CM->findAll().size(),1);
    }
    BOOST_AUTO_TEST_CASE(TransactionManagerTests){
        TM->createTransaction(acc1,acc2,100,"Testowy przelew");
        BOOST_CHECK_EQUAL(TM->findAll().size(),1);
        std::vector<TransactionPtr>testowy;
        testowy.push_back(TM->findAll()[0]);
        BOOST_TEST(testowy==TM->findAll());
        TM->createTransaction(acc1,acc2,100,"Testowy przelew");
        testowy.push_back(TM->findAll()[1]);
        BOOST_TEST(testowy==TM->findAll());
        BOOST_CHECK_EQUAL(TM->findAll().size(),2);
    }

BOOST_AUTO_TEST_SUITE_END()
