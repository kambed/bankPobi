#include "model/TurboSaver.h"
#include <exceptions/TurboSaverException.h>
#include "model/Client.h"
#include "model/Account.h"
#include "model/Transaction.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "managers/AccountManager.h"
#include <boost/uuid/uuid_io.hpp>
#include "functions.h"

TurboSaver::TurboSaver() {
    std::system("mkdir -p ./databases");
    if(!fileExists("databases/database.db")) {
        int edb = sqlite3_open("databases/database.db", &db);
        open=1;
        if (edb) {
            std::string error = "Can't open database";
            error = error + sqlite3_errmsg(db);
            throw TurboSaverException(error);
        }
        sqlQuery = "CREATE TABLE CLIENT("
              "id                      TEXT PRIMARY KEY     NOT NULL, "
              "first_name              TEXT                 NOT NULL, "
              "last_name               TEXT                 NOT NULL, "
              "birth_date              TEXT                 NOT NULL);";
        edb = sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if (edb)
            throw TurboSaverException(error);
        sqlQuery = "CREATE TABLE CURRENTACC("
              "account_number          TEXT PRIMARY KEY     NOT NULL, "
              "savings_account_number  TEXT                 NOT NULL, "
              "client_id               TEXT                 NOT NULL, "
              "balance                 DOUBLE               NOT NULL, "
              "creation_date           TEXT                 NOT NULL);";
        edb = sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if (edb)
            throw TurboSaverException(error);
        sqlQuery = "CREATE TABLE SAVINGACC("
              "account_number          TEXT PRIMARY KEY     NOT NULL, "
              "current_account_number  TEXT                 NOT NULL, "
              "client_id               TEXT                 NOT NULL, "
              "balance                 DOUBLE               NOT NULL, "
              "creation_date           TEXT                 NOT NULL, "
              "last_interest           TEXT                 NOT NULL);";
        edb = sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if (edb)
            throw TurboSaverException(error);
        sqlQuery = "CREATE TABLE TRANS("
              "id                       TEXT PRIMARY KEY     NOT NULL, "
              "from_acc_number          TEXT                 NOT NULL, "
              "to_acc_number            TEXT                 NOT NULL, "
              "title                    TEXT                 NOT NULL, "
              "amount                   DOUBLE               NOT NULL);";
        edb = sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if (edb)
            throw TurboSaverException(error);
        sqlite3_close(db);
        open=0;
    }
}

void TurboSaver::saveClient(ClientPtr client) {
    if(open==0){
        int edb = sqlite3_open("databases/database.db", &db);
        open=1;
        if (edb){
            std::string error="Can't open database";
            error=error+sqlite3_errmsg(db);
            throw TurboSaverException(error);
        }
        sqlQuery = "DELETE FROM CLIENT WHERE id='" + client->getPersonalId() + "';";
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlQuery = "INSERT INTO CLIENT VALUES('" + client->getPersonalId() + "', '" + client->getFirstName() + "', '" + client->getLastName() + "', '" + dateTimeToString(client->getBirthDate()) + "');";
        sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlite3_close(db);
        open=0;
    }
}

void TurboSaver::saveSavingsAccount(AccountPtr account) {
    if(open==0){
        int edb = sqlite3_open("databases/database.db", &db);
        open=1;
        if (edb){
            std::string error="Can't open database";
            error=error+sqlite3_errmsg(db);
            throw TurboSaverException(error);
        }
        sqlQuery = "DELETE FROM SAVINGACC WHERE account_number='" + account->getAccountNumber() + "';";
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlQuery = "INSERT INTO SAVINGACC VALUES('" + account->getAccountNumber() + "', '" + account->getConnectedAccount()->getAccountNumber() + "', '" + account->getOwner()->getPersonalId() + "', '" + std::to_string(account->getBalance()) + "', '" + dateTimeToString(account->getCreationDate()) + "', '" + dateTimeToString(account->getLastInterest()) + "');";
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlite3_close(db);
        open=0;
    }
}

void TurboSaver::saveCurrentAccount(AccountPtr account) {
    if(open==0){
        int edb = sqlite3_open("databases/database.db", &db);
        open=1;
        if (edb){
            std::string error="Can't open database";
            error=error+sqlite3_errmsg(db);
            throw TurboSaverException(error);
        }
        sqlQuery = "DELETE FROM CURRENTACC WHERE account_number='" + account->getAccountNumber() + "';";
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        if(account->getConnectedAccount()==nullptr){
            sqlQuery = "INSERT INTO CURRENTACC VALUES('" + account->getAccountNumber() + "', '" + "-" + "', '" + account->getOwner()->getPersonalId() + "', '" + std::to_string(account->getBalance()) + "', '" + dateTimeToString(account->getCreationDate()) + "');";
        }else{
            sqlQuery = "INSERT INTO CURRENTACC VALUES('" + account->getAccountNumber() + "', '" + account->getConnectedAccount()->getAccountNumber() + "', '" + account->getOwner()->getPersonalId() + "', '" + std::to_string(account->getBalance()) + "', '" + dateTimeToString(account->getCreationDate()) + "');";
        }
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlite3_close(db);
        open=0;
    }
}

void TurboSaver::removeAccount(std::string accountNumber) {
    if(open==0){
        int edb = sqlite3_open("databases/database.db", &db);
        open=1;
        if (edb){
            std::string error="Can't open database";
            error=error+sqlite3_errmsg(db);
            throw TurboSaverException(error);
        }
        sqlQuery = "DELETE FROM SAVINGACC WHERE account_number='" + accountNumber + "';";
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlQuery = "DELETE FROM CURRENTACC WHERE account_number='" + accountNumber + "';";
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlite3_close(db);
        open=0;
    }
}

void TurboSaver::saveTransaction(TransactionPtr transaction) {
    if(open==0){
        int edb = sqlite3_open("databases/database.db", &db);
        open=1;
        if (edb){
            std::string error="Can't open database";
            error=error+sqlite3_errmsg(db);
            throw TurboSaverException(error);
        }
        sqlQuery = "DELETE FROM TRANS WHERE id='" + boost::lexical_cast<std::string>(transaction->getId()) + "';";
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlQuery = "INSERT INTO TRANS VALUES('" + boost::lexical_cast<std::string>(transaction->getId()) + "', '" + transaction->getAccountFrom()->getAccountNumber() + "', '" + transaction->getAccountTo()->getAccountNumber() + "', '" + transaction->getTitle() + "', '" + std::to_string(transaction->getAmount()) + "');";
        edb=sqlite3_exec(db, sqlQuery.c_str(), NULL, 0, &error);
        if(edb)
            throw TurboSaverException(error);
        sqlite3_close(db);
        open=0;
    }
}

void TurboSaver::importClients(ClientManagerPtr clientManager) {
    int edb = sqlite3_open("databases/database.db", &db);
    open=1;
    if (edb){
        std::string error="Can't open database";
        error=error+sqlite3_errmsg(db);
        throw TurboSaverException(error);
    }
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM CLIENT", -1, &stmt, NULL);
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
    sqlite3_close(db);
    open=0;
}
void TurboSaver::importTransactions(TransactionManagerPtr transactionManager,AccountManagerPtr accountManager) {
    int edb = sqlite3_open("databases/database.db", &db);
    open=1;
    if (edb){
        std::string error="Can't open database";
        error=error+sqlite3_errmsg(db);
        throw TurboSaverException(error);
    }
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM TRANS", -1, &stmt, NULL);
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
    sqlite3_close(db);
    open=0;
}

void TurboSaver::importCurrentAccounts(AccountManagerPtr accountManager,ClientManagerPtr clientManager) {
    int edb = sqlite3_open("databases/database.db", &db);
    open=1;
    if (edb){
        std::string error="Can't open database";
        error=error+sqlite3_errmsg(db);
        throw TurboSaverException(error);
    }
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM CURRENTACC", -1, &stmt, NULL);
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
    sqlite3_close(db);
    open=0;
}

void TurboSaver::importSavingsAccounts(AccountManagerPtr accountManager,ClientManagerPtr clientManager) {
    int edb = sqlite3_open("databases/database.db", &db);
    open=1;
    if (edb){
        std::string error="Can't open database";
        error=error+sqlite3_errmsg(db);
        throw TurboSaverException(error);
    }
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM SAVINGACC", -1, &stmt, NULL);
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
    sqlite3_close(db);
    open=0;
}

int TurboSaver::countClients() {
    int edb = sqlite3_open("databases/database.db", &db);
    open=1;
    if (edb){
        std::string error="Can't open database";
        error=error+sqlite3_errmsg(db);
        throw TurboSaverException(error);
    }
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM CLIENT", -1, &stmt, NULL);
    int i=0;
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        i++;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    open=0;
    return i;
}

int TurboSaver::countSavingsAccounts() {
    int edb = sqlite3_open("databases/database.db", &db);
    open=1;
    if (edb){
        std::string error="Can't open database";
        error=error+sqlite3_errmsg(db);
        throw TurboSaverException(error);
    }
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM SAVINGACC", -1, &stmt, NULL);
    int i=0;
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        i++;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    open=0;
    return i;
}

int TurboSaver::countCurrentAccounts() {
    int edb = sqlite3_open("databases/database.db", &db);
    open=1;
    if (edb){
        std::string error="Can't open database";
        error=error+sqlite3_errmsg(db);
        throw TurboSaverException(error);
    }
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM CURRENTACC", -1, &stmt, NULL);
    int i=0;
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        i++;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    open=0;
    return i;
}

int TurboSaver::countTransactions() {
    int edb = sqlite3_open("databases/database.db", &db);
    open=1;
    if (edb){
        std::string error="Can't open database";
        error=error+sqlite3_errmsg(db);
        throw TurboSaverException(error);
    }
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT * FROM TRANS", -1, &stmt, NULL);
    int i=0;
    while(sqlite3_step(stmt) == SQLITE_ROW) {
        i++;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    open=0;
    return i;
}
