#-------------------------------------------------
#
# Project created by QtCreator 2015-04-11T14:06:19
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    login.cpp \
    renderer.cpp

HEADERS  += client.h \
    login.h \
    renderer.h

FORMS    += client.ui \
    login.ui

RESOURCES += \
    img.qrc
