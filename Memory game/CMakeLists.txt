cmake_minimum_required(VERSION 3.21)
project(Memory_game)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(SFML 2.5.1 REQUIRED system window graphics network audio)

add_executable(Memory_game main.cpp Server/Server.cpp headers/Server.h Server/CommandHandler.cpp headers/CommandHandler.h Game.cpp headers/Game.h PagedMatrix/DiskMatrix.cpp headers/DiskMatrix.h PagedMatrix/PagedArray.cpp headers/PagedArray.h headers/Card.h Server/ServerInterface.cpp headers/ServerInterface.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

target_link_libraries(Memory_game sfml-graphics sfml-audio)

include_directories(/home/tavo/Descargas/json-develop/include)
