cmake_minimum_required(VERSION 3.7.0)
project(moderncppchallenge)

message("-------------------------")
message(">    ${CMAKE_CXX_COMPILER}")
message(">    ${CMAKE_CXX_COMPILER_ID}")
message("-------------------------")

if(MSVC)
    message(status "** Setting MSVC flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
    add_compile_options(/W4 /w14640)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(status "** Setting GCC flags")
    add_compile_options(-std=c++17 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(status "** Setting Clang flags")
    add_compile_options(-std=c++17 -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic)
endif()

set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/include")
set(LIBS_PATH "${CMAKE_SOURCE_DIR}/libs")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Adds a subdirectory to the build. The source_dir specifies the directory in which the source CMakeLists.txt
# and code files are located.
#add_subdirectory(${LIBS_PATH}/curl)
#add_subdirectory(${LIBS_PATH}/curlcpp)
#Add the given directories to those the compiler uses to search for include files.
#include_directories(${CURLCPP_SOURCE_DIR}/include)

add_subdirectory(Chapter01/01)
add_subdirectory(Chapter01/02)
add_subdirectory(Chapter01/03)
add_subdirectory(Chapter01/04)
add_subdirectory(Chapter01/05)
add_subdirectory(Chapter01/11)
add_subdirectory(Chapter01/14)
add_subdirectory(Chapter02/15)
add_subdirectory(Chapter02/16)
add_subdirectory(Chapter02/17)
add_subdirectory(Chapter02/18)
add_subdirectory(Chapter02/19)
add_subdirectory(Chapter02/20)
add_subdirectory(Chapter02/21)
add_subdirectory(Chapter12/100)

