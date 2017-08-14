#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T13:29:12
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += testlib
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeamProject
TEMPLATE = app


SOURCES += main.cpp\
        mainsystem.cpp \
    login.cpp \
    workpage.cpp \
    workpagefunc.cpp \
    users.cpp \
    admin.cpp

HEADERS  += mainsystem.h \
    login.h \
    workpage.h \
    users.h \
    admin.h

FORMS    += mainsystem.ui \
    login.ui \
    workpage.ui \
    users.ui \
    admin.ui
RC_FILE  += logo.rc

RESOURCES += \
    bgimage.qrc

DISTFILES +=
