add_executable(SetUnion
    set_union.cpp
)

target_link_libraries(SetUnion PRIVATE
    printset
)

add_library(printset
    include/printset.h
)