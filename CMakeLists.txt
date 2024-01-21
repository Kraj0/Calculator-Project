cmake_minimum_required(VERSION 3.6.2)

set(PROJECT_NAME Kalkulator_cmake)

project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)

if(WIN32)
    set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W3 /GR /EHsc /std:c++17")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Ob0 /Od /RTC1 /std:c++17")

    message("Win settings chosen...")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++17 -Wall")

    message("Mac settings chosen...")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++17 -Wall")

    message("Linux settings chosen...")
endif()

# Inform CMake where the header files are
include_directories(include)

# Separate resource files
file(GLOB SOURCES "./src/*.cpp")
file(GLOB HEADERS "./include/*.h")
file(GLOB RESOURCES "./res/*.rc")

# Create executable
add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${HEADERS} ${RESOURCES})

# Set the default project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")