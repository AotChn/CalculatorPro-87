#include "interface.h"

// Interface::Interface(Graph_info * Info){
//     info = Info;
// }

// void Interface::set_graph_info(Graph_info * Info){
//     info = Info;
// }

// void Interface::set_axis_labels(sf::RenderWindow& window){
//     sf::Text label;
//     sf::Font font;
//     font.loadFromFile("Roboto-Thin.ttf");
//     double SDI = info->window_size.x/info->intervals;
//     label.setCharacterSize(60);
//     label.setFillColor(sf::Color(255,255,255,255));
//     label.setFont(font);
//     label.setString("test1");
//     label.setPosition(sf::Vector2f(0,(info->intervals/2*SDI)+info->y_offset.x));
//     window.draw(label);
//     label.setPosition(sf::Vector2f(info->window_size.x,(info->intervals/2*SDI)+info->y_offset.x));
//     window.draw(label);
//     label.setPosition(sf::Vector2f((info->intervals/2*SDI)+info->x_offset.x+info->scale.y,0));
//     window.draw(label);
//     label.setPosition(sf::Vector2f((info->intervals/2*SDI)+info->x_offset.x+info->scale.y,info->window_size.y));
//     window.draw(label);
// }