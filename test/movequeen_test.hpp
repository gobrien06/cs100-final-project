#ifndef __MOVEQUEEN_TEST_HPP__
#define __MOVEQUEEN_TEST_HPP__

#include "gtest/gtest.h"

#include "../source/MoveVisitor.h"
#include "../source/Piece.h"
#include "../source/Board.h"

#include "test_global.h"

TEST(MoveTest, BQueenAtIEnd)
{
    //black bishop at end of board
    Queen boardQueen(0, 0, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardQueen.acceptMove(testMove);

    EXPECT_EQ(test, "1 1\n1 0\n0 1\n");
    delete testMove;
    board.occupancy[0][0] = 0;
};

TEST(MoveTest, WQueenAtIStart)
{
    Queen boardQueen(0, 0, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardQueen.acceptMove(testMove);

    EXPECT_EQ(test, "");
    delete testMove;
};

TEST(MoveTest, BQueenAtIMid)
{
    Queen boardQueen(4, 3, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardQueen.acceptMove(testMove);

    EXPECT_EQ(test, "5 4\n6 5\n3 4\n2 5\n3 2\n2 1\n5 2\n6 1\n5 3\n6 3\n7 3\n3 3\n2 3\n1 3\n0 3\n4 4\n4 5\n4 2\n4 1\n");
    delete testMove;
    board.occupancy[4][3] = -1;
};

TEST(MoveTest, WQueenAtIMid)
{
    Queen boardQueen(4, 3, 0);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardQueen.acceptMove(testMove);

    EXPECT_EQ(test, "5 4\n6 5\n7 6\n3 4\n2 5\n1 6\n3 2\n5 2\n5 3\n6 3\n7 3\n3 3\n2 3\n1 3\n0 3\n4 4\n4 5\n4 6\n4 2\n");
    delete testMove;
    board.occupancy[4][3] = -1;
};

TEST(MoveTest, BQueenAtILeft)
{
    Queen boardQueen(0, 3, 1);
    MoveVisitor *testMove = new MoveVisitor();
    std::string test = boardQueen.acceptMove(testMove);

    EXPECT_EQ(test, "1 4\n2 5\n1 2\n2 1\n1 3\n2 3\n3 3\n4 3\n5 3\n6 3\n7 3\n0 4\n0 5\n0 2\n0 1\n");
    delete testMove;
    board.occupancy[4][3] = -1;
};


#endif