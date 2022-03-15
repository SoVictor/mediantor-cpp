set(HEADERS
    include/mediantor.h
    include/mediantor/i_mediantor.h
    include/mediantor/mediantor_heap.h
    include/mediantor/mediantor_sorted_list.h
    include/mediantor/mediantor_sqrt_decomp.h
)

set(SOURCES
    src/mediantor_heap.cpp
    src/mediantor_sorted_list.cpp
    src/mediantor_sqrt_decomp.cpp
)

add_library( mediantor-lib ${SOURCES} ${HEADERS} )
target_include_directories( mediantor-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
