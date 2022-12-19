/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: system.h
 *  Uses plotter.h and translate.h to create cartesian points and translate to sfml 
 *  draws the curves of the graphs and also sets the axis
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
    void set_graph_info(Graph_info * Info);
    void draw_axis(sf::RenderWindow& window);
    void Draw_curve(sf::RenderWindow& window, int j);

private:
   // Plot P;
    sf::CircleShape shape;
    sf::Vector2f vel;
    Graph_info * info;

};

#endif

