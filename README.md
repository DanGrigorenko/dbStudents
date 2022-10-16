# Приложение "_База данных студенты_"

## Описание
Это desktop приложения под ОС Linux Ubuntu 20.04 и выше. Целью было разработать реляционную базу данных.
___

## Инструменты
+ С++ 17
+ Qt/QT Creator
+ Standard Template Library (STL)
+ Figma
+ MySql
___

## Функционал приложения
Приложение состоит из 6 окон:
1. Меню
2. Специльность
3. Предметы
4. Студенты 
5. Оценки
6. Таблицы

В каждом окне кроме "_Меню_" и "_Таблицы_" мы можем загружать данные из БД в любой очередности, добавлять, изменять и удалять.

В окне "_Таблицы_" загружаются все таблицы из БД, где мы можем переключатся между ними и наблюдать какие и где данные хранятся.
___

## Запуск 

Для запуска приложения необходимо иметь ОС Linux Ubuntu 20.04 и выше, а также установленный Qt Creator с версией Qt 5 и выше.
___

## Подключение БД
Так как MySql является удаленной базой данных, то кроме кроме название БД, необходимо знать:
+ Имя хоста
+ Имя пользователя
+ Пароль

Для удобного подключения к БД был написан заголовочный файл `Db_Connection_h`, в котором был реализован метод `createConnection()`.

Фрагмент кода реализации подключения:
```C++
static bool createConnection()
{
         QSqlDatabase db = QSqlDatabase :: addDatabase ("QMYSQL"); // Тип базы данных
         db.setHostName ("localhost"); // Имя хоста
         db.setDatabaseName ("phm_db"); // Имя базы данных
         db.setUserName ("root"); // Имя пользователя
         db.setPassword ("123456"); // Пароль
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open database",
                              "Unable to establish a database connection",
                              QMessageBox::Cancel);
        return false;
    }
    db.open();
    return true;
```
