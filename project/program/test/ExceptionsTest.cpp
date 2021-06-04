#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include "typedefs.h"
#include "model/Client.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "model/Interest.h"
#include "exceptions/ClientException.h"
#include "exceptions/AccountException.h"
#include "exceptions/InterestException.h"

BOOST_AUTO_TEST_SUITE(ExceptionsTest)

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
        BOOST_CHECK_NO_THROW(CurrentAccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, 1));
        BOOST_CHECK_THROW(CurrentAccountPtr currentAccountError = std::make_shared<CurrentAccount>(nullptr, 1),AccountException::exception);
        BOOST_CHECK_THROW(CurrentAccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, 9000),AccountException::exception);
        BOOST_CHECK_THROW(CurrentAccountPtr currentAccountError = std::make_shared<CurrentAccount>(owner, -1),AccountException::exception);
    }
    BOOST_AUTO_TEST_CASE(SavingsAccountExceptionTest) {
        ClientPtr owner = std::make_shared<Client>("01234567891", "Marcin", "Nowak",
                                                   boost::posix_time::ptime(boost::gregorian::date(2000,5,13)));
        CurrentAccountPtr acc = std::make_shared<CurrentAccount>(owner,1);
        BOOST_CHECK_NO_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,acc,2));
        BOOST_CHECK_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(nullptr,acc,2),AccountException::exception);
        BOOST_CHECK_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,nullptr,2),AccountException::exception);
        BOOST_CHECK_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,acc,9000),AccountException::exception);
        BOOST_CHECK_THROW(SavingsAccountPtr savingsAccountError = std::make_shared<SavingsAccount>(owner,acc,-1),AccountException::exception);
    }
    BOOST_AUTO_TEST_CASE(InterestExceptionTest) {
        BOOST_CHECK_NO_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,0.19));
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(-0.05,0.19),InterestException::exception);
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,-0.19),InterestException::exception);
        BOOST_CHECK_THROW(InterestPtr interest = std::make_shared<Interest>(0.05,1.19),InterestException::exception);
    }

BOOST_AUTO_TEST_SUITE_END()