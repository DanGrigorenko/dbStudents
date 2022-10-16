#ifndef STUDENTSWINDOW_H
#define STUDENTSWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <customlineedit.h>

namespace Ui {
class StudentsWindow;
}

class StudentsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentsWindow(QWidget *parent = nullptr);
    ~StudentsWindow();

private slots:
    void on_action_triggered();

    void on_comboBox_3_activated(int index);

    void on_addButton_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::StudentsWindow *ui;
    CustomLineEdit *cLE = new CustomLineEdit();
    QString yParents, ySex, ySpecialization, ochForm;
    int seekElem = 0, idElem;
};

#endif // STUDENTSWINDOW_H
