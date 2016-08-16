#-------------------------------------------------
#
# Project created by QtCreator 2016-08-03T09:54:01
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cube
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    lib_initial.cpp \
    lib_serial.cpp \
    lib_timer.cpp \
    lib_draw.cpp

HEADERS  += widget.h

FORMS    += widget.ui
