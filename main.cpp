#include <QCoreApplication>
#include <dbmanager.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DbManager my_db;
    //my_db.AddRecord("niran");
    //my_db.update("niran","Amika");
    my_db.DeleteRow("Amika");

    return a.exec();
}
