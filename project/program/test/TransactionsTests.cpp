#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <typedefs.h>
#include "model/Client.h"
#include "model/Account.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "model/Transaction.h"
struct TestSuiteTransactionFixture {
    ClientPtr client1 = std::make_shared<Client>("01234567891","Marcin","Nowak",boost::posix_time::ptime(boost::gregorian::date(2021,5,13)));
    ClientPtr client2 = std::make_shared<Client>("98765432101","Michal","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1956,2,3)));
    CurrentAccountPtr acc1 = std::make_shared<CurrentAccount>(client1);
    CurrentAccountPtr acc2 = std::make_shared<CurrentAccount>(client2);
    TransactionPtr trans1 = std::make_shared<Transaction>(acc1,acc2,100,"Test");
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
    BOOST_TEST(infotest==": z "+trans1->getAccountFrom()->getAccountNumber()+" do "+trans1->getAccountTo()->getAccountNumber()+" Kwota: "+std::to_string(trans1->getAmount())+",tytul: "+trans1->getTitle());
}
BOOST_AUTO_TEST_SUITE_END()

