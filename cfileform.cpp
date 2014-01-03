#include "cfileform.h"
#include "ui_cfileform.h"
#include <QDebug>
namespace ExtName
{
    enum
    {
        BEGIN,
        jpg = BEGIN,
        png,
        gif,
        bmp,
        END = bmp,
        CNT = END + 1
    };

    const QString STRING[CNT]=
    {
        "*.jpg", "*.png", "*.gif", "*.bmp"
    };
}


CFileForm::CFileForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CFileForm)
{
    ui->setupUi(this);
    ui->listView->setModel(&this->mFileView);
    this->mFileView.setFilter(QDir::Files);

    //확장자 제한
    QStringList filters;
    for(unsigned int i = ExtName::BEGIN; i<ExtName::CNT; i++)
        filters << ExtName::STRING[i];


    this->mFileView.setNameFilters(filters);


    //이름순 정렬
    //this->mFileView.sort(0, Qt::DescendingOrder);
    //connect(listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT()
}

//CFileForm::~CFileForm()
//{
//    delete ui;
//}

CFileForm * CFileForm::pInstance = NULL;

void CFileForm::setPath(const QString path)
{
    //qDebug() << "path = " << path;
    this->mFileView.setRootPath(path);

    ui->listView->setRootIndex(mFileView.setRootPath(path));

}

void CFileForm::on_listView_doubleClicked(const QModelIndex &index)
{
    selectedFilePath =  mFileView.fileInfo(index).absoluteFilePath();
    //MainWindow의 mImgLabel에 selectedFilePath를 전달해야 함
    emit selectedFile();

}

const QString CFileForm::getPath()
{
    return selectedFilePath;
}

