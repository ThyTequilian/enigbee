cmake_minimum_required(VERSION 3.20)

# set the project name
project(enigmaEncoder)


ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /UMBCS /D_UNICODE /DUNICODE")

# add the executable
add_executable(enigmaEncoder
	enigmaEncoder.cpp enigmaEncoder.hpp
	rotor.cpp rotor.hpp
	plugBoard.cpp plugBoard.hpp
	main.cpp main.hpp
	typeDefinitions.hpp
	pch.cpp pch.hpp)

include_directories(${CMAKE_SOURCE_DIR}/3p)
#include_directories(PROJECT_SOURCE_DIR/3p/fmt)
#target_link_libraries(virtuoso_api_source docopt)
#target_link_libraries(virtuoso_api_source tl)
#add_library(virtuoso_odbc PROJECT_SOURCE_DIR/3p/virtodbc.dll)