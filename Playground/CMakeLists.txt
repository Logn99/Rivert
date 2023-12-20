# CMakeLists.txt in the Playground directory

# Set the executable name and source files
set(EXE_NAME Playground)
set(EXE_SOURCES
    src/Game.cpp
    src/main.cpp
    
    # Add all source files for the executable

)

# Create the executable
add_executable(${EXE_NAME} ${EXE_SOURCES})

# Link the executable with the library
target_link_libraries(${EXE_NAME} PRIVATE Rivert)

# Include directories for the executable
target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})