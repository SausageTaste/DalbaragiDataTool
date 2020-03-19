cmake_minimum_required(VERSION 3.4.1)

project(DalbaragiDataTool
    LANGUAGES CXX
)


### Create library

set(lib_inclusion_path ./include)

add_library(dalDataTool
    ${lib_inclusion_path}/daltool/u_byteutils.h   src/u_byteutils.cpp
    ${lib_inclusion_path}/daltool/d_mapdata.h     src/d_mapdata.cpp
    ${lib_inclusion_path}/daltool/d_dlbparser.h   src/d_dlbparser.cpp
)
target_include_directories(dalDataTool PUBLIC ${lib_inclusion_path})
target_compile_features(dalDataTool PUBLIC cxx_std_14)


### Link to library

set(repo_root_dir ${CMAKE_CURRENT_SOURCE_DIR})
set(extern_dir ${repo_root_dir}/extern)

# miniz
if (NOT TARGET miniz)
    add_subdirectory(${extern_dir}/miniz ${CMAKE_CURRENT_BINARY_DIR}/miniz)
    target_link_libraries(dalDataTool PRIVATE miniz)
    target_include_directories(dalDataTool PRIVATE ${extern_dir}/miniz ${CMAKE_CURRENT_BINARY_DIR}/miniz)
endif()

# GLM
if (NOT TARGET glm::glm)
    add_subdirectory(${extern_dir}/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
    target_include_directories(dalDataTool PUBLIC ${extern_dir}/glm)
endif()

### Test

enable_testing()
add_subdirectory(tests)
