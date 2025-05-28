cmake_minimum_required(VERSION 3.5)

# Set project name and version
project(NoteApp VERSION 1.0 LANGUAGES CXX)

# Find required Qt packages
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

if (Qt6_FOUND)
    message(STATUS "Using Qt6")
else()
    find_package(Qt5 REQUIRED COMPONENTS Widgets)
    if (Qt5_FOUND)
        message(STATUS "Using Qt5")
    else()
        message(FATAL_ERROR "Qt not found")
    endif()
endif()

# Set C++ standard and compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/main.cpp
    src/Note.cpp
    src/Text.cpp
    src/NoteWidget.cpp
)

# Add header files
set(HEADERS
    include/Note.h
    include/Text.h
    include/NoteWidget.h
)

# Create the executable
add_executable(NoteApp ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(NoteApp PRIVATE include)

# Link Qt libraries
if (Qt6_FOUND)
    target_link_libraries(NoteApp PRIVATE Qt6::Widgets)
else()
    target_link_libraries(NoteApp PRIVATE Qt5::Widgets)
endif()

# Installation (optional)
install(TARGETS NoteApp DESTINATION bin)
