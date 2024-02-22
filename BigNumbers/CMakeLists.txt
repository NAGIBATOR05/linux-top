cmake_minimum_required(VERSION 3.20)
project(linux-top)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(This BigNumbers)

set(Sources
        BigFloat.cpp
        arithmetics.cpp

)
set(Headers
        BigFloat.cpp
        arithmetics.hpp
)

add_library(${This} SHARED
        ${Sources}
        ${Headers}
)