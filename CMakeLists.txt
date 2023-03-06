cmake_minimum_required(VERSION 3.2)

# Name and version project
project(fractal_app)

# Creates compile_commands.json, used by CCLS
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Destination for binary output files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source directory
add_subdirectory(src)