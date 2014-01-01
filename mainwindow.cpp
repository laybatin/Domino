#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include <QtGui>
#include <QLayout>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::setWindowTitle("My App");

    QHBoxLayout * layout = new QHBoxLayout;

    QPushButton * btnEdit = new QPushButton("Edit");
    mEditor = new QTextEdit(this);


    mLabel = new MyLabel("ddd");
    mLabel->setText("한글!");
    layout->addWidget(mLabel);
    layout->addWidget(mEditor);
    layout->addWidget(btnEdit);


    mLabel->show();

    ui->centralWidget->setLayout(layout);

    mLabel->raise();


    //signals
    connect(btnEdit, SIGNAL(clicked()), this, SLOT(applyLabel()));
    connect(mLabel, SIGNAL(doubleClicked()), this, SLOT(lable2TextEdit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applyLabel()
{
    mLabel->setText( mEditor->toHtml() );
    mLabel->adjustSize();

    mEditor->clear();

}

void MainWindow::lable2TextEdit()
{
    mEditor->setText( mLabel->text() );
}
