#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>

class DbManager
{
public:
    DbManager();
    bool AddRecord(const QString &name);

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
