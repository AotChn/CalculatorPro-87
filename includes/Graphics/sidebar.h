/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: array_functions.h
 *  templated low level functions to manipulate 1D arrays 
 *  search - copy - re/allocate - print
 * ************************************************************************* */

#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "../plotter/translator.h"
#include <iostream>
#include <string>
#include <vector>
#include "../data_pkg/graph_info.h"
using namespace std;


class Sidebar
{
public:
    Sidebar();
    Sidebar(float left, float width);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);
    void set_bottom_Bar_info(Graph_info* info,sf::RenderWindow& window,bool Mousein, std::string input);
    void history_buttons();
    sf::RectangleShape create_button(int i,int j);
    sf::Text show_equation(std::string eq, int j);
private:
    sf::RectangleShape rect;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object
    sf::RectangleShape bottomBar;
    float _left;
    float _width;
    sf::Text current_eq;
    sf::Text current_coord;
};

#endif // SIDEBAR_H
