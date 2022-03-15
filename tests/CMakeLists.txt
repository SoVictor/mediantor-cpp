macro( mediantor_append_to_target_property TARGET PROPERTY VALUE)
    get_target_property( CURRENT_STATE ${TARGET} ${PROPERTY} )
    if ( ${CURRENT_STATE} STREQUAL "CURRENT_STATE-NOTFOUND" )
        set(CURRENT_STATE "")
    endif()
    set_target_properties( ${TARGET} PROPERTIES ${PROPERTY} "${CURRENT_STATE} ${VALUE}" )
endmacro()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()
include_directories(
	../third_party/googletest/googletest/include
	../third_party/googletest/googletest
)

set(SOURCES
	src/test.cpp
)

add_executable(test ${SOURCES})

target_link_libraries(test gtest gtest_main mediantor-lib)

# Enable experimental/filesystem
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    mediantor_append_to_target_property(test LINK_FLAGS "-static")
    target_link_libraries(test stdc++fs)
elseif(CMAKE_COMPILER_IS_GNUCXX)
    mediantor_append_to_target_property(test LINK_FLAGS "-pthread -static-libgcc -static-libstdc++")
    target_link_libraries(test stdc++fs)
endif()

file(COPY data DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
