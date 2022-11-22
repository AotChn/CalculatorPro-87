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
    Plot();
    Plot(Graph_info info);
    sf::Vector2f operator()();

    void create_plot_map();

    //Mutators
    void set_info(Graph_info info); 
    void set_point(double x, double y);
    void set_point(pair<double,double> pt);

    //Acessors 
    Graph_info get_info(){return g_info;}
    sf::Vector2f get_SFpoint(){return sf_point;}
    pair<double,double> get_point(){return point;}
    Vector<pair<double,double>> get_coords(){return coordinates;}

   // vector<sf::Vector2f(double,double)> get_plot_map(){return plot_map;}

private:
    double x;
    double y;
    Graph_info g_info; 
    sf::Vector2f sf_point;
    pair<double,double> point;
    Vector<pair<double,double>> coordinates;

};

#endif
