#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include<QMessageBox>
#include<QtSql/QSqlDatabase>

QSqlDatabase db = QSqlDatabase :: addDatabase ("QMYSQL"); // Тип базы данных

bool createConnection()
{
     db.setHostName ("185.87.50.136"); // Имя хоста
     db.setDatabaseName ("Students"); // Имя базы данных
     db.setUserName ("user"); // Имя пользователя
     db.setPassword ("qwertyuiop"); // Пароль

    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open database",
                              "Unable to establish a database connection!",
                              QMessageBox::Cancel);
        return false;
    }
    //    QMessageBox::about(0,"",
    //                          "Database open, be yours a pleasant work!");
    db.open();
    return true;
}

#endif // DB_CONNECTION_H
