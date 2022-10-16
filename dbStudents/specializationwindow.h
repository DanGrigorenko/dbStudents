#ifndef SPECIALIZATIONWINDOW_H
#define SPECIALIZATIONWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>

namespace Ui {
class SpecializationWindow;
}

class SpecializationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpecializationWindow(QWidget *parent = nullptr);
    ~SpecializationWindow();

private slots:
    void on_action_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::SpecializationWindow *ui;
    int seekElem = 0, idElem;
};

#endif // SPECIALIZATIONWINDOW_H
