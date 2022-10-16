#include "studentswindow.h"
#include "ui_studentswindow.h"
#include <mainwindow.h>
#include <QSqlQuery>

StudentsWindow::StudentsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentsWindow)
{
    ui->setupUi(this);

    ui->lineEdit_4->setMaxLength(9);
    ui->lineEdit_5->setValidator(new QIntValidator);

    ui->label->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QFont font = ui->label->font();
    font.setPointSize(22);
    ui->label->setFont(font);
    ui->label->setStyleSheet("color: blue");

    QBoxLayout* fio = new QBoxLayout(QBoxLayout::LeftToRight);
    fio->addWidget(ui->label_2);
    fio->addWidget(ui->lineEdit);

    QBoxLayout* sex = new QBoxLayout(QBoxLayout::LeftToRight);
    sex->addWidget(ui->label_3);
    sex->addWidget(ui->comboBox);

    QBoxLayout* yParent = new QBoxLayout(QBoxLayout::LeftToRight);
    yParent->addWidget(ui->label_4);
    yParent->addWidget(ui->comboBox_2);

    QBoxLayout* adress = new QBoxLayout(QBoxLayout::LeftToRight);
    adress->addWidget(ui->label_5);
    adress->addWidget(ui->lineEdit_2);

    QBoxLayout* phone = new QBoxLayout(QBoxLayout::LeftToRight);
    phone->addWidget(ui->label_6);
    phone->addWidget(cLE);

    QBoxLayout* pasport = new QBoxLayout(QBoxLayout::LeftToRight);
    pasport->addWidget(ui->label_7);
    pasport->addWidget(ui->lineEdit_4);

    QBoxLayout* numberCard = new QBoxLayout(QBoxLayout::LeftToRight);
    numberCard->addWidget(ui->label_8);
    numberCard->addWidget(ui->lineEdit_5);

    QBoxLayout* group = new QBoxLayout(QBoxLayout::LeftToRight);
    group->addWidget(ui->label_9);
    group->addWidget(ui->lineEdit_6);

    QBoxLayout* course = new QBoxLayout(QBoxLayout::LeftToRight);
    course->addWidget(ui->label_10);
    course->addWidget(ui->spinBox);

    QBoxLayout* codeSpecialization = new QBoxLayout(QBoxLayout::LeftToRight);
    codeSpecialization->addWidget(ui->label_11);
    codeSpecialization->addWidget(ui->comboBox_3);

    QBoxLayout* firstButton = new QBoxLayout(QBoxLayout::LeftToRight);
    firstButton->addWidget(ui->pushButton_2);
    firstButton->addWidget(ui->pushButton_3);
    firstButton->addWidget(ui->addButton);

    QBoxLayout* secondButton = new QBoxLayout(QBoxLayout::LeftToRight);
    secondButton->addWidget(ui->pushButton_4);
    secondButton->addWidget(ui->pushButton_5);
    secondButton->addWidget(ui->pushButton_6);

    QBoxLayout* allLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    allLayout->addStretch(1);
    allLayout->addWidget(ui->label);
    allLayout->addSpacing(40);
    allLayout->addLayout(fio);
    allLayout->addLayout(sex);
    allLayout->addLayout(yParent);
    allLayout->addLayout(adress);
    allLayout->addLayout(phone);
    allLayout->addLayout(pasport);
    allLayout->addLayout(numberCard);
    allLayout->addLayout(group);
    allLayout->addLayout(course);
    allLayout->addLayout(codeSpecialization);
    allLayout->addWidget(ui->checkBox);
    allLayout->addSpacing(40);
    allLayout->addLayout(firstButton);
    allLayout->addLayout(secondButton);
    allLayout->addWidget(ui->pushButton_7);
    allLayout->addStretch(1);

    ui->centralwidget->setLayout(allLayout);

    ui->spinBox->setMaximum(4);
}

StudentsWindow::~StudentsWindow()
{
    delete ui;
}

void StudentsWindow::on_action_triggered()
{
    auto w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    deleteLater();
}

void StudentsWindow::on_comboBox_3_activated(int index)
{
    if (index == 0) {
         ui->spinBox->setMaximum(4);
         ySpecialization = "ПОИТ    ";
    }
    else if(index == 1) {
         ui->spinBox->setMaximum(3);
         ySpecialization = "Правоведы";
    }
    else if(index == 2) {
         ui->spinBox->setMaximum(3);
         ySpecialization = "Бухгалтерское дело";
    }
    else if(index == 3) {
         ui->spinBox->setMaximum(3);
         ySpecialization = "Логисты";
    }
}

void StudentsWindow::on_addButton_clicked()
{
    if (ui->checkBox->isChecked())
        ochForm = "1";
    else
        ochForm = "0";

    QSqlQuery query;
    query = QSqlQuery("INSERT INTO students (ФИО, Пол, Родители, Адрес, Телефон, Паспорт, Номер_Зачетки, Группа, Курс, Специальность, Очная)"
                      " VALUES('" + ui->lineEdit->text() + "', '" + ySex + "', '" + yParents + "', '" + ui->lineEdit_2->text() + "', '" + cLE->text() + "', '" + ui->lineEdit_4->text() + "', '" + ui->lineEdit_5->text() + "', '" + ui->lineEdit_6->text() + "', '" + ui->spinBox->text() + "', '" + ySpecialization + "', '" + ochForm + "')");

    QSqlDatabase::database().commit() ;
}

void StudentsWindow::on_comboBox_activated(int index)
{
    if (index == 0)
        ySex = "Оно";
    else if (index == 1)
        ySex = "Женский";
    else
        ySex = "Мужской";
}

void StudentsWindow::on_comboBox_2_activated(int index)
{
    if (index == 0)
        yParents = "Отсутствоют";
    else if (index == 1)
        yParents = "Мать и Отец";
    else if (index == 2)
        yParents = "Мать";
    else if (index == 3)
        yParents = "Отец";
    else if (index == 4)
        yParents = "Отец и Отец";
    else
        yParents = "Мать и Мать";
}

void StudentsWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM students");
    query.first();
    int index1 = ui->comboBox->findText(query.value(2).toString());
    int index2 = ui->comboBox_2->findText(query.value(3).toString());
    int index3 = ui->comboBox_3->findText(query.value(10).toString());

    ui->lineEdit->setText(query.value(1).toString());
    ui->comboBox->setCurrentIndex(index1);
    ui->comboBox_2->setCurrentIndex(index2);
    ui->lineEdit_2->setText(query.value(4).toString());
    cLE->setText(query.value(5).toString());
    ui->lineEdit_4->setText(query.value(6).toString());
    ui->lineEdit_5->setText(query.value(7).toString());
    ui->lineEdit_6->setText(query.value(8).toString());
    ui->spinBox->setValue(query.value(9).toInt());
    ui->comboBox_3->setCurrentIndex(index3);
    if (query.value(11).toInt() == 1)
        ui->checkBox->setChecked(true);
    else
        ui->checkBox->setChecked(false);;
    seekElem = 0;
    idElem = query.value(0).toInt();
}

void StudentsWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM students");
    query.last();
    int index1 = ui->comboBox->findText(query.value(2).toString());
    int index2 = ui->comboBox_2->findText(query.value(3).toString());
    int index3 = ui->comboBox_3->findText(query.value(10).toString());

    ui->lineEdit->setText(query.value(1).toString());
    ui->comboBox->setCurrentIndex(index1);
    ui->comboBox_2->setCurrentIndex(index2);
    ui->lineEdit_2->setText(query.value(4).toString());
    cLE->setText(query.value(5).toString());
    ui->lineEdit_4->setText(query.value(6).toString());
    ui->lineEdit_5->setText(query.value(7).toString());
    ui->lineEdit_6->setText(query.value(8).toString());
    ui->spinBox->setValue(query.value(9).toInt());
    ui->comboBox_3->setCurrentIndex(index3);
    if (query.value(11).toInt() == 1)
        ui->checkBox->setChecked(true);
    else
        ui->checkBox->setChecked(false);;
    seekElem = query.size()-1;
    idElem = query.value(0).toInt();
}

void StudentsWindow::on_pushButton_5_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM students");
    query.seek(seekElem);
    int index1 = ui->comboBox->findText(query.value(2).toString());
    int index2 = ui->comboBox_2->findText(query.value(3).toString());
    int index3 = ui->comboBox_3->findText(query.value(10).toString());

    ui->lineEdit->setText(query.value(1).toString());
    ui->comboBox->setCurrentIndex(index1);
    ui->comboBox_2->setCurrentIndex(index2);
    ui->lineEdit_2->setText(query.value(4).toString());
    cLE->setText(query.value(5).toString());
    ui->lineEdit_4->setText(query.value(6).toString());
    ui->lineEdit_5->setText(query.value(7).toString());
    ui->lineEdit_6->setText(query.value(8).toString());
    ui->spinBox->setValue(query.value(9).toInt());
    ui->comboBox_3->setCurrentIndex(index3);
    if (query.value(11).toInt() == 1)
        ui->checkBox->setChecked(true);
    else
        ui->checkBox->setChecked(false);

    if (seekElem != query.size()-1)
        ++seekElem;
    idElem = query.value(0).toInt();
}

void StudentsWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM students");
    query.seek(seekElem);
    query.seek(seekElem);
    int index1 = ui->comboBox->findText(query.value(2).toString());
    int index2 = ui->comboBox_2->findText(query.value(3).toString());
    int index3 = ui->comboBox_3->findText(query.value(10).toString());

    ui->lineEdit->setText(query.value(1).toString());
    ui->comboBox->setCurrentIndex(index1);
    ui->comboBox_2->setCurrentIndex(index2);
    ui->lineEdit_2->setText(query.value(4).toString());
    cLE->setText(query.value(5).toString());
    ui->lineEdit_4->setText(query.value(6).toString());
    ui->lineEdit_5->setText(query.value(7).toString());
    ui->lineEdit_6->setText(query.value(8).toString());
    ui->spinBox->setValue(query.value(9).toInt());
    ui->comboBox_3->setCurrentIndex(index3);
    if (query.value(11).toInt() == 1)
        ui->checkBox->setChecked(true);
    else
        ui->checkBox->setChecked(false);

    if (seekElem != 0)
        --seekElem;
    idElem = query.value(0).toInt();
}

void StudentsWindow::on_pushButton_6_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM students WHERE id = :id");
    query.bindValue(":id", idElem);
    query.exec();
}

void StudentsWindow::on_pushButton_7_clicked()
{
    if (ui->checkBox->isChecked())
        ochForm = "1";
    else
        ochForm = "0";

    QSqlQuery query;
    query.prepare("UPDATE students SET ФИО=:fio, Пол=:sex, Родители=:parants, Адрес=:adres, Телефон=:phone, Паспорт=:pasport, Номер_Зачетки=:codeBilet, Группа=:group, Курс=:course, Специальность=:special, Очная=:och  WHERE id = :id");
    query.bindValue(":fio", ui->lineEdit->text());
    query.bindValue(":sex", ySex);
    query.bindValue(":parants", yParents);
    query.bindValue(":adres", ui->lineEdit_2->text());
    query.bindValue(":phone", cLE->text());
    query.bindValue(":pasport", ui->lineEdit_4->text());
    query.bindValue(":codeBilet", ui->lineEdit_5->text());
    query.bindValue(":group", ui->lineEdit_6->text());
    query.bindValue(":course", ui->spinBox->text());
    query.bindValue(":special", ySpecialization);
    query.bindValue(":och", ochForm);
    query.bindValue(":id", idElem);
    query.exec();
}

