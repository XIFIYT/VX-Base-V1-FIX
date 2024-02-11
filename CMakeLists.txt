cmake_minimum_required(VERSION 3.20)

project(VX CXX ASM_MASM)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(CMAKE_ASM_COMPILER_TARGET "${CMAKE_CXX_COMPILER_TARGET}")

# Fetch modules
message("\nFetching modules")
include(scripts/minhook.cmake)
include(scripts/json.cmake)

message("\nFetching custom modules")
include(scripts/gtav-classes.cmake)

file(GLOB_RECURSE SRC_MAIN
    "${SRC_DIR}/**.hpp"
    "${SRC_DIR}/**.h"
    "${SRC_DIR}/**.cpp"
    "${SRC_DIR}/**.cc"
    "${SRC_DIR}/**.cxx"
    "${SRC_DIR}/**.asm"
)
add_library(VX MODULE "${SRC_MAIN}")

link_directories("lib")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET VX PROPERTY CXX_STANDARD 23) # 23 Because std::format is not avalible in std:c++20 for some reason. Maybe it's because i use v142 toolset.

source_group(TREE ${SRC_DIR} PREFIX "src" FILES ${SRC_MAIN})

target_include_directories(VX PRIVATE
    "${SRC_DIR}"
    "${json_SOURCE_DIR}/single_include"
    "${gtav_classes_SOURCE_DIR}"
    "${imgui_SOURCE_DIR}"
    "${discordrpc_SOURCE_DIR}/include"
)

target_precompile_headers(VX PRIVATE "${SRC_DIR}/Common.hpp")

target_link_libraries(VX PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/discord-rpc.lib" minhook)

# Warnings as errors
set_property(TARGET VX PROPERTY COMPILE_WARNING_AS_ERROR ON)

add_compile_options("/FI winapifamily.h")

target_compile_definitions(VX
    PRIVATE "_CRT_SECURE_NO_WARNINGS"
    PRIVATE "NOMINMAX"
    PRIVATE "WIN32_LEAN_AND_MEAN"
    PRIVATE "/NODEFAULTLIB:LIBCMT"
)