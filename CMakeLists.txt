cmake_minimum_required(VERSION 3.11)

# Project Rjff - RaycastingJustForFun
project(Rjff)

add_executable(${PROJECT_NAME} 
  ./src/main.cpp
  ./src/line.h
  ./src/line.cpp
  ./src/point.h
  ./src/utils.h
  ./src/utils.cpp
  ./src/map.h
  ./src/map.cpp
  ./src/player.h
  ./src/player.cpp
  ./src/randomizer.h
  ./src/randomizer.cpp
)

# Print helpful info
message(STATUS "*** CMakeList dir : " ${CMAKE_SOURCE_DIR} " ***")
message(STATUS "*** C++ compiler path: " ${CMAKE_CXX_COMPILER} " ***")
message(STATUS "*** C compiler path: " ${CMAKE_C_COMPILER} " ***")

# Set linker language property
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Set CPP standard as c++17
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

include(FetchContent)

###########################
# SFML

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

# SFML
###########################

###########################
# Set dependencies

# Set Zinet_Core to depend sfml
add_dependencies(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Set dependencies
###########################

###########################
# Include directories

message(STATUS "*** Include directories ***")

target_include_directories(${PROJECT_NAME} ${SFML_INCLUDE_DIRS})

# Include directories
###########################

###########################
# Link libs

message(STATUS "*** Link directories ***")

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-system sfml-network sfml-window)

# Link Libs
###########################
