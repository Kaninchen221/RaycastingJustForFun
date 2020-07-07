cmake_minimum_required(VERSION 3.11)

# Project Rjff - RaycastingJustForFun
project(Rjff)

# Organize output directories
# https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create rjff library
add_library(rjff_lib STATIC
	include/StaticLine.h
	src/StaticLine.cpp
	include/Line.h
	src/Line.cpp
)

# Set linker language property
set_target_properties(rjff_lib PROPERTIES LINKER_LANGUAGE CXX)

# Set CPP standard as c++17
target_compile_features(rjff_lib PRIVATE cxx_std_17)

# Create rjff_tests executable project for rjff library
add_executable(rjff_tests
	tests/src/main.cpp
)

# Set linker language property
set_target_properties(rjff_tests PROPERTIES LINKER_LANGUAGE CXX)

# Set CPP standard as c++17
target_compile_features(rjff_tests PRIVATE cxx_std_17)

# Include FetchContent
include(FetchContent)

# Fetch SFML
message(STATUS "*** Fetch SFML ***")

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG master
)

FetchContent_MakeAvailable(SFML)

# Create var contains SFML include dir
set(SFML_INCLUDE_DIRS PRIVATE 
  build/_deps/sfml-src/include
)

# Fetch GoogleTest

message(STATUS "*** Fetch GoogleTest ***")

FetchContent_Declare(
  GTEST
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG master
  SOURCE_DIR _deps/gtest-src
)

FetchContent_MakeAvailable(GTEST)

# Create var contains Google Mock include dir
set(GOOGLEMOCK_INCLUDE_DIRS PRIVATE 
  build/_deps/gtest-src/googlemock/include
)

# Create var contains Google Test include dir
set(GOOGLETEST_INCLUDE_DIRS PRIVATE 
  build/_deps/gtest-src/googletest/include
)

# Include dirs for rjff_lib
target_include_directories(rjff_lib 
	${SFML_INCLUDE_DIRS}
)

# Include dirs for rjff_tests
target_include_directories(rjff_tests 
	${SFML_INCLUDE_DIRS} 
	${GOOGLEMOCK_INCLUDE_DIRS}
	${GOOGLETEST_INCLUDE_DIRS}
)

# Dependencies for rjff_lib
add_dependencies(rjff_lib sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Dependencies for rjff_tests
add_dependencies(rjff_tests rjff_lib gtest)

# Link libraries for rjff_lib
target_link_libraries(rjff_lib 
	sfml-system 
	sfml-window 
	sfml-graphics 
	sfml-audio 
	sfml-network
)

# Link libraries for rjff_tests
target_link_libraries(rjff_tests
	rjff_lib
	gtest
)
