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
#ifndef CTINTERFACEUTILS_H

    #define CTINTERFACEUTILS_H

    #ifdef __WIN32
        #include <windows.h>
    #endif
    #ifdef __linux__
    #endif

    namespace ctinterface
    {
        #ifdef __WIN32
            extern UINT8 CurrentWinColor;

            extern COORD CursorCoords;

            extern HHOOK KeyboardHook;

            extern HANDLE hstdout;
            extern HANDLE StdInHandle;

            extern CONSOLE_SCREEN_BUFFER_INFOEX csbiEX;
        #endif

        extern uint16_t OSColors[16];

        #ifdef __WIN32
            #define Black 0
            #define Red 4
            #define Green 2
            #define Yellow 6
            #define Blue 1
            #define Magenta 5
            #define Cyan 3
            #define White 7
            #define BrightBlack 8
            #define BrightRed 12
            #define BrightGreen 10
            #define BrightYellow 14
            #define BrightBlue 9
            #define BrightMagenta 13
            #define BrightCyan 11
            #define BrightWhite 15
        #endif // __WIN32

        #ifdef __linux__
            #define Black 0
            #define Red 1
            #define Green 2
            #define Yellow 3
            #define Blue 4
            #define Magenta 5
            #define Cyan 6
            #define White 7
            #define BrightBlack 8
            #define BrightRed 9
            #define BrightGreen 10
            #define BrightYellow 11
            #define BrightBlue 12
            #define BrightMagenta 13
            #define BrightCyan 14
            #define BrightWhite 15
            #define LowColor 30
            #define HighColor 82
        #endif // __linux__

        extern void SetCtInterfaceColors(const uint8_t, const uint8_t);
        extern void Color(const uint8_t);
        extern void Color(const uint8_t, const uint8_t);
        extern void ClearScreen();
        extern void SetCursor(const short, const short);
        extern void SetCtInterfaceTitle(const std::string);
    }

#endif
