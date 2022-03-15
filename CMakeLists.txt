project(MediantorCpp)
cmake_minimum_required(VERSION 3.18.1)
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED on )

macro( mediantor_set_output_directories PATH )
    message( STATUS "Output directories set to ${PATH}" )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PATH}/bin )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PATH}/bin )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PATH}/lib )
    foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
        string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
        set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )
        set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} )
        set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} )
    endforeach()
endmacro()

mediantor_set_output_directories( ${CMAKE_BINARY_DIR}/out )

add_subdirectory( lib )

add_subdirectory( demo )
