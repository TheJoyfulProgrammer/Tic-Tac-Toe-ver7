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
#include <ctime>
#include <chrono>
#include <thread>
#include "TicTacToe.hpp"
#include "ctinterface-utils.hpp"

    
int main()
{
    // remove the comments in the line below to watch the game play itself.
    //#define ShowGamePlay

    uint8_t CurrentPlayer{0};
    uint32_t NumberOfGames{1'000'000};
    uint32_t Iterator1{0};
    uint32_t Status[]{0, 0, 0};
    uint16_t CurrentGameStatus{0};
    uint32_t Counter{0};

    std::string GameTitle{"Tic Tac Toe - ver7 - By The Joyful Programmer"};

    #ifdef __WIN32
        GameTitle += " (Windows Version)";
    #endif // __WIN32

    #ifdef __linux__
        GameTitle += " (Linux Version)";
    #endif // __linux__

    // These game messages correspond to the return value from Game Status. 0, 1, 2, 3
    std::vector<std::string> GameMessages{"Next player get ready!", "Player X Wins!", "Player Y Wins!", "Game is a Tie!"};

    std::time_t StartTimer;
    std::time_t EndTimer;

    ctinterface::SetCtInterfaceTitle(GameTitle);
    ctinterface::SetCtInterfaceColors(BrightYellow, Blue);

    std::srand(time(NULL));

    time(&StartTimer);

    for(Iterator1 = 0; Iterator1 < NumberOfGames; Iterator1++)
    {
        // Start a new Tic Tac Toe game
        t3::ResetBoard();

        ctinterface::SetCursor(0, 0);

        #ifdef ShowGamePlay
            ctinterface::ClearScreen();
        #endif

        // Have the game engine play one game with itself.
        // This DO...WHILE loop should be self explanatory.
        do
        {
            t3::AiPickRandomPosition(CurrentPlayer);
            CurrentPlayer = (CurrentPlayer + 1) % 2;
            CurrentGameStatus = t3::GameStatus();

            #ifdef ShowGamePlay
                ctinterface::SetCursor(0, 0);
                ctinterface::Color(BrightYellow);
                std::cout << t3::BoardDisplay;

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            #endif
        } while (CurrentGameStatus == 0);

        // Increment either the "PlayerX Wins", "PlayerY Wins", or "Tie Game" counter
        // so we can keep track of them.
        Status[CurrentGameStatus - 1]++;

        time(&EndTimer);
        EndTimer -= StartTimer;
        
        //std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        
        // Prevent the game stat message from updating until all games have played.
        // This will give us the actual time it takes to play those games.
        #ifndef ShowGamePlay
        if((Counter % (NumberOfGames - 1)) == 0) // COMMENT THIS OUT IF YOU WANT
        {                                        // TO SEE A GAME BY GAME PLAY.
        #endif
        
           ctinterface::SetCursor(0, 0);

            ctinterface::Color(BrightYellow);
            std::cout << t3::BoardDisplay;

            ctinterface::Color(BrightBlue);
            ctinterface::SetCursor(0, 13);
            std::cout << GameMessages[CurrentGameStatus] << "          ";

            ctinterface::SetCursor(27, 2);
            std::cout << (Iterator1 + 1) << " of " << NumberOfGames;

            ctinterface::SetCursor(27, 5);
            std::cout << "Game Status: " << CurrentGameStatus;

            ctinterface::SetCursor(27, 7);
            std::cout << "X Wins: " << Status[0];

            ctinterface::SetCursor(27, 9);
            std::cout << "Y Wins: " << Status[1];

            ctinterface::SetCursor(29, 11);
            std::cout << "Ties: " << Status[2];

            ctinterface::SetCursor(28, 13);
            std::cout << "Timer: " << EndTimer << " seconds...";

            // We need to use the std::endl function just once so we know the terminal is
            // updated correctly when we want to print this information a lot in a short
            // period of time. This is the only time I ever had to use this function in a
            // real project.
            std::cout << std::endl;

            // Pause the demo long enough to see the current information.
            //std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            #ifdef ShowGamePlay
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            #endif // ShowGamePlay

        #ifndef ShowGamePlay
        }
        #endif
        
        Counter++;
    }

    ctinterface::SetCursor(0, 20);

    // Pause the program so it does not close too quickly.
    //std::this_thread::sleep_for(std::chrono::milliseconds(20000));
}
