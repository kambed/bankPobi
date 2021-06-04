#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include "typedefs.h"
#include "model/Client.h"
#include "exceptions/ClientException.h"

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

BOOST_AUTO_TEST_SUITE_END()