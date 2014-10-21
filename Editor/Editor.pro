#-------------------------------------------------
#
# Project created by QtCreator 2014-10-04T14:00:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Editor
TEMPLATE = app


SOURCES += main.cpp\
        editor.cpp \
    person_editor.cpp

HEADERS  += editor.h \
    person_editor.h

FORMS    += editor.ui

CONFIG += c++11
