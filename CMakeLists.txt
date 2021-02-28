cmake_minimum_required(VERSION 3.17)
project(Tic_Tac_Toe_ver7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tic-tac-toe
        Tic-Tac-Toe-v7.cpp
        ctinterface-utils.cpp
        ctinterface-utils.hpp
        TicTacToe.cpp
        TicTacToe.hpp)
