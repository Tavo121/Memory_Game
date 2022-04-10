cmake_minimum_required(VERSION 3.21)
project(Memory_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Memory_game main.cpp Server.cpp headers/Server.h CommandHandler.cpp headers/CommandHandler.h Game.cpp headers/Game.h DiskMatrix.cpp headers/DiskMatrix.h)

include_directories(/home/tavo/Descargas/json-develop/include)
