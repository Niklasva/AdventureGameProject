#-------------------------------------------------
#
# Project created by QtCreator 2014-11-21T21:19:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameProjectInterface
TEMPLATE = app

CONFIG   += c++11

SOURCES += main.cpp\
        adventurewindow.cpp \
    Game.cpp \
    Player.cpp \
    Room.cpp \
    Item.cpp \
    Person.cpp \
    Merchant.cpp

HEADERS  += adventurewindow.h \
    Game.h \
    Player.h \
    Entity.h \
    Item.h \
    Object.h \
    Room.h \
    Person.h \
    Merchant.h

FORMS    += adventurewindow.ui
