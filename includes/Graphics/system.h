/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: array_functions.h
 *  templated low level functions to manipulate 1D arrays 
 *  search - copy - re/allocate - print
 * ************************************************************************* */

#ifndef AOTS_SYSTEM_H
#define AOTS_SYSTEM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.h"
#include "../plotter/plot.h"
#include "../plotter/translator.h"

class System
{
public:
    System();
    void Step(int command);
    void set_graph_info(Graph_info * Info);
    int Size();
    void Draw_axis(sf::RenderWindow& window);
    void Draw_curve(sf::RenderWindow& window, int j);
    void grid_lines(Graph_info info);
    void set_axis_label();

private:
   // Plot P;
    sf::CircleShape shape;
    sf::Vector2f vel;
    Graph_info * info;

};

#endif

