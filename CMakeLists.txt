cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(deck)
add_executable(deck main.cpp Deck.cpp)

enable_testing()
add_subdirectory(tests)
