cmake_minimum_required(VERSION 3.16)
project(PixelToVoxelProjectionResearch)

set(CMAKE_CXX_STANDARD 23)

# Find required packages
find_package(OpenCV REQUIRED)
find_package(glfw3 REQUIRED)
find_package(PkgConfig REQUIRED)

# GLEW (required for OpenGL function loading)
pkg_check_modules(GLEW REQUIRED glew)

# Add include and lib dirs for GLEW
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})

# Add the executable
add_executable(PixelToVoxelProjectionResearch
        src/main.cpp
        src/video_capture.cpp
        src/video_capture.h
        src/gl_render.cpp
        src/gl_render.h
        src/projection.h
        src/voxel_projection.cpp
)

# Link the necessary libraries
target_link_libraries(PixelToVoxelProjectionResearch
        ${OpenCV_LIBS}
        glfw
        ${GLEW_LIBRARIES}
        "-framework OpenGL"
)