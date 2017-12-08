#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Board.h"
#include "../ReversiLogic.h"

TEST(ReversiLogicTest, InitPossibleMovesTest) {
    Board board(8);
    ReversiLogic reversiLogic;
    vector<Point>* possibleMoves = reversiLogic.moveOptions(Black, board);
    ASSERT_EQ(possibleMoves->size(), 4);
    EXPECT_EQ(possibleMoves->at(0).getRow(), 3);
    EXPECT_EQ(possibleMoves->at(0).getColumn(), 4);
    EXPECT_EQ(possibleMoves->at(1).getRow(), 4);
    EXPECT_EQ(possibleMoves->at(1).getColumn(), 3);
    EXPECT_EQ(possibleMoves->at(2).getRow(), 5);
    EXPECT_EQ(possibleMoves->at(2).getColumn(), 6);
    EXPECT_EQ(possibleMoves->at(3).getRow(), 6);
    EXPECT_EQ(possibleMoves->at(3).getColumn(), 5);
    delete(possibleMoves);
    possibleMoves = reversiLogic.moveOptions(White, board);
    ASSERT_EQ(possibleMoves->size(), 4);
    EXPECT_EQ(possibleMoves->at(0).getRow(), 3);
    EXPECT_EQ(possibleMoves->at(0).getColumn(), 5);
    EXPECT_EQ(possibleMoves->at(1).getRow(), 4);
    EXPECT_EQ(possibleMoves->at(1).getColumn(), 6);
    EXPECT_EQ(possibleMoves->at(2).getRow(), 5);
    EXPECT_EQ(possibleMoves->at(2).getColumn(), 3);
    EXPECT_EQ(possibleMoves->at(3).getRow(), 6);
    EXPECT_EQ(possibleMoves->at(3).getColumn(), 4);
    delete(possibleMoves);
}

TEST(ReversiLogicTest, NoPossibleMoveTest) {
    Board board(8);
    ReversiLogic reversiLogic;
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            board.setValueAt(i, j, Black);
        }
    }
    vector<Point>* possibleMoves = reversiLogic.moveOptions(Black, board);
    EXPECT_EQ(possibleMoves->size(), 0);
    delete(possibleMoves);
    possibleMoves = reversiLogic.moveOptions(White, board);
    EXPECT_EQ(possibleMoves->size(), 0);
    delete(possibleMoves);

    Board board2(8);
    board2.setValueAt(5, 6, Black);
    board2.setValueAt(6, 4, White);
    board2.setValueAt(5, 3, Black);
    board2.setValueAt(4, 6, White);
    board2.setValueAt(3, 5, Black);
    board2.setValueAt(6, 6, White);
    board2.setValueAt(5, 7, Black);
    board2.setValueAt(6, 5, White);
    board2.setValueAt(7, 5, Black);

    possibleMoves = reversiLogic.moveOptions(Black, board);
    EXPECT_EQ(possibleMoves->size(), 0);
    delete(possibleMoves);
    possibleMoves = reversiLogic.moveOptions(White, board);
    EXPECT_EQ(possibleMoves->size(), 0);
    delete(possibleMoves);

}

TEST(ReversiLogicTest, MakeMoveTest) {
    Board board(8);
    ReversiLogic reversiLogic;
    Point point1(3, 4);
    reversiLogic.makeMove(Black, point1, board);
    // is 4,4 point
    EXPECT_EQ(board.getValueAt(3, 3), Black);
}

TEST(ReversiLogicTest, InvalidMakeMoveTest) {
    Board board(4);
    ReversiLogic reversiLogic;
    Point point1(-2, 5);
    bool status = reversiLogic.makeMove(Black, point1, board);
    EXPECT_FALSE(status);
    Point point2(5, 4);
    status = reversiLogic.makeMove(Black, point2, board);
    EXPECT_FALSE(status);
}

TEST(ReversiLogicTest, IsValidPoint) {
    ReversiLogic reversiLogic;
    vector<Point>* points = new vector<Point>;
    Point point1(3,4);
    Point point2(1,2);
    points->push_back(point1);
    points->push_back(point2);
    bool status = reversiLogic.isValidPoint(points, point1);
    EXPECT_TRUE(status);
    Point point3(5,6);
    status = reversiLogic.isValidPoint(points, point3);
    EXPECT_FALSE(status);
    delete(points);
}
