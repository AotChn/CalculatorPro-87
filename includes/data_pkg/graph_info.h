/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: graph_info.h
 *  data wrapper for graphs 
 *  window size, origin, scale, domain, angle
 * ************************************************************************* */

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
    Graph_info();
    Graph_info(std::string str); //creates postfix queue from str
    Graph_info(std::string str, Queue<Token*> postfix); 
    //Mutators
    void set_window (double width, double height);
    void set_origin (double x, double y);
    void set_origin();
    void set_scale  (double x, double y);
    void set_angle  (double x, double y);
    void set_s_domain(double x, double y);
    void set_string(std::string eq);

    void set_eq_domain (double min, double max);
    void set_eq_domain (double min, std::string pos_inf);
    void set_eq_domain (std::string neg_inf, double max);
    void set_eq_domain (std::string neg_inf, std::string pos_inf);
    void set_post_fix();
    void set_total_pts(int pts);

    std::string get_str(){return Eq;}
    Queue<Token*> get_post_fix(){return post_fix;}

    sf::Vector2f get_window_size(){return window_size;}
    sf::Vector2f get_origin(){return origin;}
    sf::Vector2f get_scale(){return scale;}
    sf::Vector2f get_Eq_domain(){return Eq_domain;}
    sf::Vector2f get_Screen_domain(){return Screen_domain;}
    sf::Vector2f get_angle(){return angle;}

    int get_total_pts(){return total_pts;}


    //Equation
    std::string Eq;
    Queue<Token*> post_fix;

    //Interface
    sf::Vector2f window_size;
    sf::Vector2f origin; //sfml origin
    sf::Vector2f scale;
    sf::Vector2f Eq_domain;
    sf::Vector2f Screen_domain;
    sf::Vector2f angle;
    sf::Vector2f offset;

    //resolution 
    int total_pts;

    tokenizer T;
    ShuntingYard Sy;
};

#endif 

