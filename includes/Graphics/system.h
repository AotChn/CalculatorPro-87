#ifndef AOTS_SYSTEM_H
#define AOTS_SYSTEM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../plotter/plot.h"
#include "../plotter/translator.cpp"

class System
{
public:
    System();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& window);

private:

    sf::CircleShape shape;
    Translator translator;
    sf::Vector2f vel;

};

#endif

