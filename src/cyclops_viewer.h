#ifndef CYCLOPS_VIEWER
#define CYCLOPS_VIEWER

#include <QDialog>
#include <QThread>
#include <QLabel>
#include <QTime>
#include <QImage>
#include <QLineEdit>
#include <QGLViewer/qglviewer.h>
#include "xtion.h"
#include "imgui/imgui.h"
#include "imgui/malwrapper.h"

class CyclopsViewer : public QGLViewer
{
public:
    CyclopsViewer(QWidget *parent);
    XtionSensor* x;
private :
    virtual void draw();
    virtual void init();

};

#endif
