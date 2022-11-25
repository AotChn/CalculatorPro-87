/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: translator.h
 *   Translate cartesian coordinates to sfml coordinates
 *  will support linear transformations 
 * ************************************************************************* */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

//|______________________STD_LIB____________________|
#include <iostream>
#include <iomanip>
#include <vector>
#include <SFML/Graphics.hpp>
//|----------------MY LIBRARY FUNCTS----------------|
#include "plot.h"
#include "../data_pkg/graph_info.h"
//|__________________________________________________|


class Translator {

public:
   //CTOR
    Translator(){}
    Translator(Graph_info Info);
    sf::Vector2f cart_to_sfml(sf::Vector2f cart_coords);

private:
   Graph_info info;
   sf::Vector2f sfml_point;

};

#endif