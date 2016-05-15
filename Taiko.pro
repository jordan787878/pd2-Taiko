#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T13:24:12
#
#-------------------------------------------------

QT       += core gui \
         multimedia  \
         multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    drum.cpp \
    beat.cpp \
    beat2.cpp \
    startwindow.cpp \
    score.cpp \
    overwindow.cpp \
    countdown.cpp \
    combo.cpp \
    song1.cpp \
    song1normal.cpp \
    song1devil.cpp \
    song2.cpp \
    hitpercent.cpp \
    beatcontinuous.cpp \
    song3.cpp \
    song2noraml.cpp

HEADERS  += \
    game.h \
    drum.h \
    beat.h \
    beat2.h \
    startwindow.h \
    score.h \
    overwindow.h \
    countdown.h \
    combo.h \
    song1.h \
    song1normal.h \
    song1devil.h \
    song2.h \
    hitpercent.h \
    beatcontinuous.h \
    song3.h \
    song2noraml.h

FORMS    +=

RESOURCES += \
    source.qrc
