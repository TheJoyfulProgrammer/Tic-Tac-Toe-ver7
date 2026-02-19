# Tic-Tac-Toe-ver7

A highly optimized Tic-Tac-Toe project written in C++17 for both Linux and Windows terminals.

## Overview

This repository is organized around three major parts:

1. **Game engine (`t3` namespace)**
   * Encodes the board in a compact bit-mask format.
   * Detects wins/ties efficiently in `CheckStatus()`.
   * Provides automated move selection for self-play.

2. **Cross-platform terminal utilities (`ctinterface` namespace)**
   * Handles color changes, cursor movement, screen clearing, and terminal title updates.
   * Uses conditional compilation so the same source works on Linux and Windows.

3. **Demo/driver application (`Tic-Tac-Toe-v7.cpp`)**
   * Runs many automated games.
   * Prints board state and running statistics.
   * Demonstrates the engine and terminal interface together.

## Project structure

* `TicTacToe.hpp` / `TicTacToe.cpp`  
  Core game logic, board representation, move handling, and status checks.

* `ctinterface-utils.hpp` / `ctinterface-utils.cpp`  
  Console helper utilities for colors, cursor control, clear screen, and title setting.

* `Tic-Tac-Toe-v7.cpp`  
  Main entry point that runs simulation loops and outputs results.

## Build notes

This game can be compiled with:

* GCC toolchain (Linux), tested with GCC 9.3
* TDM-GCC toolchain (Windows), tested with 9.0

> Note: The project does not compile with some MinGW toolchains when using `std::this_thread` functionality.

## Key features

* Cross-platform terminal control utilities:
  * `SetCtInterfaceColors(ForegroundColor, BackgroundColor)`
  * `Color(ForegroundColor)`
  * `Color(ForegroundColor, BackgroundColor)`
  * `ClearScreen()`
  * `SetCursor(XCoord, YCoord)`
  * `SetCtInterfaceTitle(Title)`
* Fast status evaluation in `CheckStatus()` using compact bitwise checks.
* Performance-focused design suitable for very large self-play runs.

## Important concepts for newcomers

* **Bitwise board representation**
  Learn how board state and win patterns are encoded with masks for speed.

* **Platform-specific terminal APIs**
  Linux relies on ANSI escape sequences while Windows uses Win32 console APIs.

* **Simulation-focused design**
  The main loop emphasizes high-throughput automated games instead of interactive gameplay.

## Suggested next steps

* Replace random move selection with minimax or another stronger strategy.
* Add a human-vs-AI interactive mode.
* Add unit tests around board-state transitions and win detection.
* Consider migrating random generation to modern `<random>` APIs where applicable.

This Tic-Tac-Toe engine is designed to be compact, fast, and easy to extend.
