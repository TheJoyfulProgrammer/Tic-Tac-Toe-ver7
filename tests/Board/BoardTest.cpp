#include <gtest/gtest.h>
#include <tests/Player/MockPlayerInterface.h>

#include "src/Board/Board.h"

class BoardTest : public ::testing::Test
{
protected:
    Board::Board *board;

    void SetUp() override {
        board = new Board::Board();
    }

    void TearDown() override {
        delete board;
    }
};

TEST_F(BoardTest, Board_IsEmptyAfterCreation) {
    for (uint8_t x = 0; x < Board::Board::getRowSize(); x++) {
        for (uint8_t y = 0; y < Board::Board::getRowSize(); y++) {
            EXPECT_EQ(0, board->getIdAt(x, y));
        }
    }
}

TEST_F(BoardTest, getIdAt_OutOfRange_ThrowsOutOfRangeException) {
    EXPECT_THROW(board->getIdAt(99, 0),  std::out_of_range);
    EXPECT_THROW(board->getIdAt(0, 99),  std::out_of_range);
    EXPECT_THROW(board->getIdAt(3, 3), std::out_of_range);
}

TEST_F(BoardTest, getRowSize_ReturnsRowSize) {
    EXPECT_EQ(3u, board->getRowSize());
}

TEST_F(BoardTest, makeMove_PlayerPosition_SetsPlayerIdAtPosition) {
    ::testing::NaggyMock<Player::MockPlayerInterface> player;

    EXPECT_CALL(player, getId())
        .WillRepeatedly(testing::Return(2u));

    Board::Position pos1 = {0u, 2u};
    Board::Position pos2 = {0u, 0u};
    Board::Position pos3 = {2u, 2u};

    EXPECT_CALL(player, move())
        .Times(3)
        .WillOnce(testing::Return(pos1))
        .WillOnce(testing::Return(pos2))
        .WillRepeatedly(testing::Return(pos3));

    board->makeMove(player);
    board->makeMove(player);
    board->makeMove(player);

    EXPECT_EQ(2u, board->getIdAt(pos1));
    EXPECT_EQ(2u, board->getIdAt(0, 0));
    EXPECT_EQ(2u, board->getIdAt(pos3));
}

TEST_F(BoardTest, makeMove_OutOfRange_ThrowsOutOfRangeException) {
    ::testing::NaggyMock<Player::MockPlayerInterface> player;

    EXPECT_CALL(player, getId())
            .WillRepeatedly(testing::Return(2u));

    Board::Position pos1 = {0u, 3u};
    Board::Position pos2 = {3u, 0u};
    Board::Position pos3 = {3u, 3u};

    EXPECT_CALL(player, move())
            .Times(3)
            .WillOnce(testing::Return(pos1))
            .WillOnce(testing::Return(pos2))
            .WillRepeatedly(testing::Return(pos3));

    EXPECT_THROW(board->makeMove(player), std::out_of_range);
    EXPECT_THROW(board->makeMove(player), std::out_of_range);
    EXPECT_THROW(board->makeMove(player), std::out_of_range);
}