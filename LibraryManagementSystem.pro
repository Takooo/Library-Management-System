#-------------------------------------------------
#
# Project created by QtCreator 2017-05-01T09:46:33
#
#-------------------------------------------------

QT       += core sql gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RC_FILE =qtdemo.rc
TARGET = LibraryManagementSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    bookquery.cpp \
    normaluser.cpp \
    rootuser.cpp \
    regist.cpp \
    changecipher.cpp \
    insertsinglebook.cpp \
    insertgroupbook.cpp

HEADERS  += mainwindow.h \
    connection.h \
    login.h \
    bookquery.h \
    normaluser.h \
    rootuser.h \
    regist.h \
    changecipher.h \
    insertsinglebook.h \
    insertgroupbook.h

FORMS    += mainwindow.ui \
    login.ui \
    bookquery.ui \
    normaluser.ui \
    rootuser.ui \
    regist.ui \
    changecipher.ui \
    insertsinglebook.ui \
    insertgroupbook.ui

RESOURCES += \
    res.qrc
