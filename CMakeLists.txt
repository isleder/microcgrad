cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

project(microcgrad)

set(SOURCES 
    src/main.cpp
    src/value.h
)

add_executable(${PROJECT_NAME} ${SOURCES})


