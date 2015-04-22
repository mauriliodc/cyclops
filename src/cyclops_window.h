#ifndef CYCLOPS_WINDOW
#define CYCLOPS_WINDOW
#include <QDialog>
#include <QMainWindow>
#include <QThread>
#include <QLabel>
#include <QTime>
#include <QImage>
#include "ui_cyclops_window.h"
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include "xtion.h"
namespace Ui {
    class CyclopsWindow;
}


class CyclopsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CyclopsWindow(QWidget *parent = 0);
    ~CyclopsWindow();
    void setXtion(XtionSensor* x);
private:
    Ui::CyclopsWindow *ui;

};

#endif
