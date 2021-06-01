#ifndef __MOVEPAWN_TEST_HPP__
#define __MOVEPAWN_TEST_HPP__

#include "gtest/gtest.h"

#include "../source/MoveVisitor.h"
#include "../source/Piece.h"
#include "../source/Board.h"

#include "test_global.h"

TEST(MoveTest, BPawnAtIEnd)
{
    //black pawn at end of board
    Pawn boardPawn(0, 0, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardPawn.acceptMove(testMove);

    EXPECT_EQ(test, "");
    delete testMove;
    board.occupancy[0][0] = 0;
};

TEST(MoveTest, BPawnAtIMid)
{
    Pawn boardPawn(4, 4, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardPawn.acceptMove(testMove);

    EXPECT_EQ(test, "4 3\n4 2\n");
    delete testMove;
    board.occupancy[4][4] = -1;
};

TEST(MoveTest, BPawnAtIStart)
{
    //black pawn at start of board
    Pawn boardPawn(4, 7, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardPawn.acceptMove(testMove);

    EXPECT_EQ(test, "");
    delete testMove;
    board.occupancy[4][7] = 1;
};

TEST(MoveTest, WPawnAtIEnd)
{
    //white pawn at end of board
    Pawn boardPawn(4, 7, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardPawn.acceptMove(testMove);

    EXPECT_EQ(test, "");
    delete testMove;
    board.occupancy[4][7] = 1;
};

TEST(MoveTest, WPawnAtIOneFromEnd)
{
    //white pawn at start of board
    Pawn boardPawn(4, 6, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardPawn.acceptMove(testMove);

    EXPECT_EQ(test, "5 7\n3 7\n");
    delete testMove;
    board.occupancy[4][6] = 1;
};

TEST(MoveTest, WPawnAtIMid)
{
    //white pawn at middle of board
    Pawn boardPawn(0, 3, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardPawn.acceptMove(testMove);

    EXPECT_EQ(test, "0 4\n0 5\n");
    delete testMove;
    board.occupancy[0][3] = -1;
};

#endif
