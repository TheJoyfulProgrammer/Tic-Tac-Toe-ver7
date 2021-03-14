cmake_minimum_required(VERSION 3.17)
project(Tic_Tac_Toe_ver7)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

# check if google test is installed
find_package(GTest REQUIRED)

include_directories(
        .
        ${GTEST_INCLUDE_DIR}
)

# build the original tic-tac-toe
add_executable(tic-tac-toe-original
        Tic-Tac-Toe-v7.cpp
        ctinterface-utils.cpp
        ctinterface-utils.hpp
        TicTacToe.cpp
        TicTacToe.hpp
        )

add_executable(
        testsRunner
        tests/testMain.cpp
        tests/Board/BoardTest.cpp
        src/Board/Board.cpp
        src/Player/PlayerInterface.h tests/Player/MockPlayerInterface.h src/Board/Position.h)
target_link_libraries(testsRunner ${GTEST_LIBRARIES} gmock pthread)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()