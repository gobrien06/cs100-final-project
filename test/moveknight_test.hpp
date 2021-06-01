#ifndef __MOVEKNIGHT_TEST_HPP__
#define __MOVEKNIGHT_TEST_HPP__

#include "gtest/gtest.h"

#include "../source/MoveVisitor.h"
#include "../source/Piece.h"
#include "../source/Board.h"

#include "test_global.h"

TEST(MoveTest, BKnightAtIEnd)
{
    //black knight at end of board
    Knight boardKnight(0, 0, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKnight.acceptMove(testMove);

    EXPECT_EQ(test, "1 2\n2 1\n");
    delete testMove;
    board.occupancy[0][0] = 0;
};

TEST(MoveTest, BKnightAtIMid)
{
    //black knight at middle of board
    Knight boardKnight(4, 4, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKnight.acceptMove(testMove);

    EXPECT_EQ(test, "6 5\n6 3\n3 2\n2 3\n5 2\n2 5\n");
    delete testMove;
    board.occupancy[4][4] = -1;
};

TEST(MoveTest, BKnightAtInit)
{
    //black knight at proper init position
    Knight boardKnight(1, 7, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKnight.acceptMove(testMove);

    EXPECT_EQ(test, "0 5\n2 5\n");
    delete testMove;
    board.occupancy[7][1] = 0;
};

TEST(MoveTest, WKnightAtInit)
{
    //white knight at proper init position
    Knight boardKnight(1, 0, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKnight.acceptMove(testMove);

    EXPECT_EQ(test, "2 2\n0 2\n");
    delete testMove;
    board.occupancy[1][0] = 0;
};

TEST(MoveTest, WKnightAtMid)
{
    //white knight at mid
    Knight boardKnight(4, 4, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardKnight.acceptMove(testMove);

    EXPECT_EQ(test, "5 6\n6 5\n3 6\n6 3\n3 2\n2 3\n5 2\n2 5\n");
    delete testMove;
    board.occupancy[4][4] = -1;
};

#endif