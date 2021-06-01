#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include <string>
#include <tuple>

#include "Piece.h"

//Movement is the Visitor interface
class Visitor
{
protected:
    std::vector<std::tuple<int, int>> movements = {};

public:
    //virtual void moveKing(King *);
    virtual std::vector<std::tuple<int, int>> visitRook(Rook *) = 0;
    virtual std::vector<std::tuple<int, int>> visitKnight(Knight *) = 0;
    virtual std::vector<std::tuple<int, int>> visitPawn(Pawn *) = 0;
    virtual std::vector<std::tuple<int, int>> visitBishop(Bishop *) = 0;
    virtual std::vector<std::tuple<int, int>> visitQueen(Queen *) = 0;
};

#endif