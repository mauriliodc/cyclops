#include "xtion.h"

XtionSensor::XtionSensor(){



}

void XtionSensor::run(){
    openni::Status rc = openni::STATUS_OK;
    openni::Device device;
    openni::VideoStream depth, color;
    const char* deviceURI = openni::ANY_DEVICE;
    rc = openni::OpenNI::initialize();
    printf("After initialization:\n%s\n", openni::OpenNI::getExtendedError());
    fflush(stdout);
    rc = device.open(deviceURI);
    rc = depth.create(device, openni::SENSOR_DEPTH);
    if (rc == openni::STATUS_OK)
    {
        rc = depth.start();
        if (rc != openni::STATUS_OK)
        {
            printf("SimpleViewer: Couldn't start depth stream:\n%s\n", openni::OpenNI::getExtendedError());
            fflush(stdout);
            depth.destroy();
        }
    }
    else
    {
        printf("SimpleViewer: Couldn't find depth stream:\n%s\n", openni::OpenNI::getExtendedError());
        fflush(stdout);
    }
    openni::VideoMode depthVideoMode;
    depthVideoMode = depth.getVideoMode();
    int depthWidth = depthVideoMode.getResolutionX();
    int depthHeight = depthVideoMode.getResolutionY();
    printf("%d %d \n",depthWidth, depthHeight);
    fflush(stdout);
    openni::VideoStream** m_streams = new openni::VideoStream*[2];
    m_streams[0] = &depth;
    while(1){
        int changedIndex;
        openni::Status rc = openni::OpenNI::waitForAnyStream(m_streams, 1, &changedIndex);
        depth.readFrame(&frame);
    }
}
