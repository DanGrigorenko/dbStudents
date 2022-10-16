#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Db_Connection.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createConnection();

    connect(studentsButton,SIGNAL(clicked()),this, SLOT(studentsButtonClicked()));
    connect(subjectsButton,SIGNAL(clicked()),this, SLOT(subjectButtonClicked()));
    connect(specializationButton,SIGNAL(clicked()),this, SLOT(specializationButtonClicked()));
    connect(marksButton,SIGNAL(clicked()),this, SLOT(marksButtonClicked()));
    connect(tablesButton,SIGNAL(clicked()),this, SLOT(tablesButtonClicked()));

    title->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(22);
    title->setFont(font);
    title->setStyleSheet("color: blue");

    QBoxLayout* pbxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    pbxLayout->setContentsMargins(200,5,200,5);
    pbxLayout->addStretch(1);
    pbxLayout->addWidget(title,1);
    pbxLayout->addWidget(specializationButton,1);
    pbxLayout->addSpacing(15);
    pbxLayout->addWidget(subjectsButton,1);
    pbxLayout->addSpacing(15);
    pbxLayout->addWidget(studentsButton,1);
    pbxLayout->addSpacing(15);
    pbxLayout->addWidget(marksButton,1);
    pbxLayout->addSpacing(15);
    pbxLayout->addWidget(tablesButton,1);
    pbxLayout->addStretch(1);

    ui->centralwidget->setLayout(pbxLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::studentsButtonClicked()
{
    stud = new StudentsWindow(this);

    stud->show();
    this->hide();
}

void MainWindow::subjectButtonClicked()
{
    sub = new SubjectWindow(this);
    sub->show();
    this->hide();
}

void MainWindow::specializationButtonClicked()
{
    spec = new SpecializationWindow(this);
    spec->show();
    this->hide();
}

void MainWindow::marksButtonClicked()
{
    mark = new MarksWindow(this);
    mark->show();
    this->hide();
}

void MainWindow::tablesButtonClicked()
{
    tab = new TableWindow(this);
    tab->show();
    this->hide();
}

