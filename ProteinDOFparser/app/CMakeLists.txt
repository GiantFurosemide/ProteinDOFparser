# Find all .cpp files in current directory
file(GLOB APP_SOURCES "*.cpp")

# Create executables for each .cpp file
foreach(source_file ${APP_SOURCES})
    # Get filename without extension
    get_filename_component(filename ${source_file} NAME_WE)
    # Create executable name with "prodof" prefix
    add_executable(prodof_${filename} ${source_file})
    # Link the library
    target_link_libraries(prodof_${filename} PRIVATE protein_dof_parser)
    # Set include directories for the executable
    target_include_directories(prodof_${filename} PUBLIC 
        ${CMAKE_SOURCE_DIR}/ProteinDOFparser
    )
endforeach()
