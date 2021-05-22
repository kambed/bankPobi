#include <boost/test/unit_test.hpp>
#include <typedefs.h>
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
struct TestSuiteAccountFixture {
    //AccountPtr acc = std::make_shared<Account>(client);
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress,TestSuiteAccountFixture)

    BOOST_AUTO_TEST_CASE(AccountConstructorTests) {

    }
BOOST_AUTO_TEST_SUITE_END()

