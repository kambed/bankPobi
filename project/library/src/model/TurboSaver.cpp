#include "model/TurboSaver.h"
#include <exceptions/TurboSaverException.h>
#include <iostream>
#include <cstdlib>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include "model/Client.h"
#include "functions.h"
#include "managers/ClientManager.h"
#include "managers/TransactionManager.h"
#include "managers/AccountManager.h"
#include <string>
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
        sql = "CREATE TABLE CLIENT("
              "id                      TEXT PRIMARY KEY     NOT NULL, "
              "first_name              TEXT                 NOT NULL, "
              "last_name               TEXT                 NOT NULL, "
              "birth_date              INT                  NOT NULL);";
        caf = sqlite3_exec(dbca,sql.c_str(),NULL,0,&error);
        sql = "CREATE TABLE CLIENT("
              "id                      TEXT PRIMARY KEY     NOT NULL, "
              "first_name              TEXT                 NOT NULL, "
              "last_name               TEXT                 NOT NULL, "
              "birth_date              INT                  NOT NULL);";
        saf = sqlite3_exec(dbsa,sql.c_str(),NULL,0,&error);
        sql = "CREATE TABLE CLIENT("
              "id                      TEXT PRIMARY KEY     NOT NULL, "
              "first_name              TEXT                 NOT NULL, "
              "last_name               TEXT                 NOT NULL, "
              "birth_date              INT                  NOT NULL);";
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
    int cf = sqlite3_open("databases/clients.db", &dbc);
    sql = "DELETE FROM CLIENT WHERE id='"+client->getPersonalId()+"';";
    cf = sqlite3_exec(dbc,sql.c_str(),NULL,0,&error);
    sql = "INSERT INTO CLIENT VALUES('"+client->getPersonalId()+"', '"+client->getFirstName()+"', '"+client->getLastName()+"', '"+dateTimeToString(client->getBirthDate())+"');";
    cf = sqlite3_exec(dbc,sql.c_str(),NULL,0,&error);
    sqlite3_close(dbc);
}

void TurboSaver::importClient(ClientManagerPtr clientManager) {
    int cf = sqlite3_open("databases/clients.db", &dbc);
    //std::string query = "SELECT * FROM CLIENT;";
    //sqlite3_exec(dbc, query.c_str(), callback, NULL, NULL);
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(dbc, "SELECT * FROM CLIENT", -1, &stmt, NULL);
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string str,str2,str3,str4,str5,str6,str7;
        for(int i=0;i<strlen(reinterpret_cast<const char *>(sqlite3_column_text(stmt,0))); i++){
            str+=sqlite3_column_text(stmt,0)[i];
        }
        for(int i=0;i<strlen(reinterpret_cast<const char *>(sqlite3_column_text(stmt,1))); i++){
            str2+=sqlite3_column_text(stmt,1)[i];
        }
        for(int i=0;i<strlen(reinterpret_cast<const char *>(sqlite3_column_text(stmt,2))); i++){
            str3+=sqlite3_column_text(stmt,2)[i];
        }
        for(int i=0;i<strlen(reinterpret_cast<const char *>(sqlite3_column_text(stmt,3))); i++){
            str4+=sqlite3_column_text(stmt,3)[i];
        }
        str5=str4.substr(0,4);
        str6=str4.substr(5,3);
        std::string months[13];
        months[1]="Jan";
        months[2]="Feb";
        months[3]="Mar";
        months[4]="Apr";
        months[5]="May";
        months[6]="Jun";
        months[7]="Jul";
        months[8]="Aug";
        months[9]="Sep";
        months[10]="Oct";
        months[11]="Nov";
        months[12]="Dec";
        int month;
        for(int i=1;i<=12;i++){
            if(str6==months[i])
            {
                month=i;
            }
        }
        str7=str4.substr(9,2);
        clientManager->addClient(str,str2,str3,boost::posix_time::ptime(boost::gregorian::date(atoi(str5.c_str()),month,atoi(str7.c_str()))));
    }
    sqlite3_finalize(stmt);
    sqlite3_close(dbc);
}
