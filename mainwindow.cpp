#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include <QtGui>
#include <QLayout>
#include <QPushButton>
#include <QTextCodec>
#include <QFileDialog>
#include <QtWidgets>
#include <QFontComboBox>
#include <QSpinBox>
#include <QPixmap>
#include "cfileform.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::setWindowTitle("My App");

    //이미지 변수 초기화
    mImage = nullptr;
    mBuffer = nullptr;

    QHBoxLayout * hLayout = new QHBoxLayout;
    QVBoxLayout * layout = new QVBoxLayout;
    QPushButton * btnEdit = new QPushButton("Edit");
    QPushButton * btnNew = new QPushButton("New");
    mFontBox = new QFontComboBox;
    mSpinFontSize = new QSpinBox;
    mSpinFontSize->setMinimum(5);
    mSpinFontSize->setMaximum(128);
    mSpinFontSize->setValue(12);



    //이미지 라벨 붙이기
    mImgLabel = new QLabel("Select File",this);
    mEditor = new QTextEdit(this);
    mLabel = new MyLabel("ddd");


    layout->addWidget(mImgLabel);
    layout->addWidget(mLabel);
    layout->addWidget(mEditor);

    hLayout->addWidget(btnEdit);
    hLayout->addWidget(btnNew);
    layout->addLayout(hLayout);


    ui->centralWidget->setLayout(layout);

    //mainToolBar 추가
    ui->mainToolBar->addWidget(mFontBox);
    ui->mainToolBar->addWidget(mSpinFontSize);

    //가장 위쪽에 위치하게 함
    mLabel->raise();

    //싱글톤
    m_pSingleFileView = CFileForm::getInstance();


    //signals    
    connect(btnEdit, SIGNAL(clicked()), this, SLOT(applyLabel()));
    connect(mLabel, SIGNAL(doubleClicked()), this, SLOT(lable2TextEdit()));
    connect(mSpinFontSize, SIGNAL(valueChanged(int)), this, SLOT( setFontSize()) );
    connect(mFontBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(setFontName()));

    //다른클래스로 시그널
    connect(m_pSingleFileView, SIGNAL(selectedFile()), this, SLOT(applyImgLabel()));




}

MainWindow::~MainWindow()
{

    m_pSingleFileView->FreeInstance();    
    m_pSingleFileView = NULL;
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

//CFileForm * fileView;

void MainWindow::on_actionFolderOpen_triggered()
{
    QFileDialog dlg;

    dlg.setFileMode( QFileDialog::Directory );
    selectedDir = dlg.getExistingDirectory();
    qDebug() << selectedDir;

    if(selectedDir.length())
    {
        m_pSingleFileView->setPath(selectedDir);
        m_pSingleFileView->show();
        m_pSingleFileView->setAttribute(Qt::WA_DeleteOnClose, true);
    }

//    fileView->getInstance();
//    fileView->setPath("C:\\");
//    fileView.setPath("C:\\");
//    fileView.show();




}

void MainWindow::applyImgLabel()
{
    //qDebug() << "ImgLabel";
    QString imgfile = m_pSingleFileView->getPath();
    qDebug() << imgfile;

    //이미지 라벨에 로딩
    if(mImage == nullptr)
        mImage = new QImage();

    if(mBuffer == nullptr)
        mBuffer = new QPixmap();

    if(mImage->load( imgfile ))
    {
        //이미지에 글자박기
//        QPainter * painter = new QPainter(img);

//        painter->setPen(Qt::blue);
//        painter->setFont(QFont("Arial",30));

//        painter->drawText(img->rect(), Qt::AlignCenter, "Text On Image");

        *mBuffer = QPixmap::fromImage(*mImage);
        *mBuffer = mBuffer->scaled(mImage->width(), mImage->height());

    }else
    {
        QMessageBox::about(0, "Image load error", "Image load Error");
    }


    mImgLabel->setPixmap(*mBuffer);
    mImgLabel->resize(mBuffer->width(), mBuffer->height());

    mImgLabel->show();
    MainWindow::adjustSize();

}

void MainWindow::setFontName()
{
    //qDebug() << mFontBox->currentFont().family();
    mFont.setFamily(mFontBox->currentFont().family());
    mEditor->setFont(mFont);


}

void MainWindow::setFontSize()
{
    //qDebug() << mSpinFontSize->value();

    mFont.setPointSize(mSpinFontSize->value());
    mFont.setFixedPitch(true);

    mEditor->setFont(mFont);

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_pSingleFileView->close();
}
