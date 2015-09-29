#-------------------------------------------------
#
# Project created by QtCreator 2015-09-28T17:43:05
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = videoGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    videowidget.cpp

HEADERS  += mainwindow.h \
    videowidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
