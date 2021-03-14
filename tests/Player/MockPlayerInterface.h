#include <gmock/gmock.h>

#include "src/Player/PlayerInterface.h"

namespace Player {
    class MockPlayerInterface : public PlayerInterface
    {
    public:
        MOCK_METHOD(uint8_t, getId, (), (override));
        MOCK_METHOD(Board::Position, move, (), (override));
    };
}