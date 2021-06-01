#include "Piece.h"
#include "global.h"
#include "MoveVisitor.h"

Piece::Piece(int x_, int y_, int team_) : x(x_), y(y_), team(team_)
{
    board.occupancy[x][y] = team;
};

Piece::~Piece()
{
    //board.occupancy[x][y] = -1;
}

void Piece::show(sf::RenderWindow &w, int sqrsize)
{
    if(dead){
        spr->setPosition(((float)x)/2 * sqrsize, ((float)y)/2 * sqrsize);
    }else{
        spr->setPosition(x * sqrsize, y * sqrsize);
    }
    w.draw(*spr);
}

std::string Piece::acceptMove(MoveVisitor *move){};

bool Piece::movePiece(int x_, int y_)
{
    for (auto i : moves)
    {
        if (std::get<0>(i) == x_ && std::get<1>(i) == y_)
        {

            board.removePiece(x_, y_);

            board.occupancy[x][y] = -1;
            board.occupancy[x_][y_] = team;

            x = std::get<0>(i);
            y = std::get<1>(i);

            return true;
        }
    }
    return false;
}

King::King(int x_, int y_, int team_) : Piece(x_, y_, team_)
{
    //add texture and sprite
    tex = new sf::Texture();
    if (team == 0)
    {
        if (!tex->loadFromFile("textures/wking.png"))
            std::cout << "failed to load texture" << std::endl;
    }
    else
    {
        if (!tex->loadFromFile("textures/bking.png"))
            std::cout << "failed to load texture" << std::endl;
    }

    spr = new sf::Sprite(*tex);
}

//Accept Visitor
std::string King::acceptMove(MoveVisitor *move)
{
    type = "King";
    
    std::string total;
    moves = move->visitKing(this);
    for (auto i = moves.begin(); i != moves.end(); ++i)
    {
        total += std::to_string(std::get<0>(*i)) + " " + std::to_string(std::get<1>(*i)) + "\n";
    };
    return total;
};


Queen::Queen(int x_, int y_, int team_) : Piece(x_, y_, team_)
{
    //add texture and sprite
    tex = new sf::Texture();
    if (team == 0)
    {
        if (!tex->loadFromFile("textures/wqueen.png"))
            std::cout << "failed to load texture" << std::endl;
    }
    else
    {
        if (!tex->loadFromFile("textures/bqueen.png"))
            std::cout << "failed to load texture" << std::endl;
    }

    spr = new sf::Sprite(*tex);
};

//Accept Visitor
std::string Queen::acceptMove(MoveVisitor *move)
{
    std::string total;
    moves.clear();
    moves = move->visitQueen(this);
    for (auto i = moves.begin(); i != moves.end(); ++i)
    {
        total += std::to_string(std::get<0>(*i)) + " " + std::to_string(std::get<1>(*i)) + "\n";
    };
    return total;
};

Rook::Rook(int x_, int y_, int team_) : Piece(x_, y_, team_)
{
    //add texture and sprite
    tex = new sf::Texture();
    if (team == 0)
    {
        if (!tex->loadFromFile("textures/wrook.png"))
            std::cout << "failed to load texture" << std::endl;
    }
    else
    {
        if (!tex->loadFromFile("textures/brook.png"))
            std::cout << "failed to load texture" << std::endl;
    }

    spr = new sf::Sprite(*tex);
};

//Accept Visitor
std::string Rook::acceptMove(MoveVisitor *move)
{
    std::string total;
    moves.clear();
    moves = move->visitRook(this);
    for (auto i = moves.begin(); i != moves.end(); ++i)
    {
        total += std::to_string(std::get<0>(*i)) + " " + std::to_string(std::get<1>(*i)) + "\n";
    };
    return total;
};

Bishop::Bishop(int x_, int y_, int team_) : Piece(x_, y_, team_)
{
    //add texture and sprite
    tex = new sf::Texture();
    if (team == 0)
    {
        if (!tex->loadFromFile("textures/wbishop.png"))
            std::cout << "failed to load texture" << std::endl;
    }
    else
    {
        if (!tex->loadFromFile("textures/bbishop.png"))
            std::cout << "failed to load texture" << std::endl;
    }

    spr = new sf::Sprite(*tex);
};

//Accept Visitor
std::string Bishop::acceptMove(MoveVisitor *move)
{
    std::string total;
    moves.clear();
    moves = move->visitBishop(this);
    for (auto i = moves.begin(); i != moves.end(); ++i)
    {
        total += std::to_string(std::get<0>(*i)) + " " + std::to_string(std::get<1>(*i)) + "\n";
    };
    return total;
};

Knight::Knight(int x_, int y_, int team_) : Piece(x_, y_, team_)
{
    //add texture and sprite
    tex = new sf::Texture();
    if (team == 0)
    {
        if (!tex->loadFromFile("textures/wknight.png"))
            std::cout << "failed to load texture" << std::endl;
    }
    else
    {
        if (!tex->loadFromFile("textures/bknight.png"))
            std::cout << "failed to load texture" << std::endl;
    }

    spr = new sf::Sprite(*tex);
};

//Accept Visitor
std::string Knight::acceptMove(MoveVisitor *move)
{
    std::string total;
    moves.clear();
    moves = move->visitKnight(this);
    for (auto i = moves.begin(); i != moves.end(); ++i)
    {
        total += std::to_string(std::get<0>(*i)) + " " + std::to_string(std::get<1>(*i)) + "\n";
    };
    return total;
};

Pawn::Pawn(int x_, int y_, int team_) : Piece(x_, y_, team_)
{
    type = "Pawn";

    //add texture and sprite
    tex = new sf::Texture();
    if (team == 0)
    {
        if (!tex->loadFromFile("textures/wpawn.png"))
            std::cout << "failed to load texture" << std::endl;
    }
    else
    {
        if (!tex->loadFromFile("textures/bpawn.png"))
            std::cout << "failed to load texture" << std::endl;
    }

    spr = new sf::Sprite(*tex);
};

//Accept Visitor
std::string Pawn::acceptMove(MoveVisitor *move)
{
    std::string total;
    moves = move->visitPawn(this);
    for (auto i = moves.begin(); i != moves.end(); ++i)
    {
        total += std::to_string(std::get<0>(*i)) + " " + std::to_string(std::get<1>(*i)) + "\n";
    };
    return total;
};

void Pawn::promote(){
    //do something
};