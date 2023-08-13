cmake_minimum_required(VERSION 3.0)

set(CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

project(FManager LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH C:/Qt/Qt5.12.12/5.12.12/mingw73_64)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(BOOST_ROOT "C:/Boost")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Boost 1.80.0 COMPONENTS filesystem thread chrono REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}/sources
    ${PROJECT_SOURCE_DIR}/headers
    ${PROJECT_SOURCE_DIR}/sources/Components
    ${PROJECT_SOURCE_DIR}/headers/Components
    ${PROJECT_SOURCE_DIR}/headers/Func
    ${PROJECT_SOURCE_DIR}/sources/Func
    ${Boost_INCLUDE_DIRS}
)

file(GLOB all_SRCS    
    "${PROJECT_SOURCE_DIR}/headers/*.h"
    "${PROJECT_SOURCE_DIR}/sources/*.cpp"
    "${PROJECT_SOURCE_DIR}/headers/Components/*.h"
    "${PROJECT_SOURCE_DIR}/sources/Components/*.cpp"
    "${PROJECT_SOURCE_DIR}/headers/Func/*.h"
    "${PROJECT_SOURCE_DIR}/sources/Func/*.cpp"
)

add_executable(app ${all_SRCS})

target_link_libraries(app PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    Boost::filesystem
    Boost::thread
    Boost::chrono
)