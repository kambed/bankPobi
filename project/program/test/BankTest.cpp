#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include <memory>
#include "model/Bank.h"
#include "model/Interest.h"
#include "model/TurboSaver.h"
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
struct TestSuiteBankFixture {
    BankPtr bank = std::make_shared<Bank>();
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBank,TestSuiteBankFixture)

    BOOST_AUTO_TEST_CASE(BankConstructorTest) {
        BOOST_TEST(bank->getInterest()->getPercentage()==0.01);
        BOOST_TEST(bank->getInterest()->getTax()==0.19);
        BOOST_TEST(bank->getClientManager()->findAll().size()==bank->getTurboSaver()->countClients());
        BOOST_TEST(bank->getAccountManager()->findAll().size()==bank->getTurboSaver()->countSavingsAccounts()+bank->getTurboSaver()->countCurrentAccounts());
        BOOST_TEST(bank->getTransactionManager()->findAll().size()==bank->getTurboSaver()->countTransactions());
    }

BOOST_AUTO_TEST_SUITE_END()

