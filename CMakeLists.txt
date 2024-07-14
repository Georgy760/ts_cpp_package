cmake_minimum_required(VERSION 3.5)
project(hello)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include the Node.js and node-addon-api headers
include_directories(${CMAKE_JS_INC}
                    ${CMAKE_JS_SRC}
                    ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api)

# Create the library target
add_library(hello SHARED
    src/hello.cpp
)

# Link Node.js libraries
target_link_libraries(hello ${CMAKE_JS_LIB})

# Ensure the output file has the .node extension and no lib prefix
set_target_properties(hello PROPERTIES
    PREFIX ""
    SUFFIX ".node"
    OUTPUT_NAME "hello"
)

# Create another library target for cppWrapper
add_library(cppWrapper SHARED
    src/cpp_wrapper.cpp
)

# Link Node.js libraries
target_link_libraries(cppWrapper ${CMAKE_JS_LIB})

# Ensure the output file has the .node extension and no lib prefix
set_target_properties(cppWrapper PROPERTIES
    PREFIX ""
    SUFFIX ".node"
    OUTPUT_NAME "cppWrapper"
)
