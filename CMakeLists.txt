cmake_minimum_required(VERSION 3.20)

project(VM)

set(CMAKE_CXX_STANDARD 20)

add_executable(Runner Main.cpp VM.cpp VM.hpp)