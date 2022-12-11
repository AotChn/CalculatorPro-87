/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: animate.h
 *  manipulate window actions in sfml
 *  on screen content
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
#include <fstream>
#include <iostream>
#include "../array_functions/array_functions.h"
// #include "sidebar.h"

class Animate{

    public:

    Animate() : sidebar(WORK_PANEL, SIDE_BAR)
    {
        window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"CALCULATOR ULTRA-47");
        window.setFramerateLimit(60);
        bool take_input = false;
        info = &graph;
        system.set_graph_info(info);
        button_color = 0;
        j = 2;
    }
    
    void run();
    void Draw();
    void render();
    void update();
    void process_events();
    void create_graphs();
    void load_graphs();
    void save_graphs();
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
    int button_color;
    int j;
    bool Mousein;
    sf::Vector2f mouse_pos;
    std::string graphs[7];
    bool show_graphs[7];
    
};
//clear -> draw -> display cycle  is the way to draw stuff
//no other good way to do it 


#endif 

