/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: translator.h
 *   Translate cartesian coordinates to sfml coordinates
 *  Or translate sfml to cartesian coords by doing the inverse
 *  will support linear transformations 
 * ************************************************************************* */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

//|______________________STD_LIB____________________|
#include <iostream>
#include <iomanip>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
//|----------------MY LIBRARY FUNCTS----------------|
#include "plot.h"
#include "../data_pkg/graph_info.h"
//|__________________________________________________|


class Translator {

public:
   //CTOR
   Translator(){}
   Translator(Graph_info * Info);
   sf::Vector2f cart_to_sfml(sf::Vector2f coords);
   sf::Vector2f sfml_to_cart(sf::Vector2f coords);
   
   void set_dx();
   void set_delta_x();
   void set_delta_y();
   void set_domain(double min, double max);
   void set_graph_info(Graph_info * Info);

   double get_SDI(); //screen domain interval
   double get_dx(){return dx;} //split screen evenly (x-axis) by domain
   double get_dy(){return dy;} ////split screen evenly (y-axis) by domain

   void print();

private:
   Graph_info* info;
   sf::Vector2f sfml_point;
   double dx;
   double dy;
   double offset;

};

#endif