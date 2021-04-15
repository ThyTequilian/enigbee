cmake_minimum_required(VERSION 3.20)

# set the project name
project(enigma)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 16)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Add Subdirectories to Incluce
add_subdirectory(source)
#add_subdirectory(3p/tl)
#add_subdirectory(3p/fmt)


message(STATUS  "Subdirectories included")
message(STATUS "************************************************")

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /UMBCS /D_UNICODE /DUNICODE")

message(STATUS  "Flags Set")
message(STATUS "************************************************")

# Set Warninglevel to 4
if(CMAKE_BUILD_TOOL MATCHES "(msdev|devenv|nmake)")
    add_definitions(/W4)
endif()


message(STATUS "WarningLevel set")
message(STATUS "************************************************")

message(STATUS "************************************************")


add_definitions(-D_AFXDLL)
Set(CMAKE_MFC_FLAGS 2)

#message(STATUS "fmt-Format")
#message(STATUS "************************************************")
#add_library(fmt INTERFACE)
#target_sources(fmt INTERFACE format.h)

#target_include_directories(tl INTERFACE
#    "${PROJECT_SOURCE_DIR}/3p/tl"
#)

include_directories(${CMAKE_SOURCE_DIR}/3p)

message(STATUS "CMake Done")
message(STATUS "************************************************")