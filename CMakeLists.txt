cmake_minimum_required(VERSION 3.7.0)
project(moderncppchallenge)

message("-------------------------")
message(">    ${CMAKE_CXX_COMPILER}")
message(">    ${CMAKE_CXX_COMPILER_ID}")
message(">    ${CMAKE_CXX_COMPILER_IS_GNUCXX}")
message("-------------------------")

if(MSVC)
    message(status "** Setting MSVC flags")
    add_compile_options(/W4)
elseif(Clang OR GNU)
    message(status "** Setting GCC flags")
    add_compile_options(-std=c++11 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic)
endif()

#set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(Chapter01/01)
add_subdirectory(Chapter01/02)
add_subdirectory(Chapter01/03)
add_subdirectory(Chapter01/04)
add_subdirectory(Chapter01/05)
add_subdirectory(Chapter02/15)


