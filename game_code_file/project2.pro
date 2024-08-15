#-------------------------------------------------
#
# Project created by QtCreator 2022-11-23T09:05:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
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


SOURCES += \
        main.cpp \
        widget.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    level.cpp \
    map.cpp \
    tower.cpp \
    levelboard.cpp \
    mapload_board.cpp \
    init.cpp \
    lab.cpp \
    frontboard.cpp \
    myapp.cpp \
    helper_func.cpp \
    mapmake_board.cpp \
    levelmake_board.cpp

HEADERS += \
        widget.h \
    bullet.h \
    enemy.h \
    game.h \
    level.h \
    map.h \
    tower.h \
    levelboard.h \
    mapload_board.h \
    init.h \
    lab.h \
    frontboard.h \
    myapp.h \
    helper_func.h \
    mapmake_board.h \
    levelmake_board.h

FORMS += \
        widget.ui
