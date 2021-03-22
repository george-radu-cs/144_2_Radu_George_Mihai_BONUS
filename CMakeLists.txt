cmake_minimum_required (VERSION 3.5)

project(144_2_Radu_George_Mihai_BONUS VERSION 1.0)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.h" "${source_dir}/*.cpp")

add_executable (144_2_Radu_George_Mihai_BONUS ${source_files})

target_compile_features(144_2_Radu_George_Mihai_BONUS PRIVATE cxx_lambda_init_captures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
