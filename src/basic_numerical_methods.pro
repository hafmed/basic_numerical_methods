#-------------------------------------------------
# HAF 19-6-2020
# on Qt 5.9.5 GCC 7.3.0; 64 bit Qt Creator 4.5.2 Ubuntu 18.4
# sudo apt install g++
# sudo apt install cmake
# sudo apt-get install libgl-dev
# sudo apt-get install qt5-default
#------------Make *.AppImage----------------------
# in the directorie : compilation
# chmod a+x linuxdeployqt-6-x86_64.AppImage
# ./linuxdeployqt-6-x86_64.AppImage basic_numerical_methods -appimage -qmake=/home/hafmed/Qt5.12.8/5.12.8/gcc_64/bin/qmake
#-------------------------------------------------

QT       += core gui
CONFIG += c++17
VERSION = 1.9.0  #2-9-2020
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QMAKE_CXXFLAGS += -std=c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = basic_numerical_methods
TEMPLATE = app

SOURCES += basic_numerical_methods.cpp \
    fparser.cc \
    fpoptimizer.cc \
 qcustomplot/qcustomplot.cpp \
    main.cpp

HEADERS  += basic_numerical_methods.h \
    fparser.hh \
    fpconfig.hh \
    qcustomplot/qcustomplot.h \
    extrasrc/fptypes.hh \
    extrasrc/fpaux.hh \
    constants.h

FORMS    += basic_numerical_methods.ui

RESOURCES += \
    qtresource.qrc

win32:RC_ICONS += basic_numerical_methods.ico

