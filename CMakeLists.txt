cmake_minimum_required(VERSION 3.10)
project(ProteinDOFparser)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/bin)

# Create library from source files
file(GLOB LIB_SOURCES "ProteinDOFparser/*.cpp")
file(GLOB LIB_HEADERS "ProteinDOFparser/*.h")

add_library(protein_dof_parser ${LIB_SOURCES} ${LIB_HEADERS})

# Include directories
target_include_directories(protein_dof_parser PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/ProteinDOFparser
)

# Add the app subdirectory
add_subdirectory(ProteinDOFparser/app) 