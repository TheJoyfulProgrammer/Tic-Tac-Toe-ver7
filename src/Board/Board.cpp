#include <iostream>
#include <stdexcept>

#include "Board.h"

namespace Board {
    Board::Board()
    {
        board = new uint8_t[ROW_SIZE * ROW_SIZE];
        reset();
    }

    Board::~Board()
    {
        delete[] board;
    }

    void Board::reset()
    {
        std::fill_n(board, sizeof(*board), 0);
    }

    PlayerId_t Board::getIdAt(uint8_t x, uint8_t y) const
    {
        if (isOutOfRange(x, y)) {
            throw std::out_of_range("Out of Range");
        }

        return board[y * ROW_SIZE + x];
    }

    PlayerId_t Board::getIdAt(Position &pos) const
    {
        return getIdAt(pos.x, pos.y);
    }

    void Board::makeMove(Player::PlayerInterface &player)
    {
        Position pos = player.move();

        if (isOutOfRange(pos.x, pos.y)) {
            throw std::out_of_range("Out of Range");
        }

        board[pos.y * ROW_SIZE + pos.x] = player.getId();
    }
}