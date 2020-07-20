# Create rjff_tests executable project for rjff library
add_executable(rjff_tests
	src/main.cpp
	src/StaticLineTest.h
	src/StaticLineTest.cpp
	src/LineTest.h
	src/LineTest.cpp
	src/MathUtilityTest.h
	src/MathUtilityTest.cpp
	src/UtilityTest.h
	src/UtilityTest.cpp
	src/CameraTest.h
	src/CameraTest.cpp
	src/RaycastingTest.h
	src/RaycastingTest.cpp
)

# Set linker language property
set_target_properties(rjff_tests PROPERTIES LINKER_LANGUAGE CXX)

# Set CPP standard as c++17
target_compile_features(rjff_tests PRIVATE cxx_std_17)

# Dependencies for rjff_tests
add_dependencies(rjff_tests rjff_lib gtest)

message(STATUS ${RJFF_LIB_INCLUDE_DIR})

# Include dirs
target_include_directories(rjff_tests PUBLIC
	${RJFF_LIB_INCLUDE_DIR} 
	${SFML_INCLUDE_DIRS} 
	${GOOGLEMOCK_INCLUDE_DIRS} 
	${GOOGLETEST_INCLUDE_DIRS} 
)

# Link libraries
target_link_libraries(rjff_tests
	rjff_lib
	gtest
)
