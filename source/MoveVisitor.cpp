#include "MoveVisitor.h"
#include <algorithm>

std::vector<std::tuple<int, int> > MoveVisitor::visitPawn(Pawn *currentPawn)
{
    movements.clear();
    auto checkCapture = [](int team, int x, int y)
    {
        if (x > board.squares - 1 || x < 0)
            return false;
        if (y > board.squares - 1 || y < 0)
            return false;
        if (board.occupancy[x][y] == -1)
            return false;
        return board.occupancy[x][y] != team ? true : false;
    };

    //Determine end of board by team
    int potentialY = defineForward(currentPawn->team, currentPawn->y);

    //Check capture - bring this into a separate visitor
    if (checkCapture(currentPawn->team, currentPawn->x + 1, potentialY))
        movements.push_back(std::make_tuple(currentPawn->x + 1, potentialY));
    if (checkCapture(currentPawn->team, currentPawn->x - 1, potentialY))
        movements.push_back(std::make_tuple(currentPawn->x - 1, potentialY));

    if ((currentPawn->team == 0 && potentialY >= board.squares - 1) || (currentPawn->team == 1 && potentialY <= 0))
        return movements;

    //First move - move 2 squares if not blocked
    if (currentPawn->moveCount == 0)
    {
        int temp = currentPawn->y;
        for (int i = 1; i <= 2; i++)
        {
            temp = defineForward(currentPawn->team, temp);
            if (temp >= board.squares - 1 || temp <= 0 || board.occupancy[currentPawn->x][temp] != -1)
                return movements;
            movements.push_back(std::make_tuple(currentPawn->x, temp));
        }

        return movements;
    };

    //Else Move one square
    if (board.occupancy[currentPawn->x][potentialY] == -1)
    {
        movements.push_back(std::make_tuple(currentPawn->x, potentialY));
        potentialY = defineForward(currentPawn->team, potentialY);
    }
    //Implement promotions if movements is the end of the board in Pawn
    return movements;
};

//Could be optimized
std::vector<std::tuple<int, int> > MoveVisitor::visitRook(Rook *currentRook)
{
    movements.clear();
    std::vector<std::pair<int, int> > directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    checkSimpleMoves(currentRook, directions);
    return movements;
};

std::vector<std::tuple<int, int> > MoveVisitor::visitKnight(Knight *currentKnight)
{
    movements.clear();
    int pX, pY;

    std::vector<std::pair<int, int> > directions = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}};

    for (auto i = directions.begin(); i != directions.end(); i++)
    {
        pX = currentKnight->x + i->first;
        pY = currentKnight->y + i->second;
        if (board.occupancy[pX][pY] != currentKnight->team && pY >= 0 && pY <= board.squares - 1 && pX >= 0 && pX <= board.squares - 1)
            movements.push_back(std::make_tuple(pX, pY));
    }

    return movements;
}

std::vector<std::tuple<int, int> > MoveVisitor::visitBishop(Bishop *currentBishop)
{
    movements.clear();
    std::vector<std::pair<int, int> > directions = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

    checkSimpleMoves(currentBishop, directions);

    return movements;
};

std::vector<std::tuple<int, int> > MoveVisitor::visitQueen(Queen *currentQueen)
{
    movements.clear();
    std::vector<std::pair<int, int> > directions = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    checkSimpleMoves(currentQueen, directions);

    return movements;
}

//Moves pieces that can't jump and use simple directions
void MoveVisitor::checkSimpleMoves(Piece *current, std::vector<std::pair<int, int> > directions)
{
    int pX = current->x;
    int pY = current->y;

    for (auto i = directions.begin(); i != directions.end(); i++)
    {
        pX = pX + i->first;
        pY = pY + i->second;

        while ((pX >= 0 && pX <= board.squares - 1) && (pY >= 0 && pY <= board.squares - 1) && (board.occupancy[pX][pY] != current->team))
        {
            movements.push_back(std::make_tuple(pX, pY));
            if (board.occupancy[pX][pY] != -1)
                break;
            pX = pX + i->first;
            pY = pY + i->second;
        }

        pX = current->x;
        pY = current->y;
    }
}

std::vector<std::tuple<int, int> > MoveVisitor::visitKing(King *currentKing)
{
    movements.clear();
    
    std::cout << "visited king\n";
    std::vector<std::pair<int, int> > directions = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int pX = currentKing->x;
    int pY = currentKing->y;

    for (auto i = directions.begin(); i != directions.end(); i++)
    {
        pX = pX + i->first;
        pY = pY + i->second;

        if (pX >= 0 && pX <= board.squares - 1 && pY >= 0 && pY <= board.squares - 1 && board.occupancy[pX][pY] != currentKing->team)
            movements.push_back(std::make_tuple(pX, pY));

        pX = currentKing->x;
        pY = currentKing->y;
    }

    //Check other pieces' movements for checks
    std::vector<std::tuple<int, int> > piecesMoves;

    MoveVisitor *visit = new MoveVisitor();

    for (auto i = board.pieces.begin(); i != board.pieces.end(); i++)
    {
        if ((*i)->team == currentKing->team)
            continue;

        if ((*i)->type == "King")
        {
            int pXK;
            int pYK;
            for (auto z = directions.begin(); z != directions.end(); z++)
            {
                pXK = pXK + z->first;
                pYK = pYK + z->second;

                if (pXK >= 0 && pXK <= board.squares - 1 && pYK >= 0 && pYK <= board.squares - 1 && board.occupancy[pXK][pYK] != currentKing->team)
                    piecesMoves.push_back(std::make_tuple(pXK, pYK));
                pXK = (*i)->x;
                pYK = (*i)->y;
            }
        }
        else
        {
            (*i)->acceptMove(visit);
            for (auto j = (*i)->moves.begin(); j != (*i)->moves.end(); j++)
            {
                piecesMoves.push_back(*j);
            };
        }
    }
    delete visit;
    std::cout << "at the end of king\n";
    movements.erase(std::remove_if(movements.begin(), movements.end(), [piecesMoves](const std::tuple<int, int> &elem)
                                   {
                                       bool contains = find(piecesMoves.begin(), piecesMoves.end(), (elem)) != piecesMoves.end();
                                       return contains;
                                   }),
                    movements.end());

    return movements;
};