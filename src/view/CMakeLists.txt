cmake_minimum_required(VERSION 3.5)

project(3DViewer VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXXFLAGS -Wno-deprecated)
set(GL_SILENCE_DEPRECATION ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)

set(PROJECT_SOURCES
        ../main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        glwidget.h
        glwidget.cpp

        ../models/IObserver.h
        ../models/ISubject.h
        ../models/Object.h
        ../models/Object.cc
        ../models/Settings.h
        ../models/Settings.cc
        ../models/ObjectReader.h
        ../models/ObjectReader.cc
        ../models/ObjectTransformer.h
        ../models/ObjectTransformer.cc
        ../models/SettingsSaver.h
        ../models/SettingsSaver.cc
        ../models/Vertex.h
        ../models/Vertex.cc

        ../controllers/ViewerController.h
        ../controllers/ViewerController.cc


        gifmaker/gif_hash.h
        gifmaker/gif_lib.h
        gifmaker/gif_lib_private.h
        gifmaker/qgifglobal.h
        gifmaker/qgifimage.h
        gifmaker/qgifimage_p.h

        gifmaker/gif_hash.c
        gifmaker/qgifimage.cpp
        gifmaker/dgif_lib.c
        gifmaker/egif_lib.c
        gifmaker/gif_err.c
        gifmaker/gif_font.c
        gifmaker/gifalloc.c
        gifmaker/quantize.c
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3DViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 3DViewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3DViewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3DViewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(3DViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(3DViewer PRIVATE Qt6::Gui)
target_link_libraries(3DViewer PRIVATE Qt6::OpenGLWidgets)

set_target_properties(3DViewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3DViewer)
endif()
