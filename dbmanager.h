#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>

class DbManager
{
public:
    DbManager();
    bool AddRecord(const QString &name);
    bool update(const QString &name_old, const QString &name_new);
    bool DeleteRow(const QString &name);

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
