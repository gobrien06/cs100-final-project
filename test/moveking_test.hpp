#ifndef __MOVEKING_TEST_HPP__
#define __MOVEKING_TEST_HPP__

#include "gtest/gtest.h"

#include "test_global.h"

#include "../source/MoveVisitor.h"
#include "../source/Piece.h"
#include "../source/Board.h"

TEST(MoveTest, BKingAtEndI)
{
    //black rook at end of board
    King boardKing(0, 0, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKing.acceptMove(testMove);

    EXPECT_EQ(test, "1 1\n1 0\n0 1\n");
    delete testMove;
    board.occupancy[0][0] = 0;
};

TEST(MoveTest, BKingAtMiddleI)
{
    //black king at middle of board
    King boardKing(2, 4, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKing.acceptMove(testMove);

    EXPECT_EQ(test, "3 5\n1 5\n3 4\n1 4\n2 5\n");
    delete testMove;
    board.occupancy[2][4] = -1;
};


TEST(MoveTest, WKingAtOneFromEnd)
{
    //white king one away from end
    King boardKing(3, 5, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKing.acceptMove(testMove);
    EXPECT_EQ(test, "3 4\n");
    delete testMove;
    board.occupancy[3][5] = -1;
};


TEST(MoveTest, WKingAtLeft)
{
    //white king one away from end
    King boardKing(0, 3, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKing.acceptMove(testMove);
    EXPECT_EQ(test, "1 2\n1 3\n0 2\n");
    delete testMove;
    board.occupancy[0][3] = -1;
};

#endif