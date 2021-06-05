#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <typedefs.h>
#include "model/Client.h"
#include "model/Account.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "model/Transaction.h"
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"
#include "model/Interest.h"
struct TestSuiteTransactionFixture {
    TurboSaverPtr turboSaver = std::make_shared<TurboSaver>();
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    InterestPtr interest = std::make_shared<Interest>(0.05,0.19);
    TransactionManagerPtr TM = std::make_shared<TransactionManager>(turboLogger,turboSaver);
    AccountManagerPtr AM = std::make_shared<AccountManager>(turboLogger,turboSaver,TM,interest);
    ClientManagerPtr CM = std::make_shared<ClientManager>(turboLogger,turboSaver);
    ClientPtr client1 = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver);
    ClientPtr client2 = std::make_shared<Client>("98765432101","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1956,2,3)),turboSaver);
    CurrentAccountPtr acc1 = std::make_shared<CurrentAccount>(client1,1,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time);
    CurrentAccountPtr acc2 = std::make_shared<CurrentAccount>(client2,1,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time);
    TransactionPtr trans1 = std::make_shared<Transaction>("",acc1,acc2,100,"Test");
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteAccount,TestSuiteTransactionFixture)

BOOST_AUTO_TEST_CASE(TransactionConstructorTests) {
    BOOST_TEST(trans1->getAccountFrom()==acc1);
    BOOST_TEST(trans1->getAccountTo()==acc2);
    BOOST_TEST(trans1->getTitle()=="Test");
    BOOST_TEST(trans1->getAmount()==100);
}
BOOST_AUTO_TEST_CASE(TransactionInfoTests) {
    std::string info = trans1->getTransactionInfo();
    std::size_t pos = info.find(": z ");
    std::string infotest = info.substr (pos);
    BOOST_TEST(infotest==": z "+trans1->getAccountFrom()->getAccountNumber()+" do "+trans1->getAccountTo()->getAccountNumber()+" Kwota: "+std::to_string(trans1->getAmount())+", tytul: "+trans1->getTitle());
}
BOOST_AUTO_TEST_SUITE_END()

