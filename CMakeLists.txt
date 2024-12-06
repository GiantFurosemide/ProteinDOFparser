cmake_minimum_required(VERSION 3.10)

# Set installation directory
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/ProteinDOFparser/app_install CACHE PATH "Installation Directory" FORCE)

project(ProteinDOFparser)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Install header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/ProteinDOFparser/ 
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

# Set output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/app_install/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/app_install/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/app_install/bin)

# Collect source files
file(GLOB LIB_SOURCES "ProteinDOFparser/*.cpp")
file(GLOB LIB_HEADERS "ProteinDOFparser/*.h")

# Create main library
add_library(protein_dof_parser ${LIB_SOURCES} ${LIB_HEADERS})

# Set include directories for the library
target_include_directories(protein_dof_parser PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/ProteinDOFparser
)

# Build applications
add_subdirectory(ProteinDOFparser/app)