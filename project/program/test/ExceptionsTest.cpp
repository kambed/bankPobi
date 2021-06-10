#include <boost/test/unit_test.hpp>
#include <exception>
#include "model/Client.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "model/Interest.h"
#include "model/Transaction.h"
#include "exceptions/ClientException.h"
#include "exceptions/AccountException.h"
#include "exceptions/InterestException.h"
#include "exceptions/TransactionException.h"
#include "exceptions/ClientManagerException.h"
#include "exceptions/AccountManagerException.h"
#include "exceptions/TransactionManagerException.h"
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"
struct TestSuiteExceptionFixture {
    TurboSaverPtr turboSaver = std::make_shared<TurboSaver>();
    TurboLoggerPtr turboLogger = std::make_shared<TurboLogger>();
    InterestPtr interest = std::make_shared<Interest>(0.05,0.19);
    TransactionManagerPtr TM = std::make_shared<TransactionManager>(turboLogger,turboSaver);
    AccountManagerPtr AM = std::make_shared<AccountManager>(turboLogger,turboSaver,interest);
    ClientManagerPtr CM = std::make_shared<ClientManager>(turboLogger,turboSaver);
};
BOOST_FIXTURE_TEST_SUITE(ExceptionsTest,TestSuiteExceptionFixture)

    BOOST_AUTO_TEST_CASE(ClientExceptionTest) {
        BOOST_CHECK_NO_THROW(ClientPtr clientError = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13))));
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("", "Marcin", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13))),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("0123456789", "", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13))),ClientException::exception);;
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("012345678900", "", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13))),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("01234567891", "", "Nowak",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13))),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("01234567891", "Marcin", "",
                             boost::posix_time::ptime(boost::gregorian::date(2000,5,13))),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                                  boost::posix_time::second_clock::local_time()),ClientException::exception);
    }

    BOOST_AUTO_TEST_CASE(CurrentAccountExceptionTest) {
        ClientPtr owner = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                                                   boost::posix_time::ptime(boost::gregorian::date(2000, 5, 13)));
        BOOST_CHECK_NO_THROW(AccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, 1,0,boost::posix_time::not_a_date_time,interest));
        BOOST_CHECK_THROW(AccountPtr currentAccountError = std::make_shared<CurrentAccount>(nullptr, 1,0,boost::posix_time::not_a_date_time,interest),AccountException::exception);
        BOOST_CHECK_THROW(AccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, 9000,0,boost::posix_time::not_a_date_time,interest),AccountException::exception);
        BOOST_CHECK_THROW(AccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, -1,0,boost::posix_time::not_a_date_time,interest),AccountException::exception);
    }
    BOOST_AUTO_TEST_CASE(SavingsAccountExceptionTest) {
        ClientPtr owner = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                                                   boost::posix_time::ptime(boost::gregorian::date(2000,5,13)));
        AccountPtr acc = std::make_shared<CurrentAccount>(owner,1,0,boost::posix_time::not_a_date_time,interest);
        BOOST_CHECK_NO_THROW(AccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,2,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time,acc,interest));
        BOOST_CHECK_THROW(AccountPtr savingsAccountError = std::make_shared<SavingsAccount>(nullptr,2,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time,acc,interest),AccountException::exception);
        BOOST_CHECK_THROW(AccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,2,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time,nullptr,interest),AccountException::exception);
        BOOST_CHECK_THROW(AccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,9000,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time,acc,interest),AccountException::exception);
        BOOST_CHECK_THROW(AccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,-1,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time,acc,interest),AccountException::exception);
        BOOST_CHECK_THROW(AccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,1,0,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time,acc,nullptr),AccountException::exception);
    }
    BOOST_AUTO_TEST_CASE(InterestExceptionTest) {
        BOOST_CHECK_NO_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,0.19));
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(-0.05,0.19),InterestException::exception);
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,-0.19),InterestException::exception);
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,1.19),InterestException::exception);
    }
    BOOST_AUTO_TEST_CASE(TransactionExceptionTest) {
        ClientPtr client1 = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2000,5,13)));
        ClientPtr client2 = std::make_shared<Client>("98765432101","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1956,2,3)));
        AccountPtr acc1 = std::make_shared<CurrentAccount>(client1,1,0,boost::posix_time::not_a_date_time,interest);
        AccountPtr acc2 = std::make_shared<CurrentAccount>(client2,1,0,boost::posix_time::not_a_date_time,interest);
        TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,100,"Test");
        BOOST_CHECK_NO_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,100,"Test"));
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",nullptr,acc2,100,"Test"),TransactionException::exception);
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,nullptr,100,"Test"),TransactionException::exception);
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,0,"Test"),TransactionException::exception);
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,-100,"Test"),TransactionException::exception);
        BOOST_CHECK_THROW(TransactionPtr transactionError = std::make_shared<Transaction>("",acc1,acc2,100,""),TransactionException::exception);
    }
    BOOST_AUTO_TEST_CASE(AccountManagerExceptionTest) {
        BOOST_CHECK_NO_THROW(AccountManagerPtr accountManager = std::make_shared<AccountManager>(turboLogger,turboSaver,interest));
        BOOST_CHECK_THROW(AccountManagerPtr accountManager = std::make_shared<AccountManager>(nullptr,turboSaver,interest),ClientManagerException::exception);
        BOOST_CHECK_THROW(AccountManagerPtr accountManager = std::make_shared<AccountManager>(turboLogger,nullptr,interest),ClientManagerException::exception);
        BOOST_CHECK_THROW(AccountManagerPtr accountManager = std::make_shared<AccountManager>(turboLogger,turboSaver,nullptr),ClientManagerException::exception);
    }
    BOOST_AUTO_TEST_CASE(ClientManagerExceptionTest) {
        BOOST_CHECK_NO_THROW(ClientManagerPtr clientManager = std::make_shared<ClientManager>(turboLogger,turboSaver));
        BOOST_CHECK_THROW(ClientManagerPtr clientManager = std::make_shared<ClientManager>(nullptr,turboSaver),ClientManagerException::exception);
        BOOST_CHECK_THROW(ClientManagerPtr clientManager = std::make_shared<ClientManager>(turboLogger,nullptr),ClientManagerException::exception);
    }
    BOOST_AUTO_TEST_CASE(TransactionManagerExceptionTest) {
        BOOST_CHECK_NO_THROW(TransactionManagerPtr transactionManager = std::make_shared<TransactionManager>(turboLogger,turboSaver));
        BOOST_CHECK_THROW(TransactionManagerPtr transactionManager = std::make_shared<TransactionManager>(nullptr,turboSaver),TransactionManagerException::exception);
        BOOST_CHECK_THROW(TransactionManagerPtr transactionManager = std::make_shared<TransactionManager>(nullptr,turboSaver),TransactionManagerException::exception);
    }

BOOST_AUTO_TEST_SUITE_END()