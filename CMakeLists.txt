cmake_minimum_required(VERSION 3.5)
project(COMP472_miniproject3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_executable(uni-bigram-model
        main.cpp
        LanguageModel.cpp
        LanguageModel.hpp
        UniGram.cpp
        BiGram.cpp
        SentenceClassifier.cpp
        SentenceClassifier.hpp
        utils.cpp)
