#include "translator.h"


sf::Vector2f Translator::cart_to_sfml(sf::Vector2f cart_coords){
    sfml_point.x = (info.window_size.x/2) + cart_coords.x; //x-axis
    sfml_point.y = (info.window_size.y/2) - cart_coords.y; //y-axis
    return sfml_point;
}