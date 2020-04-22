#-------------------------------------------------
# Project created by QtCreator 2014-11-22T18:40:41
#
# expressPython
#   - Bhathiya Perera
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
    Features/xtute.cpp \
    PythonAccess/jedi.cpp

HEADERS  += UI/mainview.h \
    CodeEditor/pythonsyntaxhighlighter.h \
    CodeEditor/codeeditor.h \
    Features/snippets.h \
    PythonAccess/emb.h \
    PythonAccess/pythonworker.h \
    CodeEditor/codelineedit.h \
    Features/xquestion.h \
    Features/xtute.h \
    PythonAccess/jedi.h

FORMS    += UI/mainview.ui

# Include useful images, built-ins
RESOURCES += \
    PyRunResources.qrc

# Windows specific config
win32: PYTHON37_LOCATION = $$(PYTHON37_LOCATION)
win32: message($$PYTHON37_LOCATION)
win32: RC_FILE = WindowsResources/win_rsrc.rc
win32: LIBS += -L$${PYTHON37_LOCATION}\libs\ -lpython37
win32: INCLUDEPATH += $${PYTHON37_LOCATION}\include
win32: DEPENDPATH += $${PYTHON37_LOCATION}\include

# MacOS specific config
macx: PYTHON37_LIB_LOCATION = $$(PYTHON37_LIB_LOCATION)
# If installed with brew it looks like: /usr/local/Cellar/python/3.7.0/Frameworks/Python.framework/Versions/3.7/lib
macx: PYTHON37_INC_LOCATION = $$(PYTHON37_INC_LOCATION)
# If installed with brew it looks like: /usr/local/Cellar/python/3.7.0/Frameworks/Python.framework/Versions/3.7/include/python3.7m
macx: LIBS += -L$${PYTHON37_LIB_LOCATION} -lpython3.7
macx: INCLUDEPATH += $${PYTHON37_INC_LOCATION}
macx: DEPENDPATH += $${PYTHON37_INC_LOCATION}
macx: ICON = Icons/PyRunImg.icns

unix: PYTHON3_LIB_LOCATION = $$(PYTHON3_LIB_LOCATION)
unix: PYTHON3_INC_LOCATION = $$(PYTHON3_INC_LOCATION)
unix: LIBS += PYTHON3_LIB_LOCATION
unix: INCLUDEPATH += PYTHON3_INC_LOCATION
unix: DEPENDPATH += PYTHON3_INC_LOCATION

greaterThan(QT_MAJOR_VERSION, 4){
    CONFIG += c++11
} else {
    QMAKE_CXXFLAGS += -std=c++11 -Wpedantic
}
