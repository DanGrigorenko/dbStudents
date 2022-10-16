#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QLayout>

namespace Ui {
class TableWindow;
}

class TableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = nullptr);
    ~TableWindow();

    void printTable(QString tableName);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_action_triggered();

private:
    Ui::TableWindow *ui;
    QSqlTableModel* model;
    QString nameTable = "students";
};

#endif // TABLEWINDOW_H
