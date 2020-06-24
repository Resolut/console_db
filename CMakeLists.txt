cmake_minimum_required(VERSION 3.5)

project(db_clients LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(db_clients main.cpp dbengine.cpp dbengine.h person.h )
