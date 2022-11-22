#ifndef PLOT_H
#define PLOT_H

//|______________________STD_LIB____________________|
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
//|----------------MY LIBRARY FUNCTS----------------|
#include "includes/rpn/rpn.h"
#include "includes/tokenizer/tokenizer.h"
#include "includes/data_pkg/graph_info.h"
#include "includes/shunting_yard/shunting_yard.h"
//|__________________________________________________|


class Plot {

    public:
        Plot();
        Plot(Graph_info info);
        void set_info(Graph_info info);
        sf::Vector2f operator()();

    private:
        Graph_info data;
        double i;
        double j;
        vector<sf::Vector2f(double,double)> coord;

};

Plot::Plot(){


}
Plot::Plot(Graph_info info){
    data = info;
}

void Plot::set_info(Graph_info info){
    data = info;
}

sf::Vector2f Plot::operator()(){
    

    
}








#endif
