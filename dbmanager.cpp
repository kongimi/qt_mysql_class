#include "dbmanager.h"

DbManager::DbManager()
{
   m_db = QSqlDatabase::addDatabase("QMYSQL");
   m_db.setHostName("127.0.0.1");
   m_db.setUserName("exampleuser");
   m_db.setPassword("pimylifeup");
   m_db.setDatabaseName("exampledb");

   if (!m_db.open())
   {
      qDebug() << "Error: connection with database failed";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

bool DbManager::AddRecord(const QString& name){
    bool success = false;
   // you should check if args are ok first...
    QSqlQuery query;
    query.prepare("SELECT name FROM people WHERE name = (:name)");
    query.bindValue(":name", name);

    if (query.exec())
    {
       if (query.next())
       {
           qDebug() << "Person exist";
           return success;
       }else{
           query.prepare("INSERT INTO people (name) VALUES (:name)");
           query.bindValue(":name", name);
           if(query.exec())
           {
               success = true;
               qDebug() << "addPerson ok.";
           }
           else
           {
                qDebug() << "addPerson error:"
                         << query.lastError();
           }
       }
    }else{
        qDebug() << "addPerson error:"
                 << query.lastError();
    }

   return success;
}

bool DbManager::update(const QString &name_old, const QString &name_new){
    bool success = false;
    QSqlQuery query;
    query.prepare("UPDATE people SET name=(:name_new) WHERE name = (:name_old)");
    query.bindValue(":name_old", name_old);
    query.bindValue(":name_new", name_new);
    if(query.exec())
    {
        success = true;
        qDebug() << "update ok.";
    }
    else
    {
         qDebug() << "update error:"
                  << query.lastError();
    }
}

bool DbManager::DeleteRow(const QString &name){
    bool success = false;
    QSqlQuery query;
    query.prepare("DELETE FROM people WHERE name = (:name)");
    query.bindValue(":name", name);
    if(query.exec())
    {
        success = true;
        qDebug() << "delete ok.";
    }
    else
    {
         qDebug() << "delete error:"
                  << query.lastError();
    }
}
