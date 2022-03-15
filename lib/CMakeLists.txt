set(HEADERS
    include/i_mediantor.h
    include/mediantor_heap.h
    include/mediantor_sqrt_decomp.h
)

set(SOURCES
    src/mediantor_heap.cpp
    src/mediantor_sqrt_decomp.cpp
)

add_library( mediantor-lib ${SOURCES} ${HEADERS} )
target_include_directories( mediantor-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
