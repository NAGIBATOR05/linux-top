cmake_minimum_required(VERSION 3.19)
project(linux-top)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(linux-top main.cpp)

add_subdirectory(BigNumbers)

target_link_libraries(linux-top PUBLIC BigNumbers)

target_include_directories(linux-top PUBLIC
        "${PROJECT_BINARY_DIR}"
)