#include <iostream>
#include <typedefs.h>
#include "model/Bank.h"
#include "managers/AccountManager.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "model/Client.h"
#include "model/Account.h"
#include "model/Transaction.h"

using namespace std;

int main() {
    BankPtr bank = std::make_shared<Bank>();
//    bank->getClientManager()->addClient("10203040506","Kamil","Bednarek",boost::posix_time::ptime(boost::gregorian::date(2001,1,6)));
//    bank->getClientManager()->addClient("08090102070","Radoslaw","Bucki",boost::posix_time::ptime(boost::gregorian::date(2000,11,26)));
//    bank->getClientManager()->addClient("54545454545","Jan","Kowalski",boost::posix_time::ptime(boost::gregorian::date(1976,6,11)));
//    bank->getAccountManager()->createCurrentAccount(bank->getClientManager()->getClient("10203040506"),"-",2500,boost::posix_time::not_a_date_time);
//    bank->getAccountManager()->createCurrentAccount(bank->getClientManager()->getClient("08090102070"),"-",1300,boost::posix_time::ptime(boost::gregorian::date(2019,4,27),boost::posix_time::hours(9))+boost::posix_time::minutes(59)+boost::posix_time::seconds(40));
//    bank->getAccountManager()->createSavingsAccount(bank->getClientManager()->getClient("10203040506"),"10246813570102030405061000",200,boost::posix_time::not_a_date_time,boost::posix_time::not_a_date_time);
//    bank->getTransactionManager()->createTransaction("217e2c9a-7d35-4a70-80fa-cd8e26ac90b1",bank->getAccountManager()->getAccount("10246813570102030405061000"),bank->getAccountManager()->getAccount("10246813570080901020701000"),100,"Rozliczenie");
    cout<<bank->getClientManager()->getClient("10203040506")->getClientInfo()<<endl;
    cout<<bank->getClientManager()->getClient("08090102070")->getClientInfo()<<endl;
    cout<<bank->getClientManager()->getClient("54545454545")->getClientInfo()<<endl<<endl;;
    cout<<bank->getAccountManager()->getAccount("10246813570102030405061000")->getAccountInfo()<<endl;
    cout<<bank->getAccountManager()->getAccount("10246813570080901020701000")->getAccountInfo()<<endl;
    cout<<bank->getAccountManager()->getAccount("10246813570102030405061000")->getConnectedAccount()->getAccountInfo()<<endl<<endl;
    cout<<bank->getTransactionManager()->getTransaction("217e2c9a-7d35-4a70-80fa-cd8e26ac90b1")->getTransactionInfo()<<endl;
    return 0;
}