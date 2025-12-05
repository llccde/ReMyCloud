cmake_minimum_required(VERSION 3.16)

project(TestMain LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TestMain tst_testmain.cpp)
add_test(NAME TestMain COMMAND TestMain)

target_link_libraries(TestMain PRIVATE Qt${QT_VERSION_MAJOR}::Test)

