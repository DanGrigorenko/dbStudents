#ifndef MARKSWINDOW_H
#define MARKSWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>

namespace Ui {
class MarksWindow;
}

class MarksWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MarksWindow(QWidget *parent = nullptr);
    ~MarksWindow();

private slots:
    void on_pushButton_clicked();

    void on_action_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MarksWindow *ui;
    int seekElem = 0, idElem;
};

#endif // MARKSWINDOW_H
