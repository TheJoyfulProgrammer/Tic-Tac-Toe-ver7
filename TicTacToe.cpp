/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    March 10th, 2020
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:    https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C++ ver 17
    Tested Compilers:         G++ ver 9.3, TDM-GCC 9.0 (Doesn't work in MingW)
    Tested Operating Systems: Linux Mint 19, Windows 10
    Description: A highly-optimized, Tic Tac Toe game.
*/

#include <iostream>
#include <experimental/random>
#include <vector>
#include <string>
#include "TicTacToe.hpp"

namespace t3
{
    uint8_t PlayableBoardPositions[MaximumNumberOfPlayingPositions];

    int BoardPositionsRemaining{MaximumNumberOfPlayingPositions};

    uint32_t GameBoard{0};

    // Our simple TicTacToe board for display.
    std::string BoardDisplay("");

    void ResetBoard()
    {
        // Reset the display game board
        t3::BoardDisplay = "   |   |   \n"
                           " 8 | 7 | 6 \n"
                           "   |   |   \n"
                           "---+---+---\n"
                           "   |   |   \n"
                           " 5 | 4 | 3 \n"
                           "   |   |   \n"
                           "---+---+---\n"
                           "   |   |   \n"
                           " 2 | 1 | 0 \n"
                           "   |   |   \n";

        // Remove any and all plays made by players
        t3::GameBoard = 0;

        // The total number of the playing board
        t3::BoardPositionsRemaining = MaximumNumberOfPlayingPositions;

        // Reset the playable board positions
        for(uint8_t Iterator1 = 0; Iterator1 < MaximumNumberOfPlayingPositions; Iterator1++) t3::PlayableBoardPositions[Iterator1] = Iterator1;
    }


    uint8_t GameStatus()
    {
        // Unrolled loops here... This is the fastest possible method to calculate wins.
        // This uses simple bit logic mathematics to determine if either player has won, which allows us to test
        // for a win in one statement, instead of a ton of IF...ELSE statements.
        uint8_t PlayerWins = ((t3::GameBoard & t3::WinPositions[0]) == t3::WinPositions[0]) |
                             (((t3::GameBoard & (t3::WinPositions[0] << 1)) == (t3::WinPositions[0] << 1)) << 1) |
                             ((t3::GameBoard & t3::WinPositions[1]) == t3::WinPositions[1]) |
                             (((t3::GameBoard & (t3::WinPositions[1] << 1)) == (t3::WinPositions[1] << 1)) << 1) |
                             ((t3::GameBoard & t3::WinPositions[2]) == t3::WinPositions[2]) |
                             (((t3::GameBoard & (t3::WinPositions[2] << 1)) == (t3::WinPositions[2] << 1)) << 1) |
                             ((t3::GameBoard & t3::WinPositions[3]) == t3::WinPositions[3]) |
                             (((t3::GameBoard & (t3::WinPositions[3] << 1)) == (t3::WinPositions[3] << 1)) << 1) |
                             ((t3::GameBoard & t3::WinPositions[4]) == t3::WinPositions[4]) |
                             (((t3::GameBoard & (t3::WinPositions[4] << 1)) == (t3::WinPositions[4] << 1)) << 1) |
                             ((t3::GameBoard & t3::WinPositions[5]) == t3::WinPositions[5]) |
                             (((t3::GameBoard & (t3::WinPositions[5] << 1)) == (t3::WinPositions[5] << 1)) << 1) |
                             ((t3::GameBoard & t3::WinPositions[6]) == t3::WinPositions[6]) |
                             (((t3::GameBoard & (t3::WinPositions[6] << 1)) == (t3::WinPositions[6] << 1)) << 1) |
                             ((t3::GameBoard & t3::WinPositions[7]) == t3::WinPositions[7]) |
                             (((t3::GameBoard & (t3::WinPositions[7] << 1)) == (t3::WinPositions[7] << 1)) << 1);

        // Return value: GameStillPlayable = 0, PlayerXWins = 1, PlayerYWins = 2, GameTime = 3
        // The "Tie Game" is only determined if all spots have been played.
        return PlayerWins + ((t3::BoardPositionsRemaining == 0) * 3) * !PlayerWins;
    }


    void SetPosition(const uint32_t BoardPosition, const uint32_t Player)
    {
        // Place the player on the Game Board
        t3::GameBoard = t3::GameBoard | (1 << (BoardPosition + BoardPosition + Player));

        // Place the ASCII character of the player on the drawable ASCII board.
        t3::BoardDisplay.replace(t3::PlayablePosition[BoardPosition], 1, t3::PlayerPiece[Player]);
    }


    // A poor man's AI algorithm.
    void AiPickRandomPosition(const uint32_t Player)
    {
        int ArrayPointer = std::experimental::randint(1, t3::BoardPositionsRemaining) - 1;

        SetPosition(t3::PlayableBoardPositions[ArrayPointer], Player);

        std::swap(t3::PlayableBoardPositions[ArrayPointer], t3::PlayableBoardPositions[t3::BoardPositionsRemaining - 1]);
        t3::BoardPositionsRemaining--;
    }
}
