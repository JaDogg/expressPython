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
    snippets.h

FORMS    += mainview.ui

QMAKE_CXXFLAGS += -std=c++11

win32: LIBS += -L$$PWD/../../TermPack/data/python/libs/ -lpython27

INCLUDEPATH += $$PWD/../../TermPack/data/python/include
DEPENDPATH += $$PWD/../../TermPack/data/python/include

RESOURCES += \
    PyRunResources.qrc

RC_FILE = windows_res.rc
