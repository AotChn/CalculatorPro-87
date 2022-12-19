/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: sidebar.h
 *  main interface of application 
 *  handles text on those interfaces
 * ************************************************************************* */

#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "constants.h"
#include "../plotter/translator.h"
#include "../data_pkg/graph_info.h"

using namespace std;
class Sidebar{

public:
    Sidebar();
    Sidebar(float left, float width);

    void draw(sf::RenderWindow& window);

    void history_buttons();
    sf::RectangleShape create_button(int i,int j);
    sf::Text show_equation(std::string eq, int j,bool on, int state);
    void set_bottom_Bar_info(Graph_info* info,sf::RenderWindow& window,bool Mousein, std::string input);

private:

    //interfaces 
    sf::RectangleShape rect;   
    sf::RectangleShape bottomBar;

    //text handling
    sf::Font font;              
    sf::Text sb_text;  
    sf::Text current_eq;
    sf::Text current_coord;             
    
    //sb demensions
    float _left;
    float _width;
};

#endif // SIDEBAR_H
