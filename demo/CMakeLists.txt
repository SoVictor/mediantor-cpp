set(SOURCES
    src/main.cpp
)

add_executable( demo ${SOURCES} )
target_link_libraries( demo mediantor-lib )
