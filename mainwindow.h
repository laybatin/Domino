#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QTextEdit>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QSpinBox>
#include <QFontComboBox>
#include <QFont>
#include <QFontMetrics>
#include "mylabel.h"

class CFileForm;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);


private:
    Ui::MainWindow *ui;
    MyLabel * mLabel;
    QTextEdit * mEditor;
    QLabel * mImgLabel;
    QString selectedDir;
    CFileForm * m_pSingleFileView;
    QPixmap * mBuffer;
    QImage * mImage;
    QSpinBox * mSpinFontSize;
    QFontComboBox * mFontBox;
    QFont mFont;


private slots:
    void applyLabel();
    void applyImgLabel();
    void lable2TextEdit();
    void on_actionFolderOpen_triggered();

    void setFontSize();
    void setFontName();


};

#endif // MAINWINDOW_H
