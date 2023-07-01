add_library(simple STATIC
        frontend.cpp
        "${CMAKE_BINARY_DIR}/../include/tt/frontend.hpp"
        )

add_library(task STATIC
        task.cpp
        "${CMAKE_BINARY_DIR}/../include/tt/task.hpp"
        )
