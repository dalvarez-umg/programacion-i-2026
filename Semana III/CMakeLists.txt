cmake_minimum_required(VERSION 4.1)
project(Semana_III)

set(CMAKE_CXX_STANDARD 20)

add_executable(holaMundo_1 ejemplos/holaMundo_1.cpp
        ejemplos/int.cpp
        ejemplos/float.cpp
        ejemplos/double.cpp
        ejemplos/char.cpp
        ejemplos/boole.cpp
        ejemplos/string.cpp
)
add_executable(holaMundo_2 ejemplos/holaMundo_2.cpp)