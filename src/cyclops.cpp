#include <iostream>
#include <QApplication>
#include "cyclops_window.h"
#include "xtion.h"

int main(int argc, char **argv)
{
    std::cout<<"init"<<std::endl;
    QApplication qapp(argc, argv);

    XtionSensor* xs= new XtionSensor();
    xs->start();

    CyclopsWindow w;
    w.setXtion(xs);
    w.show();
    return qapp.exec();
}
