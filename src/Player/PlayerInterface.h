#pragma once

#include <src/Board/Position.h>
typedef uint8_t PlayerId_t;

namespace Player {
    class PlayerInterface
    {
    public:
        virtual ~PlayerInterface() = default;
        virtual PlayerId_t getId() = 0;
        virtual Board::Position move() = 0;
    };
}