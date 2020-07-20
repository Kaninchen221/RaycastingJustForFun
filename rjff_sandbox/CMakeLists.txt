# Create rjff_sandbox executable project for rjff library
add_executable(rjff_sandbox
	src/main.cpp
)

# Set linker language property
set_target_properties(rjff_sandbox PROPERTIES LINKER_LANGUAGE CXX)

# Set CPP standard as c++17
target_compile_features(rjff_sandbox PRIVATE cxx_std_17)

# Include dirs for rjff_sandbox 
target_include_directories(rjff_sandbox PUBLIC
	${RJFF_LIB_INCLUDE_DIR} 
	${SFML_INCLUDE_DIRS} 
)

# Dependencies for rjff_sandbox
add_dependencies(rjff_sandbox rjff_lib)

# Link libraries for rjff_sandbox
target_link_libraries(rjff_sandbox
	rjff_lib
)
