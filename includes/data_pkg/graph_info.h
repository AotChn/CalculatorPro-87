/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: graph_info.h
 *  data wrapper for graphs 
 *  window size, origin, scale, domain, angle
 * manipulates graph based on pans, zooms, eq changes
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
    Graph_info(std::string str, Queue<Token*> postfix); //skip tokenizer step

    //Mutators
    void set_window   (double width, double height);
    void set_origin   (double x, double y);
    void set_scale    (double x, double y);
    void set_angle    (double x, double y);
    void set_s_domain (double x, double y);
    void set_s_range  (double x, double y);
    void set_offset   (double x = 0, double y = 0);

        //diff eq_domain cases
    void set_eq_domain (double min, double max);
    void set_eq_domain (double min, std::string pos_inf);
    void set_eq_domain (std::string neg_inf, double max);
    void set_eq_domain (std::string neg_inf, std::string pos_inf);

        //initilizations
    void set_origin();
    void set_string(std::string eq);
    void set_post_fix();
    void set_total_pts(int pts);

        //dependent mutators 
    void set_intervals();
    void offset_recalculate();
    void reset_scale();
    int set_grid_offset();

    //accessors
    sf::Vector2f get_window_size(){return window_size;}
    sf::Vector2f get_origin(){return origin;}
    sf::Vector2f get_scale(){return scale;}
    sf::Vector2f get_Eq_domain(){return Eq_domain;}
    sf::Vector2f get_Screen_domain(){return Screen_domain;}
    sf::Vector2f get_angle(){return angle;}

    int get_total_pts(){return total_pts;}
    std::string get_str(){return Eq;}
    Queue<Token*> get_post_fix(){return post_fix;}

    bool update; //true if graph updates
    //this so we dont continously run rpn/tokenizer if we have made the graph before

    //Equation
    std::string Eq;
    Queue<Token*> post_fix;

    //Interface
    sf::Vector2f window_size; //x / y demensions of sfml screen in px
    sf::Vector2f origin; //sfml origin
    sf::Vector2f scale; //zoom info
    sf::Vector2f Eq_domain; //default {-10,10}
    sf::Vector2f Screen_domain;
    sf::Vector2f Screen_range; 
    sf::Vector2f angle; 
    sf::Vector2f x_offset; //vertical pans
    sf::Vector2f y_offset; //horizontal pans

    //resolution 
    int total_pts; //default 750
    double intervals; 

};

#endif 

