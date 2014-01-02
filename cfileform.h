#ifndef CFILEFORM_H
#define CFILEFORM_H

#include <QWidget>
#include <QFileSystemModel>


namespace Ui {
class CFileForm;
}

class CFileForm : public QWidget
{
    Q_OBJECT

public:
    static CFileForm * getInstance()
    {
        if(NULL == pInstance)
            pInstance = new CFileForm;

        return pInstance;
    }
    /*static*/ void FreeInstance()
    {
        this->close();
        if(NULL != pInstance)
        {
            delete pInstance;
            pInstance = NULL;
        }
    }


    void setPath(const QString path);
    const QString getPath();

signals:
    void selectedFile();

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::CFileForm *ui;
    QFileSystemModel mFileView;
    static CFileForm * pInstance;
    QString selectedFilePath;

    CFileForm(QWidget *parent = 0);

    ~CFileForm() {}
    CFileForm(const CFileForm &);       //XX
    void operator =(const CFileForm &); //XX
};

#endif // CFILEFORM_H
