#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Board.h"

TEST(BoardTest, CellTest) {
    Board board(8);
    board.setValueAt(0, 0, Black);
    EXPECT_EQ(board.getValueAt(0, 0), Black);
    board.setValueAt(0, 0, White);
    EXPECT_EQ(board.getValueAt(0, 0), White);
}

TEST(BoardTest, InvalidIndexTest) {
    Board board(8);
    bool status = board.setValueAt(9, 0, Black);
    EXPECT_FALSE(status);
    status = board.setValueAt(-4, 0, Black);
    EXPECT_FALSE(status);
    status = board.setValueAt(3, 8, Black);
    EXPECT_FALSE(status);
    status = board.setValueAt(3, -1, Black);
    EXPECT_FALSE(status);
}

TEST(BoardTest, NumOfColorCellsTest) {
    Board board(8);
    board.setValueAt(0, 0, Black);
    board.setValueAt(1, 4, Black);
    board.setValueAt(0, 3, Black);
    board.setValueAt(4, 4, White);
    board.setValueAt(1, 2, White);
    EXPECT_EQ(board.getNumberOfBlackCells(), 5);
    EXPECT_EQ(board.getNumberOfWhiteCells(), 3);
    board.setValueAt(3, 9, White);
    EXPECT_EQ(board.getNumberOfWhiteCells(), 3);
}

TEST(BoardTest, SizeTest) {
    Board board1(8);
    EXPECT_EQ(board1.getSize(), 8);
    Board board2(3);
    EXPECT_EQ(board2.getSize(), 3);
    Board board3(10);
    EXPECT_EQ(board3.getSize(), 10);
}

TEST(BoardTest, BoardCopy) {
    Board boardSrc(8);
    Board boardDst(boardSrc);
    EXPECT_TRUE(boardSrc == boardDst);
}