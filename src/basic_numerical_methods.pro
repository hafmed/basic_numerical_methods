#-------------------------------------------------
# HAF 19-6-2020
# on Qt 5.9.5 GCC 7.3.0; 64 bit Qt Creator 4.5.2 Ubuntu 18.4
# sudo apt install g++
# sudo apt install cmake
# sudo apt-get install libgl-dev
# sudo apt-get install qt5-default
#------------Make *.AppImage------on Manjaro-----1-8-2021-----------
# in the directorie : CompilationLinux
# chmod a+x linuxdeployqt-6-x86_64.AppImage
# ./linuxdeployqt-continuous-x86_64.AppImage basic_numerical_methods -appimage -unsupported-allow-new-glibc
#-------------------------------------------------

QT       += core gui
CONFIG += c++17
VERSION = 3.0.15  #19-9-2020#19-5-2021#1-8-2021
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QMAKE_CXXFLAGS += -std=c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = basic_numerical_methods
TEMPLATE = app
DEPLOYMENT_PATH = $${TARGET}
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

TRANSLATIONS = translations/qt_en.ts

RESOURCES += \
    qtresource.qrc \
    translations.qrc

win32:RC_ICONS += basic_numerical_methods.ico
