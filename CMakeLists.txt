cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

project(expressPython LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -Wpedantic")

set(SOURCES
    main.cpp
    ANTLR/customtoken.cpp
    UI/mainview.cpp
    CodeEditor/antlrsyntaxhighlighter.cpp
    CodeEditor/codeeditor.cpp
    Features/snippets.cpp
    PythonAccess/emb.cpp
    PythonAccess/pythonworker.cpp
    CodeEditor/codelineedit.cpp
    Features/xquestion.cpp
    Features/xtute.cpp
    PythonAccess/jedi.cpp
    ANTLR/Python3BaseListener.cpp
    ANTLR/Python3Lexer.cpp
    ANTLR/Python3Listener.cpp
    ANTLR/Python3Parser.cpp
)

set(UI
    UI/mainview.ui
)

set(HEADERS
    UI/mainview.h
    ANTLR/customtoken.h
    CodeEditor/antlrsyntaxhighlighter.h
    CodeEditor/codeeditor.h
    Features/snippets.h
    PythonAccess/emb.h
    PythonAccess/pythonworker.h
    CodeEditor/codelineedit.h
    Features/xquestion.h
    Features/xtute.h
    PythonAccess/jedi.h
    ANTLR/Python3BaseListener.h
    ANTLR/Python3Lexer.h
    ANTLR/Python3Listener.h
    ANTLR/Python3Parser.h
)

set(RESOURCES
    PyRunResources.qrc
)

qt5_add_resources(RESOURCES_WRAPPED ${RESOURCES})
qt5_wrap_ui(UI_WRAPPED ${UI})
qt5_wrap_cpp(SOURCES_MOC ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES_MOC} ${UI_WRAPPED} ${RESOURCES_WRAPPED})

# WINDOWS SPECIFIC CONFIG
if(WIN32) 
    set(PYTHON37_LOCATION $ENV{PYTHON37_LIB_LOCATION})
    set(RC_FILE WindowsResources/win_rsrc.rc)
    set(LIBS
        -L${PYTHON37_LOCATION}\libs\ 
        -lpython37
    )   
    set(INCLUDES
        ${PYTHON37_LOCATION}\include
    )
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE YES
    )
# MACOS SPECIFIC CONFIG
elseif(APPLE)
    set(PYTHON37_LIB_LOCATION $ENV{PYTHON37_LIB_LOCATION})
    set(PYTHON37_INC_LOCATION $ENV{PYTHON37_INC_LOCATION})
    set(LIBS
        ${PYTHON37_LIB_LOCATION}
        qtermwidget5
        ${CMAKE_SOURCE_DIR}/ANTLR4runtime/run/usr/local/lib/libantlr4-runtime.so.4.8
    )
    set(INCLUDES
        ${PYTHON37_INC_LOCATION}
        ${CMAKE_SOURCE_DIR}/ANTLR4runtime/run/usr/local/include/antlr4-runtime/
    )
    set(ICON Icons/PyRunImg.icns)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE YES
    )
# UNIX specific config
elseif(UNIX)
    set(PYTHON37_LIB_LOCATION $ENV{PYTHON37_LIB_LOCATION})
    set(PYTHON37_INC_LOCATION $ENV{PYTHON37_INC_LOCATION})
    set(LIBS
        ${PYTHON37_LIB_LOCATION}
        qtermwidget5
        ${CMAKE_SOURCE_DIR}/ANTLR4runtime/run/usr/local/lib/libantlr4-runtime.so.4.8
    )
    set(INCLUDES
        ${PYTHON37_INC_LOCATION}
        ${CMAKE_SOURCE_DIR}/ANTLR4runtime/run/usr/local/include/antlr4-runtime/
    )
else()
    message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)

# LINKING EXTERNAL LIBRARIES
target_include_directories(${PROJECT_NAME} PUBLIC
    ${INCLUDES}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${LIBS}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)
