TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    eventtest.cpp

RESOURCES += qml.qrc

CONFIG += c++11

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    eventtest.h
