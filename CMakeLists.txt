cmake_minimum_required(VERSION 3.7.0)
project(moderncppchallenge)

message("-------------------------")
message(">    ${CMAKE_CXX_COMPILER}")
message(">    ${CMAKE_CXX_COMPILER_ID}")
message("-------------------------")

if(MSVC)
    message(status "** Setting MSVC flags")
    add_compile_options(/W4)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(status "** Setting GCC flags")
    add_compile_options(-std=c++11 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(status "** Setting Clang flags")
    add_compile_options(-std=c++11 -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic)
endif()

#set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(Chapter01/01)
add_subdirectory(Chapter01/02)
add_subdirectory(Chapter01/03)
add_subdirectory(Chapter01/04)
add_subdirectory(Chapter01/05)
add_subdirectory(Chapter02/15)


