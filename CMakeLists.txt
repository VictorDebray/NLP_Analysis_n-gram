cmake_minimum_required(VERSION 3.10)
project(COMP472_miniproject3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_executable(COMP472_miniproject3
    main.cpp 
    LanguageModel.cpp 
    LanguageModel.hpp
    SentenceClassifier.cpp
    SentenceClassifier.hpp 
    utils.cpp)
