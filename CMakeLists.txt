cmake_minimum_required(VERSION 2.4.6)
SET(ROS_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")
FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(QGLViewer)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/src/
)

include_directories(~/src/OpenNI2/Include)
include_directories(~/src/OpenNI2/Samples/Common/)
include_directories(~/src/OpenNI2/Include/Linux-Arm)
link_directories(~/src/OpenNI2/Bin/Arm-Release)
link_directories(~/src/OpenNI2/Bin/x64-Release)
link_directories(~/src/OpenNI2/Redist)

SET(FORMS src/cyclops_window.ui)
QT4_WRAP_UI(FORM_HEADERS ${FORMS})
SET(HEADERS src/cyclops_window.h src/cyclops_viewer.h src/xtion.h)
QT4_WRAP_CPP(MOC ${HEADERS})
INCLUDE(${QT_USE_FILE})


ADD_EXECUTABLE(cyclops  src/cyclops.cpp src/cyclops_window.cpp src/cyclops_viewer.cpp src/xtion.cpp ${FORM_HEADERS} ${MOC})

TARGET_LINK_LIBRARIES(cyclops ${QGLVIEWER_LIBRARY_RELEASE} ${QT_LIBRARIES}  glut GLU GL OpenNI2)

