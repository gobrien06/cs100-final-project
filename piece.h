#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <iostream>

//Piece Base Class
class Piece{
    public:
        int x,y,team;
        int numMoves;
        int dist;
        int moves[100];

        sf::Texture *tex;
        sf::Sprite *spr;

        Piece(int x_, int y_, int team_): x(x_), y(y_), team(team_){};

        void show(sf::RenderWindow &w, int sqrsize){
            spr->setPosition(x*sqrsize,y*sqrsize);
            w.draw(*spr);
        }

        bool movePiece(int x_, int y_){
            for(int i = 0; i < numMoves; i+=2){
                //check if move is in list of moves
                if(x_ == moves[i] && y_ == moves[i+1]){
                    x = x_; y = y_;
                    //if it is, move and return true
                    return true;
                }
            }
            //if not, return false
            return false;
        };
        
        virtual void getMoves() = 0;

};

//King Class
class King: public Piece{

    public:
        King(int x_, int y_, int team_): Piece(x_, y_, team_){
            //add texture and sprite
            tex = new sf::Texture();
            if(team == 0){
                if (!tex->loadFromFile("textures/wking.png"))
                    std::cout << "failed to load texture" << std::endl;
            }else{
                if (!tex->loadFromFile("textures/bking.png"))
                    std::cout << "failed to load texture" << std::endl;
            }
            
            spr = new sf::Sprite(*tex);
        }
        
        virtual void getMoves(){
            numMoves = 0;
        }

};

class Queen: public Piece{

    public:
        Queen(int x_, int y_, int team_): Piece(x_, y_, team_){
            //add texture and sprite
            tex = new sf::Texture();
            if(team == 0){
                if (!tex->loadFromFile("textures/wqueen.png"))
                    std::cout << "failed to load texture" << std::endl;
            }else{
                if (!tex->loadFromFile("textures/bqueen.png"))
                    std::cout << "failed to load texture" << std::endl;
            }
            
            spr = new sf::Sprite(*tex);
        }
        
        virtual void getMoves(){
            numMoves = 0;
        }

};

class Rook: public Piece{

    public:
       Rook(int x_, int y_, int team_): Piece(x_, y_, team_){
            //add texture and sprite
            tex = new sf::Texture();
            if(team == 0){
                if (!tex->loadFromFile("textures/wrook.png"))
                    std::cout << "failed to load texture" << std::endl;
            }else{
                if (!tex->loadFromFile("textures/brook.png"))
                    std::cout << "failed to load texture" << std::endl;
            }
            
            spr = new sf::Sprite(*tex);
        }
        
        virtual void getMoves(){
            numMoves = 0;
        }

};

class Bishop: public Piece{

    public:
       Bishop(int x_, int y_, int team_): Piece(x_, y_, team_){
            //add texture and sprite
            tex = new sf::Texture();
            if(team == 0){
                if (!tex->loadFromFile("textures/wbishop.png"))
                    std::cout << "failed to load texture" << std::endl;
            }else{
                if (!tex->loadFromFile("textures/bbishop.png"))
                    std::cout << "failed to load texture" << std::endl;
            }
            
            spr = new sf::Sprite(*tex);
        }
        
        virtual void getMoves(){
            numMoves = 0;
        }

};

class Knight: public Piece{

    public:
       Knight(int x_, int y_, int team_): Piece(x_, y_, team_){
            //add texture and sprite
            tex = new sf::Texture();
            if(team == 0){
                if (!tex->loadFromFile("textures/wknight.png"))
                    std::cout << "failed to load texture" << std::endl;
            }else{
                if (!tex->loadFromFile("textures/bknight.png"))
                    std::cout << "failed to load texture" << std::endl;
            }
            
            spr = new sf::Sprite(*tex);
        }
        
        virtual void getMoves(){
            numMoves = 0;
        }

};

class Pawn: public Piece{

    public:
       Pawn(int x_, int y_, int team_): Piece(x_, y_, team_){
            //add texture and sprite
            tex = new sf::Texture();
            if(team == 0){
                if (!tex->loadFromFile("textures/wpawn.png"))
                    std::cout << "failed to load texture" << std::endl;
            }else{
                if (!tex->loadFromFile("textures/bpawn.png"))
                    std::cout << "failed to load texture" << std::endl;
            }
            
            spr = new sf::Sprite(*tex);
        }
        
        virtual void getMoves(){
            numMoves = 0;
        }

};
#endif //PIECE_H

