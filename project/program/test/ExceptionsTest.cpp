#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include "typedefs.h"
#include "model/Client.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "model/Interest.h"
#include "model/Transaction.h"
#include "exceptions/ClientException.h"
#include "exceptions/AccountException.h"
#include "exceptions/InterestException.h"
#include "exceptions/TransactionException.h"
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"
#include "model/Interest.h"
struct TestSuiteExceptionFixture {
    TurboSaverPtr turboSaver = std::make_shared<TurboSaver>();
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    InterestPtr interest = std::make_shared<Interest>(0.05,0.19);
    TransactionManagerPtr TM = std::make_shared<TransactionManager>(turboLogger,turboSaver);
    AccountManagerPtr AM = std::make_shared<AccountManager>(turboLogger,turboSaver, TM,interest);
    ClientManagerPtr CM = std::make_shared<ClientManager>(turboLogger,turboSaver);
};
BOOST_FIXTURE_TEST_SUITE(ExceptionsTest,TestSuiteExceptionFixture)

    BOOST_AUTO_TEST_CASE(ClientExceptionTest) {
        BOOST_CHECK_NO_THROW(ClientPtr clientError = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver));
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("", "Marcin", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("0123456789", "", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver),ClientException::exception);;
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("012345678900", "", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("01234567891", "", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("01234567891", "Marcin", "",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                                  boost::posix_time::second_clock::local_time(),turboSaver),ClientException::exception);
    }

    BOOST_AUTO_TEST_CASE(CurrentAccountExceptionTest) {
        ClientPtr owner = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                                                   boost::posix_time::ptime(boost::gregorian::date(2000, 5, 13)),turboSaver);
        BOOST_CHECK_NO_THROW(CurrentAccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, 1,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time));
        BOOST_CHECK_THROW(CurrentAccountPtr currentAccountError = std::make_shared<CurrentAccount>(nullptr, 1,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time),AccountException::exception);
        BOOST_CHECK_THROW(CurrentAccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, 9000,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time),AccountException::exception);
        BOOST_CHECK_THROW(CurrentAccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, -1,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time),AccountException::exception);
    }
    BOOST_AUTO_TEST_CASE(SavingsAccountExceptionTest) {
        ClientPtr owner = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                                                   boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver);
        CurrentAccountPtr acc = std::make_shared<CurrentAccount>(owner,1,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time);
        BOOST_CHECK_NO_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,2,TM,AM, acc,interest,turboSaver,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time));
        BOOST_CHECK_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(nullptr,2,TM,AM,acc,interest,turboSaver,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time),AccountException::exception);
        BOOST_CHECK_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,2,TM,AM,nullptr,interest,turboSaver,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time),AccountException::exception);
        BOOST_CHECK_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,9000,TM,AM,acc,interest,turboSaver,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time),AccountException::exception);
        BOOST_CHECK_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,-1,TM,AM,acc,interest,turboSaver,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time),AccountException::exception);
    }
    BOOST_AUTO_TEST_CASE(InterestExceptionTest) {
        BOOST_CHECK_NO_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,0.19));
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(-0.05,0.19),InterestException::exception);
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,-0.19),InterestException::exception);
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,1.19),InterestException::exception);
    }
    BOOST_AUTO_TEST_CASE(TransactionExceptionTest) {
        ClientPtr client1 = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2000,5,13)),turboSaver);
        ClientPtr client2 = std::make_shared<Client>("98765432101","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1956,2,3)),turboSaver);
        CurrentAccountPtr acc1 = std::make_shared<CurrentAccount>(client1,1,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time);
        CurrentAccountPtr acc2 = std::make_shared<CurrentAccount>(client2,1,TM,AM,turboSaver,0,boost::posix_time::not_a_date_time);
        TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,100,"Test");
        BOOST_CHECK_NO_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,100,"Test"));
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",nullptr,acc2,100,"Test"),TransactionException::exception);
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,nullptr,100,"Test"),TransactionException::exception);
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,0,"Test"),TransactionException::exception);
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,-100,"Test"),TransactionException::exception);
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,100,""),TransactionException::exception);
    }

BOOST_AUTO_TEST_SUITE_END()