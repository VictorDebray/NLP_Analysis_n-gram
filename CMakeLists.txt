cmake_minimum_required(VERSION 3.10)
project(COMP472_miniproject3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(.)
add_executable(COMP472_miniproject3
    main.cpp 
    LanguageModel.cpp
        UniGram.cpp
        BiGram.cpp
    SentenceClassifier.cpp
    utils.cpp)
