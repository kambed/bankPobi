#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/TurboSaver.h"
#include "exceptions/TurboSaverException.h"
#include "model/Client.h"
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
#include "model/Interest.h"
struct TestSuiteTurboSaverFixture {
    TurboSaverPtr ts = std::make_shared<TurboSaver>();
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    InterestPtr interest = std::make_shared<Interest>(0.05,0.19);
    TransactionManagerPtr TM = std::make_shared<TransactionManager>(turboLogger);
    AccountManagerPtr AM = std::make_shared<AccountManager>(turboLogger, TM, interest);
    ClientManagerPtr CM = std::make_shared<ClientManager>(turboLogger,ts);
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteTurboSaver,TestSuiteTurboSaverFixture)
    BOOST_AUTO_TEST_CASE(TurboSaverConstructorTest) {
        BOOST_CHECK_NO_THROW(TurboSaverPtr ts = std::make_shared<TurboSaver>());
        CM->addClient("12694342121","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2000,6,3)));
        CM->addClient("12345678901","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1999,1,10)));
}
    BOOST_AUTO_TEST_CASE(TurboSaverImportTest) {
        BOOST_TEST(CM->findAll().size()==0);
        ts->importClient(CM);
        BOOST_TEST(CM->findAll().size()==5);
    }
BOOST_AUTO_TEST_SUITE_END()
