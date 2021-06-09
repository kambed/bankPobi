#include "model/TurboSaver.h"
#include <exceptions/TurboSaverException.h>
#include <iostream>
#include <cstdlib>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include "model/Client.h"
#include "model/Account.h"
#include "model/SavingsAccount.h"
#include "model/CurrentAccount.h"
#include "model/Transaction.h"
#include "functions.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "managers/AccountManager.h"
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <sstream>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include <boost/date_time/posix_time/time_formatters.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"

TurboSaver::TurboSaver() {
    std::system("mkdir -p ./databases");
    try {
        int cf = sqlite3_open("databases/clients.db", &dbc);
        int tf = sqlite3_open("databases/transactions.db", &dbt);
        int caf = sqlite3_open("databases/currentaccounts.db", &dbca);
        int saf = sqlite3_open("databases/savingsaccounts.db", &dbsa);
        if (caf){
            std::string blad="Can't open currentaccount database";
            blad=blad+sqlite3_errmsg(dbca);
            throw TurboSaverException(blad);
        }
        if (saf){
            std::string blad="Can't open savingsaccount database";
            blad=blad+sqlite3_errmsg(dbsa);
            throw TurboSaverException(blad);
        }
        if (cf){
            std::string blad="Can't open client database";
            blad=blad+sqlite3_errmsg(dbc);
            throw TurboSaverException(blad);
        }
        if (tf){
            std::string blad="Can't open transaction database";
            blad=blad+sqlite3_errmsg(dbt);
            throw TurboSaverException(blad);
        }
        sql = "CREATE TABLE CLIENT("
              "id                      TEXT PRIMARY KEY     NOT NULL, "
              "first_name              TEXT                 NOT NULL, "
              "last_name               TEXT                 NOT NULL, "
              "birth_date              TEXT                 NOT NULL);";
        cf = sqlite3_exec(dbc,sql.c_str(),NULL,0,&error);
        sql = "CREATE TABLE CURRENTACC("
              "account_number          TEXT PRIMARY KEY     NOT NULL, "
              "savings_account_number  TEXT                 NOT NULL, "
              "client_id               TEXT                 NOT NULL, "
              "balance                 DOUBLE               NOT NULL, "
              "creation_date           TEXT                 NOT NULL);";
        caf = sqlite3_exec(dbca,sql.c_str(),NULL,0,&error);
        sql = "CREATE TABLE SAVINGACC("
              "account_number          TEXT PRIMARY KEY     NOT NULL, "
              "current_account_number  TEXT                 NOT NULL, "
              "client_id               TEXT                 NOT NULL, "
              "balance                 DOUBLE               NOT NULL, "
              "creation_date           TEXT                 NOT NULL, "
              "last_interest           TEXT                 NOT NULL);";
        saf = sqlite3_exec(dbsa,sql.c_str(),NULL,0,&error);
        sql = "CREATE TABLE TRANS("
              "id                       TEXT PRIMARY KEY     NOT NULL, "
              "from_acc_number          TEXT                 NOT NULL, "
              "to_acc_number            TEXT                 NOT NULL, "
              "title                    TEXT                 NOT NULL, "
              "amount                   DOUBLE               NOT NULL);";
        tf = sqlite3_exec(dbt,sql.c_str(),NULL,0,&error);
        sqlite3_close(dbc);
        sqlite3_close(dbsa);
        sqlite3_close(dbca);
        sqlite3_close(dbt);
    }catch(const TurboSaverException &exception){
        std::cout << "Exception: " << exception.what() << std::endl;
    }
}

void TurboSaver::saveClient(ClientPtr client) {
    sqlite3_open("databases/clients.db", &dbc);
    sql = "DELETE FROM CLIENT WHERE id='"+client->getPersonalId()+"';";
    sqlite3_exec(dbc,sql.c_str(),NULL,0,&error);
    sql = "INSERT INTO CLIENT VALUES('"+client->getPersonalId()+"', '"+client->getFirstName()+"', '"+client->getLastName()+"', '"+dateTimeToString(client->getBirthDate())+"');";
    sqlite3_exec(dbc,sql.c_str(),NULL,0,&error);
    sqlite3_close(dbc);
}

void TurboSaver::saveSavingsAccount(AccountPtr account) {
    sqlite3_open("databases/savingsaccounts.db", &dbsa);
    sql = "DELETE FROM SAVINGACC WHERE account_number='"+account->getAccountNumber()+"';";
    sqlite3_exec(dbsa,sql.c_str(),NULL,0,&error);
    sql = "INSERT INTO SAVINGACC VALUES('"+account->getAccountNumber()+"', '"+account->getConnectedAccount()->getAccountNumber()+"', '"+account->getOwner()->getPersonalId()+"', '"+std::to_string(account->getBalance())+"', '"+dateTimeToString(account->getCreationDate())+"', '"+dateTimeToString(account->getLastInterest())+"');";
    sqlite3_exec(dbsa,sql.c_str(),NULL,0,&error);
    sqlite3_close(dbsa);
}

void TurboSaver::saveCurrentAccount(AccountPtr account) {
    sqlite3_open("databases/currentaccounts.db", &dbca);
    sql = "DELETE FROM CURRENTACC WHERE account_number='"+account->getAccountNumber()+"';";
    sqlite3_exec(dbca,sql.c_str(),NULL,0,&error);
    if(account->getConnectedAccount()==nullptr){
        sql = "INSERT INTO CURRENTACC VALUES('"+account->getAccountNumber()+"', '"+"-"+"', '"+account->getOwner()->getPersonalId()+"', '"+std::to_string(account->getBalance())+"', '"+dateTimeToString(account->getCreationDate())+"');";
    }else{
        sql = "INSERT INTO CURRENTACC VALUES('"+account->getAccountNumber()+"', '"+account->getConnectedAccount()->getAccountNumber()+"', '"+account->getOwner()->getPersonalId()+"', '"+std::to_string(account->getBalance())+"', '"+dateTimeToString(account->getCreationDate())+"');";
    }
    sqlite3_exec(dbca,sql.c_str(),NULL,0,&error);
    sqlite3_close(dbca);
}

void TurboSaver::removeAccount(std::string accnum) {
    sqlite3_open("databases/savingsaccounts.db", &dbsa);
    sql = "DELETE FROM SAVINGACC WHERE account_number='"+accnum+"';";
    sqlite3_exec(dbsa,sql.c_str(),NULL,0,&error);
    sqlite3_open("databases/currentaccounts.db", &dbca);
    sql = "DELETE FROM CURRENTACC WHERE account_number='"+accnum+"';";
    sqlite3_exec(dbca,sql.c_str(),NULL,0,&error);
}

void TurboSaver::saveTransaction(TransactionPtr transaction) {
    sqlite3_open("databases/transactions.db", &dbt);
    sql = "DELETE FROM TRANS WHERE id='"+boost::lexical_cast<std::string>(transaction->getId())+"';";
    sqlite3_exec(dbt,sql.c_str(),NULL,0,&error);
    sql = "INSERT INTO TRANS VALUES('"+boost::lexical_cast<std::string>(transaction->getId())+"', '"+transaction->getAccountFrom()->getAccountNumber()+"', '"+transaction->getAccountTo()->getAccountNumber()+"', '"+transaction->getTitle()+"', '"+std::to_string(transaction->getAmount())+"');";
    sqlite3_exec(dbt,sql.c_str(),NULL,0,&error);
    sqlite3_close(dbt);
}

void TurboSaver::importClients(ClientManagerPtr clientManager) {
    sqlite3_open("databases/clients.db", &dbc);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbc, "SELECT * FROM CLIENT", -1, &stmt, NULL);
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string str,str2,str3,str4,str5,str6,str7;
        str=arrayConstCharToString(sqlite3_column_text(stmt,0));
        str2=arrayConstCharToString(sqlite3_column_text(stmt,1));
        str3=arrayConstCharToString(sqlite3_column_text(stmt,2));
        str4=arrayConstCharToString(sqlite3_column_text(stmt,3));
        str5=str4.substr(0,4);
        str6=str4.substr(5,3);
        str7=str4.substr(9,2);
        int month=monthFromStr(str6);
        clientManager->addClient(str,str2,str3,boost::posix_time::ptime(boost::gregorian::date(atoi(str5.c_str()),month,atoi(str7.c_str()))));
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbc);
}
void TurboSaver::importTransactions(TransactionManagerPtr transactionManager,AccountManagerPtr accountManager) {
    sqlite3_open("databases/transactions.db", &dbt);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbt, "SELECT * FROM TRANS", -1, &stmt, NULL);
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        std::string str,str2,str3,str4,str5;
        str=arrayConstCharToString(sqlite3_column_text(stmt,0));
        str2=arrayConstCharToString(sqlite3_column_text(stmt,1));
        str3=arrayConstCharToString(sqlite3_column_text(stmt,2));
        str4=arrayConstCharToString(sqlite3_column_text(stmt,3));
        str5=arrayConstCharToString(sqlite3_column_text(stmt,4));
        transactionManager->saveTransaction(str,accountManager->getAccount(str2),accountManager->getAccount(str3),std::stod(str5),str4);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbt);
}

void TurboSaver::importCurrentAccounts(AccountManagerPtr accountManager,ClientManagerPtr clientManager) {
    sqlite3_open("databases/currentaccounts.db", &dbca);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbca, "SELECT * FROM CURRENTACC", -1, &stmt, NULL);
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        std::string str,str2,str3,str4,str5,year,mon,day,hours,mins,sec;
        str2=arrayConstCharToString(sqlite3_column_text(stmt,1));
        str5=arrayConstCharToString(sqlite3_column_text(stmt,2));
        str3=arrayConstCharToString(sqlite3_column_text(stmt,3));
        str4=arrayConstCharToString(sqlite3_column_text(stmt,4));
        year=str4.substr(0, 4);
        mon=str4.substr(5, 3);
        day=str4.substr(9, 2);
        hours=str4.substr(12, 2);
        mins=str4.substr(15, 2);
        sec=str4.substr(18, 2);
        int month=monthFromStr(mon);
        accountManager->createCurrentAccount(clientManager->getClient(str5),str2,std::stod(str3),boost::posix_time::ptime(boost::gregorian::date(atoi(year.c_str()), month, atoi(day.c_str())), boost::posix_time::hours(atoi(hours.c_str())) + boost::posix_time::minutes(atoi(mins.c_str())) + boost::posix_time::seconds(atoi(sec.c_str()))));
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbca);
}

void TurboSaver::importSavingsAccounts(AccountManagerPtr accountManager,ClientManagerPtr clientManager) {
    sqlite3_open("databases/savingsaccounts.db", &dbsa);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbsa, "SELECT * FROM SAVINGACC", -1, &stmt, NULL);
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        std::string str,str2,str3,str4,str5,str6,year,mon,day,hours,mins,sec,year2,mon2,day2,hours2,mins2,sec2;
        str2=arrayConstCharToString(sqlite3_column_text(stmt,1));
        str3=arrayConstCharToString(sqlite3_column_text(stmt,2));
        str4=arrayConstCharToString(sqlite3_column_text(stmt,3));
        str5=arrayConstCharToString(sqlite3_column_text(stmt,4));
        str6=arrayConstCharToString(sqlite3_column_text(stmt,5));
        year=str5.substr(0, 4);
        mon=str5.substr(5, 3);
        day=str5.substr(9, 2);
        hours=str5.substr(12, 2);
        mins=str5.substr(15, 2);
        sec=str5.substr(18, 2);
        year2=str6.substr(0, 4);
        mon2=str6.substr(5, 3);
        day2=str6.substr(9, 2);
        hours2=str6.substr(12, 2);
        mins2=str6.substr(15, 2);
        sec2=str6.substr(18, 2);
        int month=monthFromStr(mon);
        int month2=monthFromStr(mon2);
        accountManager->createSavingsAccount(clientManager->getClient(str3),str2,std::stod(str4),boost::posix_time::ptime(boost::gregorian::date(atoi(year.c_str()), month, atoi(day.c_str())), boost::posix_time::hours(atoi(hours.c_str())) + boost::posix_time::minutes(atoi(mins.c_str())) + boost::posix_time::seconds(atoi(sec.c_str()))),boost::posix_time::ptime(boost::gregorian::date(atoi(year2.c_str()), month2, atoi(day2.c_str())), boost::posix_time::hours(atoi(hours2.c_str())) + boost::posix_time::minutes(atoi(mins2.c_str())) + boost::posix_time::seconds(atoi(sec2.c_str()))));
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbca);
}

int TurboSaver::countClients() {
    sqlite3_open("databases/clients.db", &dbc);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbc, "SELECT * FROM CLIENT", -1, &stmt, NULL);
    int i=0;
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        i++;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbc);
    return i;
}

int TurboSaver::countSavingsAccounts() {
    sqlite3_open("databases/savingsaccounts.db", &dbsa);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbsa, "SELECT * FROM SAVINGACC", -1, &stmt, NULL);
    int i=0;
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        i++;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbsa);
    return i;
}

int TurboSaver::countCurrentAccounts() {
    sqlite3_open("databases/currentaccounts.db", &dbca);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbca, "SELECT * FROM CURRENTACC", -1, &stmt, NULL);
    int i=0;
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        i++;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbca);
    return i;
}

int TurboSaver::countTransactions() {
    sqlite3_open("databases/transactions.db", &dbt);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbt, "SELECT * FROM TRANS", -1, &stmt, NULL);
    int i=0;
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        i++;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbt);
    return i;
}