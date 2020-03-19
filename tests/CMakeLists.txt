cmake_minimum_required(VERSION 3.4.1)

project(DalbaragiDataTool-Test
    LANGUAGES CXX
)


add_executable(testtest testtest.cpp)
target_link_libraries(testtest dalDataTool)

add_test(testTarget testtest)
