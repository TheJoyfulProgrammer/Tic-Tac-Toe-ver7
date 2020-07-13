/*
    ctinterface: Various utilities written by The Joyful Programmer

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
#include "ctinterface-utils.hpp"

#ifdef __WIN32
    #include <windows.h>
#endif
#ifdef __linux__
#endif


namespace ctinterface
{
    uint8_t CurrentWinColor;

    #ifdef __WIN32
        uint16_t OSColors[16]{Black, Blue, Green, Cyan,
                               Red, Magenta, Yellow, White,
                               BrightBlack, BrightBlue, BrightGreen,
                               BrightCyan, BrightRed, BrightMagenta,
                               BrightWhite};
    #endif
    #ifdef __linux__
        uint16_t OSColors[16]{Black + LowColor, Red + LowColor, Green + LowColor,
                               Yellow + LowColor, Blue + LowColor, Magenta + LowColor,
                               Cyan + LowColor, White + LowColor, BrightBlack + HighColor,
                               BrightRed + HighColor, BrightGreen + HighColor,
                               BrightYellow + HighColor, BrightBlue + HighColor,
                               BrightMagenta + HighColor, BrightCyan + HighColor,
                               BrightWhite + HighColor};

        std::string TerminalBackgroundColors[16]{"#000000", "#CD0000", "#00CD00", "#CDCD00",
                                                  "#0000EE", "#CD00CD", "#00CDCD", "#E5E5E5",
                                                  "#7F7F7F", "#FF0000", "#00FF00", "#FFFF00",
                                                  "#5C5CFF", "#FF00FF", "#00FFFF", "#FFFFFF"};
    #endif

    #ifdef __WIN32
        COORD CursorCoords = {0, 0};

        HHOOK KeyboardHook;

        HANDLE StdInHandle = GetStdHandle( STD_INPUT_HANDLE );
        HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

        CONSOLE_SCREEN_BUFFER_INFOEX csbiEX;
    #endif

    #ifdef __linux__
    #endif


    void SetCtInterfaceColors(const uint8_t ForegroundColor, const uint8_t BackgroundColor)
    {
        #ifdef __WIN32
            ctinterface::Color(ctinterface::OSColors[ForegroundColor], ctinterface::OSColors[BackgroundColor]);
            ctinterface::ClearScreen();
        #endif // __WIN32

        #ifdef __linux__
            std::cout << "\033]10;" << ctinterface::TerminalBackgroundColors[ForegroundColor] << "\007";
            std::cout << "\033]11;" << ctinterface::TerminalBackgroundColors[BackgroundColor] << "\007";
            ctinterface::Color(ForegroundColor, BackgroundColor);
        #endif // __linux__
    }

    void Color(const uint8_t ForegroundColor)
    {
        ctinterface::CurrentWinColor = (ctinterface::CurrentWinColor & 0xF0) | (ForegroundColor & 0x0F);

        #ifdef __WIN32
            SetConsoleTextAttribute(ctinterface::hstdout, ctinterface::CurrentWinColor);
        #endif

        #ifdef __linux__
            std::cout << "\033["
                      << ctinterface::OSColors[ForegroundColor]
                      << "m";
        #endif

    }



    void Color(const uint8_t ForegroundColor, const uint8_t BackgroundColor)
    {
        ctinterface::CurrentWinColor = ((BackgroundColor & 0x0F) << 4) | (ForegroundColor & 0x0F);

        #ifdef __WIN32
            SetConsoleTextAttribute(ctinterface::hstdout, ctinterface::CurrentWinColor);
        #endif

        #ifdef __linux__
            std::cout << "\033["
                      << ctinterface::OSColors[ForegroundColor]
                      << "m \033["
                      << (ctinterface::OSColors[BackgroundColor] + 10)
                      << "m";
        #endif
    }



    void ClearScreen()
    {
        #ifdef __WIN32
            DWORD cellCount;
            DWORD counter;

            ctinterface::csbiEX.cbSize = sizeof(ctinterface::csbiEX);
            GetConsoleScreenBufferInfoEx(ctinterface::hstdout, &ctinterface::csbiEX);

            cellCount = ctinterface::csbiEX.dwSize.X * ctinterface::csbiEX.dwSize.Y;

            FillConsoleOutputAttribute(ctinterface::hstdout, ctinterface::CurrentWinColor, cellCount, ctinterface::CursorCoords, &counter);
            FillConsoleOutputCharacter(ctinterface::hstdout, (TCHAR) ' ', cellCount, ctinterface::CursorCoords, &counter);
            SetConsoleCursorPosition(ctinterface::hstdout, ctinterface::CursorCoords );

            SetCursor(0, 0);
        #endif

        #ifdef __linux__
            std::cout << "\033[2J";
        #endif
    }



    void SetCursor(const short x, const short y)
    {
        #ifdef __WIN32
            SetConsoleCursorPosition(ctinterface::hstdout, {x, y} );
        #endif

        #ifdef __linux__
            std::cout << "\033[" << y << ";" << x << "f";
        #endif
    }

    void SetCtInterfaceTitle(const std::string Title)
    {
        #ifdef __WIN32
            SetConsoleTitle(Title.c_str());
        #endif // __WIN32

        #ifdef __linux__
            std::cout << "\033]2;" << Title << "\007";
        #endif // __linux__
    }

}

