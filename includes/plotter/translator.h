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
   sf::Vector2f cart_to_sfml(Vector<sf::Vector2f> coordinates, int i);
   
   void set_graph_info(Graph_info * Info);
   void set_start();
   void set_dx();
   void set_delta_x();
   void set_delta_y();
   void set_domain(double min, double max);

   double get_R_offset();
   double get_L_offset();
   double get_SDI(); //screen domain interval
   double get_dx(){return dx;}
   double get_dy(){return dy;}

   void print();

private:
   Graph_info* info;
   sf::Vector2f sfml_point;
   double dx;
   double dy;
   double offset;

};

#endif