#include "specializationwindow.h"
#include "ui_specializationwindow.h"
#include <mainwindow.h>
#include <QSqlQuery>

SpecializationWindow::SpecializationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpecializationWindow)
{
    ui->setupUi(this);

    ui->label->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QFont font = ui->label->font();
    font.setPointSize(22);
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: blue");

    QBoxLayout* description = new QBoxLayout(QBoxLayout::TopToBottom);
    description->addWidget(ui->label_2);
    description->addWidget(ui->textEdit);

    QBoxLayout* firstButton = new QBoxLayout(QBoxLayout::LeftToRight);
    firstButton->addWidget(ui->pushButton_2);
    firstButton->addWidget(ui->pushButton_3);
    firstButton->addWidget(ui->pushButton);

    QBoxLayout* secondButton = new QBoxLayout(QBoxLayout::LeftToRight);
    secondButton->addWidget(ui->pushButton_4);
    secondButton->addWidget(ui->pushButton_5);
    secondButton->addWidget(ui->pushButton_6);

    QBoxLayout* allLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    allLayout->addWidget(ui->label);
    allLayout->addLayout(description);
    allLayout->addLayout(firstButton);
    allLayout->addLayout(secondButton);
    allLayout->addWidget(ui->pushButton_7);

    ui->centralwidget->setLayout(allLayout);
}

SpecializationWindow::~SpecializationWindow()
{
    delete ui;
}

void SpecializationWindow::on_action_triggered()
{
    auto w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    deleteLater();
}


void SpecializationWindow::on_pushButton_clicked()
{
    QString str= ui->textEdit->toPlainText();

    QSqlQuery query;
    query = QSqlQuery("INSERT INTO specializations (Описание)"
                      " VALUES('" + str + "')");

    QSqlDatabase::database().commit() ;
}


void SpecializationWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.exec("SELECT id, Описание FROM specializations");
    query.first();
    ui->textEdit->setText(query.value(1).toString());
    seekElem = 0;
    idElem = query.value(0).toInt();
}


void SpecializationWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    query.exec("SELECT id, Описание FROM specializations");
    query.last();
    ui->textEdit->setText(query.value(1).toString());
    seekElem = query.size()-1;
    idElem = query.value(0).toInt();
}


void SpecializationWindow::on_pushButton_5_clicked()
{
    QSqlQuery query;
    query.exec("SELECT id, Описание FROM specializations");
    query.seek(seekElem);
    ui->textEdit->setText(query.value(1).toString());
    if (seekElem != query.size()-1)
        ++seekElem;
    idElem = query.value(0).toInt();
}


void SpecializationWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("SELECT id, Описание FROM specializations");
    query.seek(seekElem);
    ui->textEdit->setText(query.value(1).toString());
    if (seekElem != 0)
        --seekElem;
    idElem = query.value(0).toInt();
}


void SpecializationWindow::on_pushButton_7_clicked()
{
    QString str =  ui->textEdit->toPlainText();
    QSqlQuery query;
    query.prepare("UPDATE specializations SET Описание = :text WHERE id = :id");
    query.bindValue(":text", str);
    query.bindValue(":id", idElem);
    query.exec();
}


void SpecializationWindow::on_pushButton_6_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM specializations WHERE id = :id");
    query.bindValue(":id", idElem);
    query.exec();
}

