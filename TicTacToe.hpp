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

#pragma once
#ifndef T3
    #define T3

    #include <vector>
    #include <string>
    #include <sstream>
    #include <bitset>

    namespace t3
    {
        #define MaximumNumberOfPlayingPositions 9

        // These are all the possible wins on a Tic Tac Toe board
        // Player X - Odd bits
        // Player Y - Even bits
        //
        // WinPositions:                                 YX YXYX YXYX YXYX YXYX  <-- PLAYER
        //                                               88 7766 5544 3322 1100  <-- BOARD POSITION
        //                            0b0000'0000'0000'0000'0000'0000'0000'0000  <-- BIT FLAG: 0 = NOT PLAYED, 1 = PLAYED
        //
        const uint32_t WinPositions[]{0b0000'0000'0000'0001'0101'0000'0000'0000,  //  8 7 6
                                      0b0000'0000'0000'0000'0000'0101'0100'0000,  //  5 4 3
                                      0b0000'0000'0000'0000'0000'0000'0001'0101,  //  2 1 0
                                      0b0000'0000'0000'0001'0000'0100'0001'0000,  //  8 5 2
                                      0b0000'0000'0000'0000'0100'0001'0000'0100,  //  7 4 1
                                      0b0000'0000'0000'0000'0001'0000'0100'0001,  //  6 3 0
                                      0b0000'0000'0000'0001'0000'0001'0000'0001,  //  8 4 0
                                      0b0000'0000'0000'0000'0001'0001'0001'0000}; //  6 4 2

        // These are the offset positions that correspond to the character positions in the Board string
        const uint8_t PlayablePosition[]{117, 113, 109, 69, 65, 61, 21, 17, 13};

        // These are the characters we are using for the players in the game
        const std::string PlayerPiece[]{"X", "Y"};

        extern const uint8_t PlayablePosition[MaximumNumberOfPlayingPositions];
        extern const uint32_t WinPositions[];

        extern uint32_t GameBoard;

        extern int BoardPositionsRemaining;

        extern std::string BoardDisplay;

        extern void ResetBoard();
        extern uint8_t GameStatus();
        extern void SetPosition(const uint32_t, const uint32_t);
        extern void AiPickRandomPosition(const uint32_t);
    }
#endif
