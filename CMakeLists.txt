cmake_minimum_required(VERSION 3.10)
project(COMP472_miniproject3)

set(CMAKE_CXX_STANDARD 14)

add_executable(COMP472_miniproject3 main.cpp LanguageModel.cpp LanguageModel.hpp MyException.cpp MyException.hpp)
