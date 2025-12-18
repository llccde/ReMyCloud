cmake_minimum_required(VERSION 3.16)

project(ReMyCloud VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(Qt6
    REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core5Compat)

include_directories(./include)
include_directories(./include/service)
include_directories(./include/application)
include_directories(./interface/service)
include_directories(./interface/application)
include_directories(./interface)
include_directories(./interface/adapter)
include_directories(./classForTest/include)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appReMyCloud
    main.cpp
    src/Singletons.cpp
    interface/adapter/I_QmlAdapter.h
    classForTest/include/T_QmlAdapter.h

)

qt_add_qml_module(appReMyCloud
    URI ReMyCloud
    QML_FILES
        qml/Main.qml
        QML_FILES qml/navItem.qml
        QML_FILES qml/navBar.qml
        QML_FILES qml/FileList.qml

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appReMyCloud PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appReMyCloud
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appReMyCloud
    PRIVATE Qt6::Quick
)
target_link_libraries(appReMyCloud PRIVATE Qt6::Core5Compat)
include(GNUInstallDirs)
install(TARGETS appReMyCloud
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)




add_subdirectory(QKTest)
add_subdirectory(CppTest)
enable_testing()
if(TARGET QKTest)
    add_test(NAME QKTest COMMAND QKTest)
endif()

if(TARGET CppTest)
    add_test(NAME CppTest COMMAND CppTest)
endif()
