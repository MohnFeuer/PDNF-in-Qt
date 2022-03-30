#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<string>

using namespace std;

static bool createConnection(int n,int m, string * s,int** arr)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec("create table student (id int primary key, name vchar)");
    query.exec("insert into student values (0,'����')");
    query.exec("insert into student values (1,'�¸�')");
    query.exec("insert into student values (2,'����')");
    return true;
}


#endif // CONNECTION_H
