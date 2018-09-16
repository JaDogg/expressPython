#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T18:40:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = expressPython
TEMPLATE = app

SOURCES += main.cpp\
        UI/mainview.cpp \
    CodeEditor/pythonsyntaxhighlighter.cpp \
    CodeEditor/codeeditor.cpp \
    Features/snippets.cpp \
    PythonAccess/emb.cpp \
    PythonAccess/pythonworker.cpp \
    CodeEditor/codelineedit.cpp \
    Features/xquestion.cpp \
    Features/xtute.cpp

HEADERS  += UI/mainview.h \
    CodeEditor/pythonsyntaxhighlighter.h \
    CodeEditor/codeeditor.h \
    Features/snippets.h \
    PythonAccess/emb.h \
    PythonAccess/pythonworker.h \
    CodeEditor/codelineedit.h \
    Features/xquestion.h \
    Features/xtute.h

FORMS    += UI/mainview.ui

RESOURCES += \
    PyRunResources.qrc

RC_FILE = WindowsResources/win_rsrc.rc


win32: LIBS += -LD:\Python\Python36-32\libs\ -lpython36
win32: INCLUDEPATH += D:\Python\Python36-32\include
win32: DEPENDPATH += D:\Python\Python36-32\include

greaterThan(QT_MAJOR_VERSION, 4){
    CONFIG += c++11
} else {
    QMAKE_CXXFLAGS += -std=c++11 -Wpedantic
}
