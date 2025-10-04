cmake_minimum_required(VERSION 3.15)
project(TrainVis CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Conan toolchain (Conan 2.x)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Create a shared library
add_library(${PROJECT_NAME} SHARED src/vis.cpp)

# Find dependencies
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(OpenGL REQUIRED)

# Include directories for dependencies
target_include_directories(${PROJECT_NAME} PUBLIC
    ${glfw3_INCLUDE_DIRS}
    ${glad_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

# Link dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    ${glad_LIBRARIES}
    OpenGL::GL
    dl
)

