/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: array_functions.h
 *  templated low level functions to manipulate 1D arrays 
 *  search - copy - re/allocate - print
 * ************************************************************************* */

#ifndef AOTS_WINDOW_H
#define AOTS_WINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>




class window{

    public:
    window(){}

    void show(){
        sf::RenderWindow screen;
        screen.create(sf::VideoMode(1400,800),"Cool window");
        //we should see nothing program immediately closes with just this ^^
        // lets make it do something cool 

        while(screen.isOpen()){ //app stays open as long as not closed
            sf::Event event;
            while(screen.pollEvent(event)){
                
                if(event.type == sf::Event::Closed)
                    screen.close();
            }
        

        screen.clear();
        sf::CircleShape a(1.f);
        a.setFillColor(sf::Color::Red);
        a.setPosition(sf::Vector2f(700, 400));
        screen.draw(a);
      //  screen.draw(sf::CircleShape(500));
        screen.display();
        }
    }

};

//clear -> draw -> display cycle  is the way to draw stuff
//no other good way to do it 


#endif