cmake_minimum_required(VERSION 3.12)
# Name of the project
project(Qt1Build)
# This is the name of the Exe change this and it will change everywhere
set(TargetName Qt1)
# Instruct CMake to run moc automatically when needed (Qt projects only)
set(CMAKE_AUTOMOC ON)
# Run the uic tools and search in the ui folder
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/ui)
# find Qt libs
find_package(Qt5 COMPONENTS Widgets REQUIRED)
# use C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
# Set the name of the executable we want to build
add_executable(${TargetName})

target_sources(${TargetName} PRIVATE ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(${TargetName} PRIVATE Qt5::Widgets )
