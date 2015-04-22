#include "cyclops_viewer.h"

void CyclopsViewer::draw()
{
    ImGui_ImplGlfw_NewFrame();
    static float f = 0.0f;
    ImGui::Text("Hello, world!");
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::Render();

    glColor4f(0.3, 0.9, 0.9, 1.0);
    drawText(130, 35, QString("virtual laser test"), QFont("Helvetica [Cronyx]", 30));
    fflush(stdout);
    if(x!=0){
        const openni::DepthPixel* pDepthRow = (const openni::DepthPixel*)x->frame.getData();
        int rowSize = x->frame.getStrideInBytes() / sizeof(openni::DepthPixel);
        glBegin(GL_POINTS);
        printf("cose\n");
        fflush(stdout);
        for(int i =0;i<x->frame.getHeight();i++){
            const openni::DepthPixel* pDepth = pDepthRow;
            for(int j =0;j<x->frame.getWidth();j++){
                if (*pDepth != 0){
                    glVertex3f(i,j,((float)*pDepth)/1000.0f);
                    printf("%d %d %f\n",i,j,((float)*pDepth)/1000.0f );
                    fflush(stdout);
                }
            }
            pDepthRow += rowSize;
        }
        glEnd();
    }
}

void CyclopsViewer::init()
{
    ImGui_ImplGlfw_Init(this, true);
    setMouseTracking(true);
    setGrabsMouse()
    setGridIsDrawn();
    startAnimation();
    setSceneRadius(10);
    camera()->showEntireScene();
    //setBackgroundColor(QColor(29,15,29));
    setBackgroundColor(QColor(50,50,50));
    setForegroundColor(QColor(238,75,232));

}

CyclopsViewer::CyclopsViewer(QWidget *parent) : QGLViewer(parent)
{
    x=0;
}
