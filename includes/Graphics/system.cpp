#include "system.h"
#include <iostream>

System::System(){
    shape = sf::CircleShape(1.f);
    sf::Vector2f;
    shape.setPosition(vel);
}

void System::Draw(sf::RenderWindow& window){
    for(int i=0;i<1400;i=i+5){
        
        int j = 800-i;
        sf::Vector2f a;
        a.x = i;
        a.y = j;
        shape.setPosition(a);
        window.draw(shape);    
    }
    
}