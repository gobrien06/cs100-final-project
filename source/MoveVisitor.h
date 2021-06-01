#ifndef __MOVEVISITOR_HPP__
#define __MOVEVISITOR_HPP__

#include "Visitor.h"
#include "Piece.h"
#include "global.h"
#include <utility>

//Derived from Visitor
class MoveVisitor : public Visitor
{
public:
    MoveVisitor(){};
    std::vector<std::tuple<int, int> > visitPawn(Pawn *currentPawn);
    std::vector<std::tuple<int, int> > visitRook(Rook *currentRook);
    std::vector<std::tuple<int, int> > visitKnight(Knight *currentKnight);
    std::vector<std::tuple<int, int> > visitBishop(Bishop *currentBishop);
    std::vector<std::tuple<int, int> > visitQueen(Queen *currentQueen);
    std::vector<std::tuple<int, int> > visitKing(King *currentKing);
    void checkSimpleMoves(Piece *current, std::vector<std::pair<int, int> > directions);
    int defineForward(int team, int place) { return team == 0 ? place + 1 : place - 1; };
};

#endif