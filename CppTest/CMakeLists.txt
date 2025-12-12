cmake_minimum_required(VERSION 3.16)

project(CppTestMain LANGUAGES CXX)
include_directories(../include)
include_directories(./include/)
#include_directories(D:/Qt/ReMyCloud/build/Desktop_Qt_6_9_3_MinGW_64_bit-Debug/CppTest/CppTestMain_autogen/include/)
enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CppTestMain tst_cpptestmain.cpp
)
add_test(NAME CppTestMain COMMAND CppTestMain)

target_link_libraries(CppTestMain PRIVATE Qt${QT_VERSION_MAJOR}::Test)

