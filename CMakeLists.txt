cmake_minimum_required(VERSION 3.27)
project(Proyecto)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL CONFIG REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Proyecto main.cpp arbol.cpp curl_helper.cpp
        arbolAvl.cpp
        arbolAvl.h)

target_link_libraries(Proyecto PRIVATE CURL::libcurl)
