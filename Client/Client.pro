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
    renderer.cpp \
    howtoplay.cpp

HEADERS  += client.h \
    login.h \
    renderer.h \
    howtoplay.h

FORMS    += client.ui \
    login.ui \
    howtoplay.ui

RESOURCES += \
    img.qrc

win32:RC_ICONS += maze.ico
