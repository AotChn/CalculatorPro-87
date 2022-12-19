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
#include <fstream>
#include <iostream>
#include <string>

#include "system.h"
#include "sidebar.h"
#include "constants.h"
#include "interface.cpp"
#include "../vector/vector_class.h"
#include "../array_functions/array_functions.h"

class Animate{

    public:

    Animate();
    
    //processes what to put on screen
    void run();
    void Draw();
    void render();
    void update();
    void process_events();

    //history
    void load_graphs();
    void save_graphs();


    sf::RectangleShape input_box(); 
    void load_help_screen();
    sf::Text name_stamp();
    sf::Text input_text(std::string input);

    private:

    sf::RenderWindow window;
    sf::Vector2f mouse_pos;
    sf::Font font;

    //handles user interactions (non text-inputs)
    Interface gui;
    Sidebar sidebar;
    int highlight_pos;
    int button_color;
    bool Mousein;

    //handles graph creation
    System system;
    Graph_info graph;
    Graph_info* info;
    
    //handles user text-inputs
    std::string input;
    bool take_input;

    //handles help screen
    sf::Sprite sprite;
    sf::Texture texture;
    int help;
    bool help_on;

    //handles graph to be shown
    bool show_graphs[7];
    std::string graphs[7];

};

//clear -> draw -> display cycle  is the way to draw stuff
//no other good way to do it 


#endif 

