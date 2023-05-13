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
# ./linuxdeployqt-7-x86_64.AppImage basic_numerical_methods -appimage -unsupported-allow-new-glibc
#-----------------on Manjaro-----15-5-2022--------------------------
# sudo pacman -S make
#-------------------------------------------------------------------
# https://doc.qt.io/qt-6/android-publishing-to-googleplay.html
#-----------------on Manjaro-----9-10-2022--------------------------
#if
#ERROR: ldd outputLine: "libjxl.so.0.7 => not found"
#ERROR: for binary: "/usr/lib/qt/plugins/imageformats/kimg_jxl.so"
#ERROR: Please ensure that all libraries can be found by ldd. Aborting.
#then
#sudo pacman -Syuu libjxl
#-------------------------------------------------------------------


QT       += core gui
CONFIG += c++17
VERSION = 4.5.9  #19-9-2020#19-5-2021#1-8-2021#21-8-2021#15-5-2022#10-6-2022#5-7-2022#9-8-2022#19-4-2023
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QMAKE_CXXFLAGS += -std=c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
android:DISTFILES += \
android-sources/AndroidManifest.xml \
android-sources/build.gradle

ANDROID_VERSION_CODE = 064459
ANDROID_TARGET_SDK_VERSION = 33
ANDROID_MIN_SDK_VERSION = 21

android:ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
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

DISTFILES += \
    android-sources/gradle.properties \
    android-sources/gradle.properties \
    android-sources/gradle/wrapper/gradle-wrapper.jar \
    android-sources/gradle/wrapper/gradle-wrapper.jar \
    android-sources/gradle/wrapper/gradle-wrapper.properties \
    android-sources/gradle/wrapper/gradle-wrapper.properties \
    android-sources/gradlew \
    android-sources/gradlew \
    android-sources/gradlew.bat \
    android-sources/gradlew.bat \
    android-sources/res/values/libs.xml \
    android-sources/res/values/libs.xml

