#ifndef __MOVEROOK_TEST_HPP__
#define __MOVEROOK_TEST_HPP__

#include "gtest/gtest.h"

#include "test_global.h"

#include "../source/MoveVisitor.h"
#include "../source/Piece.h"
#include "../source/Board.h"

TEST(MoveTest, BRookAtIEnd)
{
    //black rook at end of board
    Rook boardRook(0, 0, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardRook.acceptMove(testMove);

    EXPECT_EQ(test, "1 0\n0 1\n");
    delete testMove;
    board.occupancy[0][0] = 0;
};

TEST(MoveTest, BRookAtIMid)
{
    Rook boardRook(4, 2, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardRook.acceptMove(testMove);

    EXPECT_EQ(test, "5 2\n6 2\n7 2\n3 2\n2 2\n1 2\n0 2\n4 1\n4 3\n4 4\n4 5\n");
    delete testMove;
    board.occupancy[4][2] = -1;
};

TEST(MoveTest, BRookAtIStart)
{
    //black rook at start of board
    Rook boardRook(0, 7, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardRook.acceptMove(testMove);

    EXPECT_EQ(test, "");
    delete testMove;
    board.occupancy[0][7] = 1;
};

TEST(MoveTest, WRookAtIEnd)
{
    //white rook at end of board
    Rook boardRook(0, 7, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardRook.acceptMove(testMove);

    EXPECT_EQ(test, "1 7\n0 6\n");
    delete testMove;
    board.occupancy[0][7] = 1;
};

TEST(MoveTest, WRookAtIMid)
{
    Rook boardRook(4, 2, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardRook.acceptMove(testMove);

    EXPECT_EQ(test, "5 2\n6 2\n7 2\n3 2\n2 2\n1 2\n0 2\n4 3\n4 4\n4 5\n4 6\n");
    delete testMove;
    board.occupancy[4][2] = -1;
};

TEST(MoveTest, WRookAtIStart)
{
    //white rook at start of board
    Rook boardRook(0, 0, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardRook.acceptMove(testMove);

    EXPECT_EQ(test, "");
    delete testMove;
};

TEST(MoveTest, WRookAtIOneEnd)
{
    //white rook at one away from end of board
    Rook boardRook(7, 6, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardRook.acceptMove(testMove);

    EXPECT_EQ(test, "6 6\n7 5\n7 4\n7 3\n7 2\n7 7\n");
    delete testMove;
    board.occupancy[7][6] = 1;
};

#endif
