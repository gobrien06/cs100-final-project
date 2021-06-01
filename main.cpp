#include <SFML/Graphics.hpp>
#include <iostream>
#include "./source/Board.h"

int width = 680;
int height = 780;
Board board(width, width, 8);

int main() { 

    bool mousedown = false;
    //Window Creation
    sf::RenderWindow window(sf::VideoMode(width, height), "Chess");

    //Mouse Position
    sf::Vector2i mousePos;

    //Main Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {

                window.close();
            }
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                mousedown  = !mousedown;
                if(mousedown){
                    std::cout << "the right button was pressed" << std::endl;
                    board.selectPiece(mousePos);
                }
                
            }
        }

        mousePos = sf::Mouse::getPosition(window);

        //drawing
        window.clear();

        board.show(mousePos, window);
        window.display();
    }

    return 0;
}