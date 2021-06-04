#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/TurboSaver.h"
#include "exceptions/TurboSaverException.h"
#include "model/Client.h"
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
struct TestSuiteTurboSaverFixture {
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    TransactionManagerPtr TM = std::make_shared<TransactionManager>(turboLogger);
    AccountManagerPtr AM = std::make_shared<AccountManager>(turboLogger, TM);
    ClientManagerPtr CM = std::make_shared<ClientManager>(turboLogger);
    TurboSaverPtr ts = std::make_shared<TurboSaver>(CM,TM,AM);
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteTurboSaver,TestSuiteTurboSaverFixture)
    BOOST_AUTO_TEST_CASE(TurboSaverConstructorTest) {
        BOOST_CHECK_NO_THROW(TurboSaverPtr ts = std::make_shared<TurboSaver>(CM,TM,AM));
        ClientPtr client = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2000,6,3)));
        ClientPtr client2 = std::make_shared<Client>("12345678901","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1999,1,10)));
        ts->saveClient(client);
        ts->saveClient(client2);
}
    BOOST_AUTO_TEST_CASE(TurboSaverImportTest) {
        BOOST_TEST(CM->findAll().size()==0);
        ts->importClient();
        BOOST_TEST(CM->findAll().size()==2);
    }
BOOST_AUTO_TEST_SUITE_END()
