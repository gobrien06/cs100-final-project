#include "gtest/gtest.h"

#include "../source/Board.h"

#include "movepawn_test.hpp"
#include "moverook_test.hpp"
#include "moveknight_test.hpp"
#include "movebishop_test.hpp"
#include "movequeen_test.hpp"
#include "moveking_test.hpp"

int width = 680;
int height = 680;
Board board(width, height, 8);

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}