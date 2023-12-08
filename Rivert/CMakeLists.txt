# CMakeLists.txt in the Rivert directory

# Set the library name and source files
set(LIB_NAME Rivert)
set(LIB_SOURCES
    src/test.cpp
    # Add all source files in the library

)

# Create the library
add_library(${LIB_NAME} ${LIB_SOURCES})

# Include directories for the library
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)