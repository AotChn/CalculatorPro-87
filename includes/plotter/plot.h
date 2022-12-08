/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: plot.h
 *  create an array of carteasian coordinates
 *  given graph info --> uses rpn to calculate y
 * ************************************************************************* */

#ifndef PLOT_H
#define PLOT_H

//|______________________STD_LIB____________________|
#include <iostream>
#include <iomanip>
#include <vector>
#include <SFML/Graphics.hpp>
//|----------------MY LIBRARY FUNCTS----------------|
#include "../rpn/rpn.h"
#include "../tokenizer/tokenizer.h"
#include "../data_pkg/graph_info.h"
#include "../shunting_yard/shunting_yard.h"
#include "../vector/vector_class.h"
//|__________________________________________________|


class Plot {

public:
   //CTOR
    Plot();
    Plot(Graph_info * Info);
    sf::Vector2f operator()();

    //Process
    void create_plot_map(); //creates vector of cartesian coords in pair form 

    //Mutators
    void set_info(Graph_info * Info); 
    void set_point(double x, double y); //instantiates pair
    double get_delta();
    double get_s_delta();

    //Acessors 
    void Print();
    Graph_info* get_info(){return info;}
    sf::Vector2f get_SFpoint(){return point;} 
    Vector<sf::Vector2f> get_coords(){return coordinates;}
    sf::Vector2f operator()(int i);
    
    void print2();

private:
   
    double x;
    double y;
    Graph_info* info; 
    sf::Vector2f point;
    Vector<sf::Vector2f> coordinates;
};

#endif

//seg fault 