#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlTableModel>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <studentswindow.h>
#include <subjectwindow.h>
#include <specializationwindow.h>
#include <markswindow.h>
#include <tablewindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void studentsButtonClicked();
    void subjectButtonClicked();
    void specializationButtonClicked();
    void marksButtonClicked();
    void tablesButtonClicked();
private:
    Ui::MainWindow *ui;
    QSqlTableModel* model;
    QLabel* title = new QLabel("База данных Студент");
    QPushButton* specializationButton = new QPushButton("Специальность");
    QPushButton* subjectsButton = new QPushButton("Предметы");
    QPushButton* studentsButton = new QPushButton("Студенты");
    QPushButton* marksButton = new QPushButton("Оценки");
    QPushButton* tablesButton = new QPushButton("Таблицы");
    StudentsWindow* stud;
    SubjectWindow* sub;
    SpecializationWindow* spec;
    TableWindow* tab;
    MarksWindow* mark;
    bool flagConnection = false;
};
#endif // MAINWINDOW_H
