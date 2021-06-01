#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <tuple>

class Piece;
class Pawn;
class Rook;
class Queen;
class King;
class Bishop;
class Visitor;
class MoveVisitor;

class Board
{

public:
    int width;
    int height;
    static const int squares = 8;
    const int sqrsize = width / squares;
    static const int BOARDSIZE = squares * squares;
    int index;
    int move = 0;
    sf::Shape *sqrs[BOARDSIZE];
    sf::Shape *hSquare;
    sf::Shape *botTable;
    std::vector<Piece *> pieces;
    int capblack = 0; int capwhite = 0;
    MoveVisitor * mvisit;
    Piece* selPiece = nullptr;
    int occupancy[squares][squares];

    Board(int w, int h, int s);
    ~Board();
    
    void show(sf::Vector2i mousePos, sf::RenderWindow &w);
    void selectPiece(sf::Vector2i mousePos);
    void removePiece(int x_, int y_);
};

#endif //BOARD_H