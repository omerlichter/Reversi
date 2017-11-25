//
// Created by omer on 11/25/17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../AIPlayer.h"
#include "../ReversiLogic.h"

TEST(AIPlayerTest, ChooseMoveTest) {
    Board board(8);
    ReversiLogic reversiLogic;
    AIPlayer player;
    Point point1(3, 4);
    reversiLogic.makeMove(Black, point1, board);
    vector<Point>* possiblePoints = reversiLogic.moveOptions(White, board);
    Point* chosenPoint = player.chooseMove(possiblePoints, reversiLogic, board);
    EXPECT_EQ(chosenPoint->getRow(), 3);
    EXPECT_EQ(chosenPoint->getColumn(), 3);
    reversiLogic.makeMove(White, *chosenPoint, board);
    delete(possiblePoints);
    delete(chosenPoint);
    Point point2(5, 6);
    reversiLogic.makeMove(Black, point2, board);
    possiblePoints = reversiLogic.moveOptions(White, board);
    chosenPoint = player.chooseMove(possiblePoints, reversiLogic, board);
    EXPECT_EQ(chosenPoint->getRow(), 6);
    EXPECT_EQ(chosenPoint->getColumn(), 6);
    delete(possiblePoints);
    delete(chosenPoint);
}

TEST(AIPlayerTest, FullBoardChooseMoveTest) {
    Board board(8);
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            board.setValueAt(i, j, Black);
        }
    }
    ReversiLogic reversiLogic;
    AIPlayer player;
    vector<Point>* possiblePoints = reversiLogic.moveOptions(White, board);
    Point* chosenPoint = player.chooseMove(possiblePoints, reversiLogic, board);
    EXPECT_EQ(chosenPoint->getRow(), -1);
    EXPECT_EQ(chosenPoint->getColumn(), -1);
    delete(possiblePoints);
    delete(chosenPoint);
}