#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QTextEdit>
#include <QLabel>
#include "mylabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MyLabel * mLabel;
    QTextEdit * mEditor;

private slots:
    void applyLabel();
    void lable2TextEdit();

    void on_actionFolderOpen_triggered();
};

#endif // MAINWINDOW_H
