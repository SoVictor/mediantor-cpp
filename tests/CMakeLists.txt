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

file(COPY data DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
