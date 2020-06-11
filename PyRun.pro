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
    ANTLR/customtoken.cpp \
    UI/mainview.cpp \
    CodeEditor/antlrsyntaxhighlighter.cpp \
    CodeEditor/codeeditor.cpp \
    Features/snippets.cpp \
    PythonAccess/emb.cpp \
    PythonAccess/pythonworker.cpp \
    CodeEditor/codelineedit.cpp \
    Features/xquestion.cpp \
    Features/xtute.cpp \
    PythonAccess/jedi.cpp \
    ANTLR/Python3BaseListener.cpp \
    ANTLR/Python3Lexer.cpp \
    ANTLR/Python3Listener.cpp \
    ANTLR/Python3Parser.cpp

HEADERS  += UI/mainview.h \
    ANTLR/customtoken.h \
    CodeEditor/antlrsyntaxhighlighter.h \
    CodeEditor/codeeditor.h \
    Features/snippets.h \
    PythonAccess/emb.h \
    PythonAccess/pythonworker.h \
    CodeEditor/codelineedit.h \
    Features/xquestion.h \
    Features/xtute.h \
    PythonAccess/jedi.h \
    ANTLR/Python3BaseListener.h \
    ANTLR/Python3Lexer.h \
    ANTLR/Python3Listener.h \
    ANTLR/Python3Parser.h

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
macx: LIBS += -L$${PYTHON37_LIB_LOCATION} -lpython3.7 -lqtermwidget5 /usr/local/lib/libantlr4-runtime.so.4.8
macx: INCLUDEPATH += $${PYTHON37_INC_LOCATION} /usr/local/include/antlr4-runtime/
macx: DEPENDPATH += $${PYTHON37_INC_LOCATION} /usr/local/include/antlr4-runtime/
macx: ICON = Icons/PyRunImg.icns

unix: PYTHON3_LIB_LOCATION = $$(PYTHON3_LIB_LOCATION)
unix: PYTHON3_INC_LOCATION = $$(PYTHON3_INC_LOCATION)
unix: LIBS += PYTHON3_LIB_LOCATION -lqtermwidget5 /usr/local/lib/libantlr4-runtime.so.4.8
unix: INCLUDEPATH += PYTHON3_INC_LOCATION /usr/local/include/antlr4-runtime/
unix: DEPENDPATH += PYTHON3_INC_LOCATION /usr/local/include/antlr4-runtime/

greaterThan(QT_MAJOR_VERSION, 4){
    CONFIG += c++11
} else {
    QMAKE_CXXFLAGS += -std=c++11 -Wpedantic
}
