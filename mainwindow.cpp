#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include <QtGui>
#include <QLayout>
#include <QPushButton>
#include <QTextCodec>
#include <QFileDialog>


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


    layout->addWidget(mLabel);
    layout->addWidget(mEditor);
    layout->addWidget(btnEdit);


    mLabel->show();

    ui->centralWidget->setLayout(layout);

    //가장 위쪽에 위치하게 함
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


void MainWindow::on_actionFolderOpen_triggered()
{
    QFileDialog dlg;
    QString selectedDir;
    dlg.setFileMode( QFileDialog::Directory );
    selectedDir = dlg.getExistingDirectory();
    qDebug() << selectedDir;
}
