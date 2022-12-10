/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: array_functions.h
 *  templated low level functions to manipulate 1D arrays 
 *  search - copy - re/allocate - print
 * ************************************************************************* */

#ifndef AOTS_ANIMATE_H
#define AOTS_ANIMATE_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include <string>
#include "constants.h"
#include "../vector/vector_class.h"
#include "interface.cpp"
// #include "sidebar.h"

class Animate{

    public:

    Animate() : sidebar(WORK_PANEL, SIDE_BAR)
    {
        window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"CALCULATOR ULTRA-47");
        window.setFramerateLimit(60);
        bool take_input = false;

    
    }
    
    void run();
    void Draw();
    void render();
    void update();
    void process_events();
    void create_new_graph();
    sf::RectangleShape input_box();

    private:
    Interface gui;
    System system;
    Sidebar sidebar;
    sf::RenderWindow window;
    sf::Text text;
    sf::Font font;
    std::string input;
    Graph_info* info;
    Graph_info graph;
    bool take_input;
    int i;
    int j;
   // Vector<std::string> history;
    
};
//clear -> draw -> display cycle  is the way to draw stuff
//no other good way to do it 


#endif 
