cmake_minimum_required(VERSION 3.21)
project(Memory_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Memory_game main.cpp Server/Server.cpp headers/Server.h Server/CommandHandler.cpp headers/CommandHandler.h Game.cpp headers/Game.h PagedMatrix/DiskMatrix.cpp headers/DiskMatrix.h PagedMatrix/PagedArray.cpp headers/PagedArray.h headers/Card.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(/home/tavo/Descargas/json-develop/include)
