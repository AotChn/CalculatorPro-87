#include "system.h"
#include <iostream>

double HEIGHT = 800;
double WIDTH = 800;

System::System(){
    shape = sf::CircleShape(1.f);
    sf::Vector2f;
    shape.setPosition(vel);
}

void System::Draw(sf::RenderWindow& window){
    //AXIS
    sf::Vertex x_axis[]={
        sf::Vertex(sf::Vector2f(0,WIDTH/2)),
        sf::Vertex(sf::Vector2f(WIDTH,WIDTH/2))
    };

    sf::Vertex y_axis[]={
        sf::Vertex(sf::Vector2f(HEIGHT/2,0)),
        sf::Vertex(sf::Vector2f(HEIGHT/2,HEIGHT))
    };
    window.draw(x_axis,2,sf::Lines); 
    window.draw(y_axis,2,sf::Lines);

    for(int i=0;i<300;i++){
        sf::Vector2f point;
        Graph_info iu("sin(x)");
      //  iu.post_fix.print_pointers();
        iu.total_pts = 300;
        Plot P(iu);
        P.create_plot_map();
        point = translator.cart_to_sfml(P(i));
        shape.setPosition(point);
        window.draw(shape);    
    }
    sf::Vector2f a;
    a.x = 400;
    a.y = 400;
    shape.setPosition(a);
    shape.setFillColor(sf::Color::Red);
    window.draw(shape);   
    //axis

}
