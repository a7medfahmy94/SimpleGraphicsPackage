#-------------------------------------------------
#
# Project created by QtCreator 2015-03-01T14:06:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicsProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    line.cpp \
    file.cpp \
    shape.cpp \
    helper.cpp \
    linecartesian.cpp \
    lineparametric.cpp \
    linedda.cpp \
    shapecontroller.cpp \
    circle.cpp \
    circlecartesian.cpp \
    drawalgo.cpp \
    circledda.cpp \
    circlepolar.cpp \
    circlemidpoint.cpp

HEADERS  += mainwindow.h \
    line.h \
    file.h \
    shape.h \
    helper.h \
    drawalgo.h \
    linecartesian.h \
    lineparametric.h \
    linedda.h \
    shapecontroller.h \
    circlecartesian.h \
    circle.h \
    circledda.h \
    circlepolar.h \
    circlemidpoint.h

FORMS    += mainwindow.ui
