cmake_minimum_required (VERSION 0.1)
project (vk_maps_internship)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++17 -Wall -Wextra -Iinclude")


set(include_dest "include/")

add_subdirectory(src)
add_subdirectory(gtest)