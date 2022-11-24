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
    Plot(Graph_info info);
    sf::Vector2f operator()();

    //Process
    void create_plot_map(); //creates vector of cartesian coords in pair form 

    //Mutators
    void set_info(Graph_info info); 
    void set_point(double x, double y); //instantiates pair

    //Acessors 
    void Print();
    Graph_info get_info(){return g_info;}
    sf::Vector2f get_SFpoint(){return point;} 
    Vector<sf::Vector2f> get_coords(){return coordinates;}
    sf::Vector2f operator()(int i);

private:
   
    double x;
    double y;
    Graph_info g_info; 
    sf::Vector2f point;
    Vector<sf::Vector2f> coordinates;
};

#endif
