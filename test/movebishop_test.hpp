#ifndef __MOVEBISHOP_TEST_HPP__
#define __MOVEBISHOP_TEST_HPP__

#include "gtest/gtest.h"

#include "../source/MoveVisitor.h"
#include "../source/Piece.h"
#include "../source/Board.h"

#include "test_global.h"

TEST(MoveTest, BBishopAtIEnd)
{
    //black bishop at end of board
    Bishop boardBishop(0, 0, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardBishop.acceptMove(testMove);

    EXPECT_EQ(test, "1 1\n");
    delete testMove;
    board.occupancy[0][0] = 0;
};

TEST(MoveTest, WBishopAtIMid)
{
    Bishop boardBishop(4, 4, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardBishop.acceptMove(testMove);

    EXPECT_EQ(test, "5 5\n6 6\n3 5\n2 6\n3 3\n2 2\n5 3\n6 2\n");
    delete testMove;
    board.occupancy[4][4] = -1;
};

TEST(MoveTest, WBishopAtIEnd)
{
    Bishop boardBishop(2, 6, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardBishop.acceptMove(testMove);

    EXPECT_EQ(test, "3 7\n1 7\n1 5\n0 4\n3 5\n4 4\n5 3\n6 2\n");
    delete testMove;
    board.occupancy[2][6] = 1;
};

TEST(MoveTest, WBishopAtILeft)
{
    Bishop boardBishop(0, 5, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardBishop.acceptMove(testMove);

    EXPECT_EQ(test, "1 6\n1 4\n2 3\n3 2\n");
    delete testMove;
    board.occupancy[0][5] = -1;
};

#endif