# CMakeLists.txt in the Rivert directory

# Set the library name and source files
set(LIB_NAME Rivert)
set(LIB_SOURCES
    src/Window.cpp
    src/Rivert.cpp
    src/InputHandler.cpp
    src/TextureManager.cpp
    src/RenderSystem.cpp
    src/ScriptSystem.cpp
    src/ECS.cpp
    src/AnimationSystem.cpp
    # Add all source files in the library

)

# Create the library
add_library(${LIB_NAME} ${LIB_SOURCES})

# Include directories for the library
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(${LIB_NAME} PRIVATE SDL2 SDL2_image)
