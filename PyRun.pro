#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T18:40:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



TARGET = PyRun
TEMPLATE = app

SOURCES += main.cpp\
        mainview.cpp \
    pythonsyntaxhighlighter.cpp \
    codeeditor.cpp \
    snippets.cpp

HEADERS  += mainview.h \
    pythonsyntaxhighlighter.h \
    codeeditor.h \
    snippets.h \
    emb.h

FORMS    += mainview.ui

QMAKE_CXXFLAGS += -std=c++11


RESOURCES += \
    PyRunResources.qrc

RC_FILE = PyRun.rc



win32: LIBS += -L$$PWD/../Python34/libs/ -lpython34

INCLUDEPATH += $$PWD/../Python34/include
DEPENDPATH += $$PWD/../Python34/include
