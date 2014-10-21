#-------------------------------------------------
#
# Project created by QtCreator 2014-10-21T14:40:27
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = GameProject
CONFIG   += console
CONFIG   -= app_bundle
CONFIG    += c++11

TEMPLATE = app


SOURCES += main.cpp \
    Spel/Game.cc \
    Spel/Merchant.cc \
    Spel/Player.cc

OTHER_FILES += \
    Spel/spelfil.txt

HEADERS += \
    Spel/Entity.h \
    Spel/Game.h \
    Spel/Item.h \
    Spel/Object.h \
    Spel/Merchant.h \
    Spel/Person.h \
    Spel/Player.h \
    Spel/Room.h
