#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/TurboSaver.h"
#include "exceptions/TurboSaverException.h"
#include "model/Client.h"
#include "model/Account.h"
#include "model/Transaction.h"
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
#include "model/Interest.h"
struct TestSuiteTurboSaverFixture {
    TurboSaverPtr ts = std::make_shared<TurboSaver>();
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    InterestPtr interest = std::make_shared<Interest>(0.05,0.19);
    TransactionManagerPtr TM = std::make_shared<TransactionManager>(turboLogger,ts);
    AccountManagerPtr AM = std::make_shared<AccountManager>(turboLogger,ts,interest);
    ClientManagerPtr CM = std::make_shared<ClientManager>(turboLogger,ts);
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteTurboSaver,TestSuiteTurboSaverFixture)
    BOOST_AUTO_TEST_CASE(TurboSaverConstructorTest) {
        BOOST_CHECK_NO_THROW(TurboSaverPtr ts = std::make_shared<TurboSaver>());
        CM->addClient("12694342188","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2000,6,3)));
        CM->addClient("12345678901","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1999,1,10)));
        CM->addClient("12694342122","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2001,6,3)));
        AM->createCurrentAccount(CM->getClient("12694342188"),0,boost::posix_time::not_a_date_time);
        AM->createCurrentAccount(CM->getClient("12345678901"),0,boost::posix_time::not_a_date_time);
        AM->getAccount("10246813570126943421881000")->setBalance(200);
        AM->createSavingsAccount(CM->getClient("12694342188"),"10246813570126943421881000",0,
                                 boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time);
}
    BOOST_AUTO_TEST_CASE(TurboSaverImportTest) {
        BOOST_TEST(CM->findAll().size()==0);
        ts->importClients(CM);
        BOOST_TEST(CM->findAll().size()==ts->countClients());
        BOOST_TEST(CM->findAll()[0]->getPersonalId()=="12345678912");
        ts->importCurrentAccounts(AM,CM);
        BOOST_TEST(AM->findAll().size()==ts->countCurrentAccounts());
        ts->importSavingsAccounts(AM,CM);
        BOOST_TEST(AM->findAll().size()==ts->countSavingsAccounts()+ts->countCurrentAccounts());
        ts->importTransactions(TM,AM);
        BOOST_TEST(TM->findAll().size()==ts->countTransactions());
    }
BOOST_AUTO_TEST_SUITE_END()
