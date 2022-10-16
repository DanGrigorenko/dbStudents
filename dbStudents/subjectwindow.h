#ifndef SUBJECTWINDOW_H
#define SUBJECTWINDOW_H

#include <QMainWindow>
#include <QLayout>

namespace Ui {
class SubjectWindow;
}

class SubjectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SubjectWindow(QWidget *parent = nullptr);
    ~SubjectWindow();

private slots:
    void on_pushButton_clicked();

    void on_action_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::SubjectWindow *ui;
    int seekElem = 0, idElem;
};

#endif // SUBJECTWINDOW_H
