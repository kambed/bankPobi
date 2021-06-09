#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <typedefs.h>
#include "model/Client.h"
#include "model/Account.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "repositories/ClientRepository.h"
#include "repositories/AccountRepository.h"
#include "model/Transaction.h"
#include "repositories/TransactionRepository.h"
#include <boost/uuid/random_generator.hpp>
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"
#include "model/Interest.h"
struct TestSuiteRepoFixture {
    TurboSaverPtr turboSaver = std::make_shared<TurboSaver>();
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    InterestPtr interest = std::make_shared<Interest>(0.05,0.19);
    ClientRepositoryPtr CR = std::make_shared<ClientRepository>();
    AccountRepositoryPtr AR = std::make_shared<AccountRepository>();
    TransactionRepositoryPtr TR =std::make_shared<TransactionRepository>();
    ClientPtr client1 = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2000,5,13)));
    ClientPtr client2 = std::make_shared<Client>("98765432101","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1956,2,3)));
    CurrentAccountPtr acc1 = std::make_shared<CurrentAccount>(client1,1,turboSaver,0,boost::posix_time::not_a_date_time);
    CurrentAccountPtr acc2 = std::make_shared<CurrentAccount>(client2,1,turboSaver,0,boost::posix_time::not_a_date_time);
    SavingsAccountPtr savacc = std::make_shared<SavingsAccount>(client2,2,acc1,interest,turboSaver,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time);
    TransactionPtr trans1 = std::make_shared<Transaction>("",acc1,acc2,100,"Przelew");
    boost::uuids::random_generator generator;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepo,TestSuiteRepoFixture)

    BOOST_AUTO_TEST_CASE(ClientsRepoTests) {
        BOOST_TEST(CR->getClient("01234567891")==nullptr);
        CR->addClient(client1);
        CR->addClient(client2);
        BOOST_TEST(CR->getClient("01234567891")==client1);
        BOOST_TEST(CR->getClient("11111111111")==nullptr);
    }
    BOOST_AUTO_TEST_CASE(AccountsRepoTests) {
        BOOST_TEST(AR->getAccount(acc1->getAccountNumber())==nullptr);
        AR->addAccount(acc1);
        BOOST_TEST(AR->getAccount(acc1->getAccountNumber())==acc1);
        AR->addAccount(savacc);
        bool status=AR->removeAccount(acc1);
        BOOST_TEST(status==true);
        BOOST_TEST(AR->getAccount(acc1->getAccountNumber())==nullptr);
        status=AR->removeAccount(acc1);
        BOOST_TEST(status==false);
        BOOST_TEST(AR->getAccount(acc1->getAccountNumber())==nullptr);
        BOOST_TEST(AR->getAccount(savacc->getAccountNumber())==savacc);
    }
    BOOST_AUTO_TEST_CASE(TransactionRepoTests) {
        BOOST_TEST(TR->getTransaction(generator())==nullptr);
        TR->addTransaction(trans1);
        BOOST_TEST(TR->getTransaction(trans1->getId())==trans1);
        BOOST_TEST(TR->getTransaction(generator())==nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()

