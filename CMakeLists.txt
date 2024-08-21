cmake_minimum_required(VERSION 3.28)
project(render VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to OpenCV installation
set(OpenCV_DIR "C:/Users/maria/Downloads/opencv/build")

# Find OpenCV
find_package(OpenCV REQUIRED)

if (OpenCV_FOUND)
    message(STATUS "OpenCV found: ${OpenCV_VERSION}")
else()
    message(FATAL_ERROR "OpenCV not found!")
endif()

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Define executables
add_executable(render
        approach/Stream/container.h
        approach/Render/node.h
        approach/Stream/stream.h
        approach/Render/xml.h
        approach/main.cpp
        approach/Stream/streamtype.h
        approach/Render/render.h
)

add_executable(outline_main
        approach/Stream/container.h
        approach/Render/node.h
        approach/Stream/stream.h
        approach/Render/outline.h
        approach/outline_main.cpp
        approach/Stream/streamtype.h
        approach/Render/render.h
        v1.h
        v2.h
        v3.h
        v4.h
        v5.h
        cnn.h
)

add_executable(render_test
        tests/doctest.h
        tests/test.cpp
)

add_executable(test_opencv
        approach/test_opencv.cpp
)

# Link OpenCV libraries
target_link_libraries(render ${OpenCV_LIBS})
target_link_libraries(outline_main ${OpenCV_LIBS})
target_link_libraries(test_opencv ${OpenCV_LIBS})
