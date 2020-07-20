cmake_minimum_required(VERSION 3.11)

# Project Rjff - RaycastingJustForFun
project(Rjff)

# Set cache var contains rjff_lib type
set(RJFF_LIB_TYPE "STATIC" CACHE STRING "")

# If RJFF_LIB_TYPE is STATIC then add RJFF_LIB_TYPE_STATIC global macro
if(RJFF_LIB_TYPE STREQUAL "STATIC")

	add_compile_definitions(rjff_lib RJFF_LIB_TYPE_STATIC)

endif()

# Organize output directories
# https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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
  ${PROJECT_BINARY_DIR}/_deps/sfml-src/include
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
  ${PROJECT_BINARY_DIR}/_deps/gtest-src/googlemock/include
)

# Create var contains Google Test include dir
set(GOOGLETEST_INCLUDE_DIRS PRIVATE 
  ${PROJECT_BINARY_DIR}/_deps/gtest-src/googletest/include
)

# Add subdirectory rjff_lib - Create rjff_lib project from CMake file in rjff_lib directory
add_subdirectory(rjff_lib)

# Add subdirectory rjff_tests - Create rjff_tests project from CMake file in rjff_tests directory
add_subdirectory(rjff_tests)

# Add subdirectory rjff_sandbox - Create rjff_sandbox project from CMake file in rjff_sandbox directory
add_subdirectory(rjff_sandbox)











