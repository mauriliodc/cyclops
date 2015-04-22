#ifndef XTION
#define XTION

#include <qthread.h>
#include <QObject>
#include <OpenNI.h>


using namespace openni;

class XtionSensor : public QThread
{
    Q_OBJECT
public:
    XtionSensor();
    openni::VideoFrameRef frame;
private:
    void run();
};


#endif
