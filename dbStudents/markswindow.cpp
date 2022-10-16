#include "markswindow.h"
#include "ui_markswindow.h"
#include <QSqlQuery>
#include <mainwindow.h>

MarksWindow::MarksWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarksWindow)
{
    ui->setupUi(this);

    ui->spinBox_4->setMaximum(10);

    ui->label->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QFont font = ui->label->font();
    font.setPointSize(22);
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: blue");

    QBoxLayout* codeStudent = new QBoxLayout(QBoxLayout::LeftToRight);
    codeStudent->addWidget(ui->label_2);
    codeStudent->addWidget(ui->spinBox);

    QBoxLayout* codeSubjects = new QBoxLayout(QBoxLayout::LeftToRight);
    codeSubjects->addWidget(ui->label_3);
    codeSubjects->addWidget(ui->spinBox_2);

    QBoxLayout* codeSpecialization = new QBoxLayout(QBoxLayout::LeftToRight);
    codeSpecialization->addWidget(ui->label_4);
    codeSpecialization->addWidget(ui->spinBox_3);

    QBoxLayout* markLy = new QBoxLayout(QBoxLayout::LeftToRight);
    markLy->addWidget(ui->label_5);
    markLy->addWidget(ui->spinBox_4);

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
    allLayout->addStretch(1);
    allLayout->addWidget(ui->label);
    allLayout->addSpacing(40);
    allLayout->addLayout(codeStudent);
    allLayout->addLayout(codeSubjects);
    allLayout->addLayout(codeSpecialization);
    allLayout->addLayout(markLy);
    allLayout->addSpacing(40);
    allLayout->addLayout(firstButton);
    allLayout->addLayout(secondButton);
    allLayout->addWidget(ui->pushButton_7);
    allLayout->addStretch(1);

    ui->centralwidget->setLayout(allLayout);

}

MarksWindow::~MarksWindow()
{
    delete ui;
}

void MarksWindow::on_pushButton_clicked()
{
    QSqlQuery query;
    query = QSqlQuery("INSERT INTO marks (Код_студента, Код_предмета, Код_специальности, Оценка)"
                      " VALUES('" + ui->spinBox->text() + "', '" + ui->spinBox_2->text() + "', '" + ui->spinBox_3->text() + "', '" + ui->spinBox_4->text() + "')");

    QSqlDatabase::database().commit() ;
}


void MarksWindow::on_action_triggered()
{
    auto w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    deleteLater();
}


void MarksWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM marks");
    query.first();
    ui->spinBox->setValue(query.value(1).toInt());
    ui->spinBox_2->setValue(query.value(2).toInt());
    ui->spinBox_3->setValue(query.value(3).toInt());
    ui->spinBox_4->setValue(query.value(4).toInt());
    seekElem = 0;
    idElem = query.value(0).toInt();
}


void MarksWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM marks");
    query.last();
    ui->spinBox->setValue(query.value(1).toInt());
    ui->spinBox_2->setValue(query.value(2).toInt());
    ui->spinBox_3->setValue(query.value(3).toInt());
    ui->spinBox_4->setValue(query.value(4).toInt());
    seekElem = query.size()-1;
    idElem = query.value(0).toInt();
}

void MarksWindow::on_pushButton_5_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM marks");
    query.seek(seekElem);
    ui->spinBox->setValue(query.value(1).toInt());
    ui->spinBox_2->setValue(query.value(2).toInt());
    ui->spinBox_3->setValue(query.value(3).toInt());
    ui->spinBox_4->setValue(query.value(4).toInt());
    if (seekElem != query.size()-1)
        ++seekElem;
    idElem = query.value(0).toInt();
}

void MarksWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM marks");
    query.seek(seekElem);
    ui->spinBox->setValue(query.value(1).toInt());
    ui->spinBox_2->setValue(query.value(2).toInt());
    ui->spinBox_3->setValue(query.value(3).toInt());
    ui->spinBox_4->setValue(query.value(4).toInt());
    if (seekElem != 0)
        --seekElem;
    idElem = query.value(0).toInt();
}

void MarksWindow::on_pushButton_6_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM marks WHERE id = :id");
    query.bindValue(":id", idElem);
    query.exec();
}


void MarksWindow::on_pushButton_7_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE marks SET Код_студента=:codeStud, Код_предмета=:codeSub, Код_специальности=:codeSpecial, Оценка=:codeMarks  WHERE id = :id");
    query.bindValue(":codeStud", ui->spinBox->text());
    query.bindValue(":codeSub", ui->spinBox_2->text());
    query.bindValue(":codeSpecial", ui->spinBox_3->text());
    query.bindValue(":codeMarks", ui->spinBox_4->text());
    query.bindValue(":id", idElem);
    query.exec();
}

