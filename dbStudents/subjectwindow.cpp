#include "subjectwindow.h"
#include "ui_subjectwindow.h"
#include <QSqlQuery>
#include <mainwindow.h>

SubjectWindow::SubjectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubjectWindow)
{
    ui->setupUi(this);

    ui->label->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QFont font = ui->label->font();
    font.setPointSize(22);
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: blue");

    QBoxLayout* nameSub = new QBoxLayout(QBoxLayout::LeftToRight);
    nameSub->addWidget(ui->label_2);
    nameSub->addWidget(ui->lineEdit);

    QBoxLayout* description = new QBoxLayout(QBoxLayout::LeftToRight);
    description->addWidget(ui->label_3);
    description->addSpacing(40);
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
    allLayout->setContentsMargins(50,50,50,5);
    allLayout->addWidget(ui->label);
    allLayout->addSpacing(40);
    allLayout->addStretch(1);
    allLayout->addLayout(nameSub);
    allLayout->addLayout(description);
    allLayout->addSpacing(40);
    allLayout->addLayout(firstButton);
    allLayout->addLayout(secondButton);
    allLayout->addWidget(ui->pushButton_7);
    allLayout->addStretch(1);

    ui->centralwidget->setLayout(allLayout);
}

SubjectWindow::~SubjectWindow()
{
    delete ui;
}

void SubjectWindow::on_pushButton_clicked()
{
    QString str= ui->textEdit->toPlainText();

    QSqlQuery query;
    query = QSqlQuery("INSERT INTO subjects (Наименование, Описание)"
                      " VALUES('" + ui->lineEdit->text() + "', '" + str + "')");

    QSqlDatabase::database().commit() ;
}


void SubjectWindow::on_action_triggered()
{
    auto w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    deleteLater();
}

void SubjectWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM subjects");
    query.first();
    ui->lineEdit->setText(query.value(1).toString());
    ui->textEdit->setText(query.value(2).toString());
    seekElem = 0;
    idElem = query.value(0).toInt();
}

void SubjectWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM subjects");
    query.last();
    ui->lineEdit->setText(query.value(1).toString());
    ui->textEdit->setText(query.value(2).toString());
    seekElem = query.size()-1;
    idElem = query.value(0).toInt();
}

void SubjectWindow::on_pushButton_5_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM subjects");
    query.seek(seekElem);
    ui->lineEdit->setText(query.value(1).toString());
    ui->textEdit->setText(query.value(2).toString());
    if (seekElem != query.size()-1)
        ++seekElem;
    idElem = query.value(0).toInt();
}

void SubjectWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM subjects");
    query.seek(seekElem);
    ui->lineEdit->setText(query.value(1).toString());
    ui->textEdit->setText(query.value(2).toString());
    if (seekElem != 0)
        --seekElem;
    idElem = query.value(0).toInt();
}

void SubjectWindow::on_pushButton_7_clicked()
{
    QString str =  ui->textEdit->toPlainText();
    QSqlQuery query;
    query.prepare("UPDATE subjects SET Наименование=:name, Описание = :text WHERE id = :id");
    query.bindValue(":name", ui->lineEdit->text());
    query.bindValue(":text", str);
    query.bindValue(":id", idElem);
    query.exec();
}

void SubjectWindow::on_pushButton_6_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM subjects WHERE id = :id");
    query.bindValue(":id", idElem);
    query.exec();
}

