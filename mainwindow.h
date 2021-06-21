#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Ui::MainWindow *ui;

signals:


private slots:


private:
    int refPos;
    int refVel;
    float kP;
    float kI;
    float kD;
    float t;

};

#endif // MAINWINDOW_H
