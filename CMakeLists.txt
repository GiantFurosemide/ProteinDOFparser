cmake_minimum_required(VERSION 3.10)
project(ProteinDOFparser)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ProteinDOFparser/bin)

# Add cifparser library path
set(CIFPARSER_ROOT ${CMAKE_SOURCE_DIR}/extern/cifparser/cifparse-obj-v7.105-prod-src)
set(CIFPARSER_INCLUDE_DIR ${CIFPARSER_ROOT}/include)
set(CIFPARSER_LIB_DIR ${CIFPARSER_ROOT}/lib)

# Create library from source files
file(GLOB LIB_SOURCES "ProteinDOFparser/*.cpp")
file(GLOB LIB_HEADERS "ProteinDOFparser/*.h")

add_library(protein_dof_parser ${LIB_SOURCES} ${LIB_HEADERS})

# Include directories
target_include_directories(protein_dof_parser PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/ProteinDOFparser
    ${CIFPARSER_INCLUDE_DIR}
)

# Link cifparser library
target_link_directories(protein_dof_parser PUBLIC ${CIFPARSER_LIB_DIR})
target_link_libraries(protein_dof_parser PUBLIC cifparse)

# Add the app subdirectory
add_subdirectory(ProteinDOFparser/app)

include(ExternalProject)
include(FetchContent)

# Set cifparser version and URL
set(CIFPARSER_URL "https://sw-tools.rcsb.org/apps/CIFPARSE-OBJ/source/cifparse-obj-v7.105-prod-src.tar.gz")
set(CIFPARSER_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/cifparser")

ExternalProject_Add(
    cifparser_external
    URL ${CIFPARSER_URL}
    PREFIX ${CIFPARSER_INSTALL_DIR}
    DOWNLOAD_DIR "${CIFPARSER_INSTALL_DIR}/download"
    SOURCE_DIR "${CIFPARSER_INSTALL_DIR}/src"
    BINARY_DIR "${CIFPARSER_INSTALL_DIR}/build"
    INSTALL_DIR "${CIFPARSER_INSTALL_DIR}/install"
    CONFIGURE_COMMAND ""  # cifparser uses make directly, no configure step
    BUILD_COMMAND make -C <SOURCE_DIR>
    INSTALL_COMMAND make -C <SOURCE_DIR> install PREFIX=<INSTALL_DIR>
    BUILD_IN_SOURCE 1
)

# Make the include directories available to dependent targets
add_library(cifparser INTERFACE)
add_dependencies(cifparser cifparser_external)
target_include_directories(cifparser INTERFACE 
    "${CIFPARSER_INSTALL_DIR}/install/include"
)
target_link_directories(cifparser INTERFACE
    "${CIFPARSER_INSTALL_DIR}/install/lib"
) 