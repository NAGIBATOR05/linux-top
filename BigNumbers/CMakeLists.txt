add_library(BigNumbers BigInteger.cpp BigFloat.cpp)

target_include_directories(BigNumbers
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)