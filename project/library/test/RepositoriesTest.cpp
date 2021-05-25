#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <typedefs.h>
#include "Client.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "repositories/ClientRepository.h"
#include "repositories/AccountRepository.h"
struct TestSuiteRepoFixture {
    ClientRepositoryPtr CR = std::make_shared<ClientRepository>();
    AccountRepositoryPtr AR = std::make_shared<AccountRepository>();
    ClientPtr client1 = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
    ClientPtr client2 = std::make_shared<Client>("98765432101","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1956,2,3)));
    CurrentAccountPtr acc1 = std::make_shared<CurrentAccount>(client1,"12345");
    SavingsAccountPtr savacc = std::make_shared<SavingsAccount>(client2,acc1);
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

BOOST_AUTO_TEST_SUITE_END()

