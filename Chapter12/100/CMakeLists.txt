cmake_minimum_required (VERSION 3.7.0) 
project(problem_100)

#Add -D define flags to the compilation of source files.
#Add definitions to the compiler command line for targets in the current directory and below
#add_definitions(-DCURL_STATICLIB)

#Add the given directories to those the compiler uses to search for include files.
include_directories(${LIBS_PATH}/json/single_include)
include_directories(${LIBS_PATH}/curl/include)
include_directories(${LIBS_PATH}/curlcpp/include)

# Add an executable to the project using the specified source files.
add_executable(problem_100 main.cpp)

#Specify libraries or flags to use when linking a given target and/or its dependents.
#Same as compiler flags g++ main.cpp -lcurl
#The linker searches a standard list of directories for the library.
#The directories searched include several standard system directories plus any that you specify with -L.
#Static libraries are archives of object files, and have file names like liblibrary.a.
#Some targets also support shared libraries, which typically have names like liblibrary.so.
#If both static and shared libraries are found, the linker gives preference to linking with the shared library unless the -static option is used.

target_link_libraries(problem_100 "${LIBS_PATH}/curlcpp/build/src/libcurlcpp.a")
#####################################################################
#TODO: Find out why linking does not work with static libcurl.a library 
#target_link_libraries(problem_100 "${LIBS_PATH}/curl/build/lib/libcurl.a")
#target_link_libraries(problem_100 "/usr/lib/libcurl.so")
#target_link_libraries(problem_100 libcurlcpp)
target_link_libraries(problem_100 curl)


if (UNIX)
   #Add directories in which the linker will look for libraries
   link_directories(${LIBS_PATH}/curlcpp/build/src)
elseif(WIN32) 

endif() 
