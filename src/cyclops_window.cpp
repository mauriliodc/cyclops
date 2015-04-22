#include "cyclops_window.h"
#include <iostream>
#include <fstream>


CyclopsWindow::CyclopsWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::CyclopsWindow)
{
    ui->setupUi(this);

}

void CyclopsWindow::setXtion(XtionSensor* x){
    printf("%x \n",this->ui->widget->x);
    this->ui->widget->x=x;
    printf("%x \n",this->ui->widget->x);
    fflush(stdout);
}


CyclopsWindow::~CyclopsWindow()
{
    delete ui;
}
