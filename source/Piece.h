#ifndef PIECE_H
#define PIECE_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <tuple>
#include <string>

class MoveVisitor;

//Piece Base Class
class Piece
{
public:
    //Team - 0  white, team - 1  black
    int x, y, team, dead = 0;
    int dist;
    std::vector<std::tuple<int, int>> moves;
    int numMoves;
    sf::Texture *tex;
    sf::Sprite *spr;
    std::string type;
    int moveCount = 0;
    
    Piece(int x_, int y_, int team_);
    ~Piece();

    void show(sf::RenderWindow &w, int sqrsize);

    virtual std::string acceptMove(MoveVisitor *move) = 0;

    bool movePiece(int x_, int y_);
};

//King Class
class King : public Piece
{

public:
    King(int x_, int y_, int team_);

    std::string acceptMove(MoveVisitor *move);
};

class Queen : public Piece
{

public:
    Queen(int x_, int y_, int team_);

    std::string acceptMove(MoveVisitor *move);
};

class Rook : public Piece
{

public:
    Rook(int x_, int y_, int team_);

    std::string acceptMove(MoveVisitor *move);
};

class Bishop : public Piece
{

public:
    Bishop(int x_, int y_, int team_);

    std::string acceptMove(MoveVisitor *move);
};

class Knight : public Piece
{

public:
    Knight(int x_, int y_, int team_);

    std::string acceptMove(MoveVisitor *move);
};

class Pawn : public Piece
{
public:
    Pawn(int x_, int y_, int team_);

    //Accept Visitor
    std::string acceptMove(MoveVisitor *move);
    void promote();
};

#endif //PIECE_H