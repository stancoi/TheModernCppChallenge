cmake_minimum_required(VERSION 3.7.0)
project(moderncppchallenge)

if (MSVC)
    message(status "** Setting MSVC flags")
    add_compile_options(/W4)
else()
    message(status "** Setting GCC/clang flags")
    add_compile_options(-std=c++11 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic)
endif()

#set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(Chapter01/01)
add_subdirectory(Chapter01/02)
add_subdirectory(Chapter01/03)

