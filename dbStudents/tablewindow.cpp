#include "tablewindow.h"
#include "ui_tablewindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <mainwindow.h>

TableWindow::TableWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);

    printTable("students");

    QBoxLayout* tablesName = new QBoxLayout(QBoxLayout::LeftToRight);
    tablesName->addWidget(ui->pushButton_2);
    tablesName->addWidget(ui->pushButton_3);
    tablesName->addWidget(ui->pushButton_4);
    tablesName->addWidget(ui->pushButton_5);

    QBoxLayout* tableV = new QBoxLayout(QBoxLayout::TopToBottom);
    tableV->addWidget(ui->tableView);
    tableV->addLayout(tablesName);

    QBoxLayout* allLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    allLayout->addItem(tableV);

    ui->centralwidget->setLayout(allLayout);
}

TableWindow::~TableWindow()
{
    delete ui;
}

void TableWindow::printTable(QString tableName)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->select();
    model->setEditStrategy (QSqlTableModel :: OnManualSubmit); // Устанавливаем стратегию редактирования.
    ui->tableView->setModel(model);
    ui-> tableView->setEditTriggers (QAbstractItemView :: NoEditTriggers);
}

void TableWindow::on_pushButton_2_clicked()
{
     printTable("students");
}


void TableWindow::on_pushButton_3_clicked()
{
     printTable("marks");
}


void TableWindow::on_pushButton_4_clicked()
{
   printTable("specializations");
}


void TableWindow::on_pushButton_5_clicked()
{
    printTable("subjects");
}


void TableWindow::on_action_triggered()
{
    auto w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    deleteLater();
}

