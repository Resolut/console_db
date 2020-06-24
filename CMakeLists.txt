cmake_minimum_required(VERSION 3.5)

project(db_clients LANGUAGES CXX)

set(SOURCES 
    src/main.cpp
    src/dbengine.cpp
)

set(HEADERS 
    src/dbengine.h
    src/person.h
)

add_executable(db_client ${SOURCES} ${HEADERS})

set_target_properties(
    version PROPERTIES
    set(CXX_STANDARD 11)
    set(CXX_STANDARD_REQUIRED ON)
)
