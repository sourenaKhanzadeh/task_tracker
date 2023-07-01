cmake_minimum_required(VERSION 3.25)
project(task_tracker)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)
add_subdirectory(src)

add_executable(task_tracker main.cpp)


target_link_libraries(task_tracker PUBLIC
        simple
        task)

