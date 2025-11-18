cmake_minimum_required(VERSION 3.15)

project(term-render VERSION 1.0 LANGUAGES CXX)

# Set a nice default for C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Using out-of-source build (i.e., building in /build)
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed. Please use a separate build directory.")
endif()

# Add include directory so headers in /inc can be found
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Add executable from source files
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Framebuffer.cpp
    src/Renderer.cpp
    src/Math.cpp
)

# If you have tests, enable testing and add them
# enable_testing()
# add_subdirectory(tests)

