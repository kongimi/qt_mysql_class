#include <QCoreApplication>
#include <dbmanager.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DbManager my_db;

    return a.exec();
}
