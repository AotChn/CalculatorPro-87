#include "system.h"
#include <iostream>

System::System(){
    shape = sf::CircleShape(5.f);
    sf::Vector2f;
    shape.setPosition(vel);
}

void System::Draw(sf::RenderWindow& window){
    for(int i=0;i<10;i++){
        sf::Vector2f a;
        Graph_info iu("x+5");
      //  iu.post_fix.print_pointers();
        iu.total_pts = 300;
        Plot P(iu);
        P.create_plot_map();
        a.x = P(i).x;
        a.y = P(i).y;
        shape.setPosition(a);
        window.draw(shape);    
    }
    sf::Vector2f a;
    a.x = 400;
    a.y = 400;
    shape.setPosition(a);
    shape.setFillColor(sf::Color::Red);
    window.draw(shape);   
    a.x = 0;
    a.y = 400;
    shape.setPosition(a);
    shape.setFillColor(sf::Color::Blue);
    window.draw(shape); 
    a.x = 400;
    a.y = 0;
    shape.setPosition(a);
    shape.setFillColor(sf::Color::Green);
    window.draw(shape); 
    a.x = 799;
    a.y = 400;
    shape.setPosition(a);
    shape.setFillColor(sf::Color::Red);
    window.draw(shape); 
    a.x = 400;
    a.y = 799;
    shape.setPosition(a);
    shape.setFillColor(sf::Color::Yellow);
    window.draw(shape); 
}

