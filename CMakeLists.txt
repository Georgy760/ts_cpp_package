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
    SUFFIX ".node"
    PREFIX ""
    OUTPUT_NAME "hello"
)
