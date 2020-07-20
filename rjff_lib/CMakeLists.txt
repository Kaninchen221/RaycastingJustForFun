# Create rjff library
add_library(rjff_lib ${RJFF_LIB_TYPE}
	include/rjff/Core.h
	include/rjff/Point.h
	include/rjff/StaticLine.h
	src/StaticLine.cpp
	include/rjff/Line.h
	src/Line.cpp
	include/rjff/MathUtility.h
	src/MathUtility.cpp
	include/rjff/Utility.h
	src/Utility.cpp
	include/rjff/Randomizer.h
	src/Randomizer.cpp
	include/rjff/Camera.h
	src/Camera.cpp
	include/rjff/Raycasting.h
	src/Raycasting.cpp
)

# Create rjff library include dir
set(RJFF_LIB_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  PARENT_SCOPE 
)

# Set linker language property
set_target_properties(rjff_lib PROPERTIES LINKER_LANGUAGE CXX)

# Set CPP standard as c++17
target_compile_features(rjff_lib PRIVATE cxx_std_17)

# Dependencies for rjff_lib
add_dependencies(rjff_lib sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Include dirs for rjff_lib
target_include_directories(rjff_lib 
	${SFML_INCLUDE_DIRS}
)

# Link libraries for rjff_lib
target_link_libraries(rjff_lib 
	sfml-system 
	sfml-window 
	sfml-graphics 
	sfml-audio 
	sfml-network
)