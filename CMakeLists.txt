cmake_minimum_required(VERSION 3.25)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(main
src/main.cpp
src/SubstringTable.cpp
src/SubstringTable.hpp
) 

add_executable(Tests
src/Tests.cpp
src/SubstringTable.cpp
src/SubstringTable.hpp
) 
