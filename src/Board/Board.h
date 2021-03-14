#pragma once

#include <unictype.h>
#include <src/Player/PlayerInterface.h>

namespace Board {
    class Board {
    private:
        PlayerId_t* board;
        static const uint8_t ROW_SIZE = 3u;
    public:
        Board();
        ~Board();
        void reset();

        static inline uint8_t getRowSize() { return ROW_SIZE; }

        PlayerId_t getIdAt(uint8_t x, uint8_t y) const;
        PlayerId_t getIdAt(Position &pos) const;

        void makeMove(Player::PlayerInterface &player);

    protected:
        static inline bool isOutOfRange(uint8_t x, uint8_t y) { return x >= ROW_SIZE || y >= ROW_SIZE; }
    };
}