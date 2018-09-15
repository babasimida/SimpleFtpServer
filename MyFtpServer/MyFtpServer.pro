#-------------------------------------------------
#
# Project created by QtCreator 2018-09-02T10:12:10
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFtpServer
TEMPLATE = app


SOURCES += main.cpp\
        myftpserver.cpp \
    server.cpp \
    mysocket.cpp \
    ftpcmdanalysis.cpp

HEADERS  += myftpserver.h \
    server.h \
    mysocket.h \
    ftpcmdanalysis.h

FORMS    += myftpserver.ui
