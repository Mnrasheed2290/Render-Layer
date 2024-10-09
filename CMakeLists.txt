cmake_minimum_required(VERSION 3.28)
project(RenderLayer VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The path to OpenCV installation
set(OpenCV_DIR "C:/opencv_install/x64/mingw/lib")

# Find OpenCV
find_package(OpenCV REQUIRED)

if (OpenCV_FOUND)
    message(STATUS "OpenCV found: ${OpenCV_VERSION}")
else()
    message(FATAL_ERROR "OpenCV not found!")
endif()

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Path to TinyFileDialogs, identifying images
set(TINYFILEDIALOGS_DIR "C:/Users/maria/Downloads/tinyfiledialogs-current/tinyfiledialogs")

# TinyFileDialogs headers
include_directories(${TINYFILEDIALOGS_DIR})

# executables and source files 
add_executable(render
        approach/Stream/container.h
        approach/Render/node.h
        approach/Stream/stream.h
        approach/Render/xml.h
        approach/main.cpp
        approach/Stream/streamtype.h
        approach/Render/render.h
        approach/Render/v2.h
)

add_executable(outline_main
        approach/Stream/container.h
        approach/Render/node.h
        approach/Stream/stream.h
        approach/Render/outline.h
        approach/outline_main.cpp
        approach/Stream/streamtype.h
        approach/Render/render.h
        approach/Render/v1.h
        approach/Render/v2.h
        approach/Render/v3.h
        approach/Render/v4.h
        approach/Render/v5.h
        approach/Render/cnn.h
        approach/Render/derivednode.cpp
)

add_executable(image_reader
        approach/Render/image_reader.cpp
)

# Link OpenCV libraries
target_link_libraries(render ${OpenCV_LIBS})
target_link_libraries(outline_main ${OpenCV_LIBS})
target_link_libraries(image_reader ${OpenCV_LIBS})

# Compile TinyFileDialogs as part of the image_reader target
target_sources(image_reader PRIVATE ${TINYFILEDIALOGS_DIR}/tinyfiledialogs.c)

# Ensure TinyFileDialogs source is compiled with C++ standard
set_source_files_properties(${TINYFILEDIALOGS_DIR}/tinyfiledialogs.c PROPERTIES COMPILE_FLAGS "-std=c++23")
