cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(ScriptPath src/)

add_executable(TicTacToe ${ScriptPath}main.cpp)

add_library(GameManager ${ScriptPath}GameManager.h ${ScriptPath}GameManager.cpp)
add_library(Map ${ScriptPath}Map.h ${ScriptPath}Map.cpp)
add_library(systemClear ${ScriptPath}systemClear.h ${ScriptPath}systemClear.cpp)

target_link_libraries(TicTacToe PUBLIC GameManager)
target_link_libraries(TicTacToe PUBLIC Map)
target_link_libraries(TicTacToe PUBLIC systemClear)

