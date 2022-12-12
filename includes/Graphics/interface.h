/* ************************************************************************* *
 * AUTHOR:      Aot Chanthorn
 * PROJECT:  GRAPHIC CALCULATOR
 * ------------------------------------------------------------------------- *
 * File: interface.h
 *  handles all interface elements 
 * 
 * ************************************************************************* */

#ifndef INTERFACE_H
#define INTERFACE_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>
#include <string>
#include <vector>
#include "../data_pkg/graph_info.h"
using namespace std;


class Interface
{
public:
    Interface(){}

Interface(Graph_info * Info){
    info = Info;
}

void set_graph_info(Graph_info * Info){
    info = Info;
}

void set_axis_labels(sf::RenderWindow& window){
    sf::Text label;
    sf::Font font;
    double posY;
    double posX;
    font.loadFromFile("Roboto-Thin.ttf");
    double SDI = info->window_size.x/info->intervals;
    label.setCharacterSize(30);
    label.setFillColor(sf::Color(255,255,255,255));
    label.setFont(font);
    posY = (info->intervals/2*SDI)+info->y_offset.x;
    if(posY<0){
        posY = 0;
    }
    else if(posY>SCREEN_HEIGHT-80){
        posY = SCREEN_HEIGHT-80;
    }
    if(info->scale.y>=-1){
        label.setString(std::to_string((int)info->Screen_domain.x));
        label.setPosition(sf::Vector2f(0,posY));
        window.draw(label); //min x

        label.setString(std::to_string((int)info->Screen_domain.y));
        label.setPosition(sf::Vector2f(info->window_size.x-140,posY));
        window.draw(label); //max x
    }
    else{
        label.setString(std::to_string(info->Screen_domain.x));
        label.setPosition(sf::Vector2f(0,posY));
        window.draw(label); //min x

        label.setString(std::to_string(info->Screen_domain.y));
        label.setPosition(sf::Vector2f(info->window_size.x-140,posY));
        window.draw(label); //max x
    }

    posX = (info->intervals/2*SDI)+info->x_offset.x+info->scale.y;
    if(posX<0){
        posX = 0;
    }
    else if(posX>WORK_PANEL-140){
        posX = WORK_PANEL-140;
    }

    if(info->scale.y>=-1){
        label.setString(std::to_string((int)info->Screen_range.y));
        label.setPosition(sf::Vector2f(posX,0));
        window.draw(label); //min y
        
        label.setString(std::to_string((int)info->Screen_range.x));
        label.setPosition(sf::Vector2f(posX,info->window_size.y-120));
        window.draw(label); //max y
    }
    else{
        label.setString(std::to_string(info->Screen_range.y));
        label.setPosition(sf::Vector2f(posX,0));
        window.draw(label); //min y
        
        label.setString(std::to_string(info->Screen_range.x));
        label.setPosition(sf::Vector2f(posX,info->window_size.y-120));
        window.draw(label); //max y
    }
}

void set_help_button(sf::RenderWindow& window, sf::Font font, int state){
    sf::RectangleShape help;
    sf::Text help_label;
    help.setSize(sf::Vector2f(40*2,40*2));
    help.setOrigin(40,40);
    help.setPosition(sf::Vector2f(166,166));
    if(state==1){
        help.setFillColor(sf::Color(89,157,255,255));
    }
    else if(state==2){
        help.setFillColor(sf::Color::Green);
    }
    else{
        help.setFillColor(sf::Color(89,157,255,100));
    }
    window.draw(help);

    help_label.setFillColor(sf::Color(sf::Color::Black));
    help_label.setString("help");
    help_label.setStyle(sf::Text::Bold);
    help_label.setCharacterSize(30);
    help_label.setFont(font);
    help_label.setOrigin(help_label.getLocalBounds().width/2,help_label.getLocalBounds().height/2);
    help_label.setPosition(sf::Vector2f(166,166));
    window.draw(help_label);


}

void show_help_page(sf::RenderWindow& window, sf::Font font){

}

private:
    Graph_info * info;
};
#endif // SIDEBAR_H