cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

project(FManager LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH C:/Qt/Qt5.12.12/5.12.12/mingw73_64)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}/sources
    ${PROJECT_SOURCE_DIR}/headers
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

file(GLOB all_SRCS    
    ${PROJECT_SOURCE_DIR}/headers/Core.h
    ${PROJECT_SOURCE_DIR}/sources/main.cpp
    ${PROJECT_SOURCE_DIR}/headers/FMMainWindow.h
    ${PROJECT_SOURCE_DIR}/sources/FMMainWindow.cpp
)

add_executable(app ${all_SRCS})

target_link_libraries(app PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)