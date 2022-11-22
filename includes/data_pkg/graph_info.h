#ifndef AOTS_GRAPH_INFO
#define AOTS_GRAPH_INFO

//|______________________STD_LIB____________________|
#include <SFML/Graphics.hpp>
#include <string>
//|----------------MY LIBRARY FUNCTS----------------|
#include "../tokenizer/tokenizer.h"
#include "../shunting_yard/shunting_yard.h"
#include "../queue/MyQueue.h"
#include "../token/token.h"
//|__________________________________________________|

struct Graph_info{
    //CTOR
    Graph_info(){}
    Graph_info(std::string str); //creates postfix queue from str
    Graph_info(std::string str, Queue<Token*> postfix); 

    //Mutators
    void set_window (double x, double y);
    void set_origin (double x, double y);
    void set_scale  (double x, double y);
    void set_domain (double x, double y);
    void set_angle  (double x, double y);

    void set_window (pair<double,double> a);
    void set_origin (pair<double,double> a);
    void set_scale  (pair<double,double> a);
    void set_domain (pair<double,double> a);
    void set_angle  (pair<double,double> a);

    //Equation
    std::string Eq;
    Queue<Token*> post_fix;

    //Interface
    sf::Vector2f window_size;
    sf::Vector2f origin;
    sf::Vector2f scale;
    sf::Vector2f domain;
    sf::Vector2f angle;

    //resolution 
    int total_pts;
};

#endif 