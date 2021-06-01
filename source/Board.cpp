#include "Board.h"
#include "Piece.h"
#include "MoveVisitor.h"
Board::Board(int w, int h, int s) : width(w), height(h)
{
    //create squares and
    //set squares to alternating Black and White
    for (int i = 0; i < squares; i++)
    {
        for (int j = 0; j < squares; j++)
        {
            index = i * squares + j;
            sqrs[index] = new sf::RectangleShape(sf::Vector2f(sqrsize, sqrsize));
            sqrs[index]->setPosition(sf::Vector2f(sqrsize * i, sqrsize * j));
            occupancy[i][j] = -1;
        }
    }

    //add classic board layout
    for (int i = 0; i < 8; i++)
    {
        //pawns
        pieces.push_back(new Pawn(i, 1, 0));
        pieces.push_back(new Pawn(i, 6, 1));
    }

    //Rooks
    pieces.push_back(new Rook(0, 0, 0));
    pieces.push_back(new Rook(7, 0, 0));
    pieces.push_back(new Rook(0, 7, 1));
    pieces.push_back(new Rook(7, 7, 1));

    //Knights
    pieces.push_back(new Knight(1, 0, 0));
    pieces.push_back(new Knight(6, 0, 0));
    pieces.push_back(new Knight(1, 7, 1));
    pieces.push_back(new Knight(6, 7, 1));

    //Bishops
    pieces.push_back(new Bishop(2, 0, 0));
    pieces.push_back(new Bishop(5, 0, 0));
    pieces.push_back(new Bishop(2, 7, 1));
    pieces.push_back(new Bishop(5, 7, 1));

    //Kings
    pieces.push_back(new King(3, 0, 0));
    pieces.push_back(new King(3, 7, 1));

    //Queens
    pieces.push_back(new Queen(4, 0, 0));
    pieces.push_back(new Queen(4, 7, 1));

    //make highlight square
    hSquare = new sf::RectangleShape(sf::Vector2f(sqrsize, sqrsize));
    hSquare->setPosition(sf::Vector2f(0, 0));
    hSquare->setFillColor(sf::Color(0, 0, 0, 100));
    botTable = new sf::RectangleShape(sf::Vector2f(sqrsize*8, sqrsize*2));
    botTable->setPosition(sf::Vector2f(0,width));
    botTable->setFillColor(sf::Color(110, 83, 55));
    //make visitor
    mvisit = new MoveVisitor();
};

Board::~Board()
{
    for (int i = 0; i < BOARDSIZE; i++)
    {
        delete sqrs[i];
    }
    for (int i = 0; i < pieces.size(); i++)
    {
        delete pieces.at(i);
    }
    //delete[] sqrs;
};

void Board::show(sf::Vector2i mousePos, sf::RenderWindow &w)
{

    //sets squares back to original color
    for (int i = 0; i < squares; i++)
    {
        for (int j = 0; j < squares; j++)
        {
            index = i * squares + j;
            if ((i + j) % 2 == 0)
            {
                sqrs[index]->setFillColor(sf::Color::White);
            }
            else
            {
                sqrs[index]->setFillColor(sf::Color(40, 40, 40));
            }
        }
    }

    //highlights available piece
    if (selPiece != nullptr)
    {
        //highlight piece
        index = (selPiece->x) * squares + (selPiece->y);
        sqrs[index]->setFillColor(sf::Color(200, 50, 50));

        //highlight possible moves
        selPiece->moves.clear();
        selPiece->acceptMove(mvisit);

        auto cMoves = selPiece->moves;
        for (auto i : cMoves)
        {
            int index = (std::get<0>(i)) * squares + (std::get<1>(i));
            sqrs[index]->setFillColor(sf::Color(200, 50, 50));
        }
    }

    //darkens square on mouseover
    if (mousePos.x > 0 && mousePos.x < width && mousePos.y > 0 && mousePos.y < height)
    {
        int sx = (mousePos.x / sqrsize);
        int sy = (mousePos.y / sqrsize);

        hSquare->setPosition(sf::Vector2f(sqrsize * sx, sqrsize * sy));
    }

    //draws all squares
    for (int i = 0; i < BOARDSIZE; i++)
    {
        w.draw(*sqrs[i]);
    }
    w.draw(*hSquare);
    w.draw(*botTable);

    //draws all pieces
    for (int i = 0; i < pieces.size(); i++)
    {
        pieces.at(i)->show(w, sqrsize);
    }
};

void Board::selectPiece(sf::Vector2i mousePos)
{
    if (mousePos.x > 0 && mousePos.x < width && mousePos.y > 0 && mousePos.y < height)
    {
        int sx = (mousePos.x / sqrsize);
        int sy = (mousePos.y / sqrsize);

        if (selPiece == nullptr)
        {
            for (int i = 0; i < pieces.size(); i++)
            {
                if (sx == pieces.at(i)->x && sy == pieces.at(i)->y && pieces.at(i)->team == move % 2)
                {
                    selPiece = pieces.at(i);
                    return;
                }
            }
        }
        else
        {
            if (selPiece->movePiece(sx, sy))
            {
                selPiece->moveCount++;
                move++;
            }
            selPiece = nullptr;
        }
    }
};

void Board::removePiece(int x_, int y_)
{
    int sx = x_;
    int sy = y_;
    for(int i = 0; i < pieces.size(); i++){
        if(sx == pieces.at(i)->x && sy == pieces.at(i)->y){
            pieces.at(i)->dead = 1;
            pieces.at(i)->spr->setScale(sf::Vector2f(0.5,0.5));
            if(pieces.at(i)->team == 0){
                pieces.at(i)->x = capwhite; pieces.at(i)->y = 16;
                capwhite++;
            }else{
                pieces.at(i)->x = capblack; pieces.at(i)->y = 17;
                capblack++;
            }
            return;
        }
    }
};