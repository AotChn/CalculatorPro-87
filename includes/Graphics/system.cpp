#include "system.h"
#include <iostream>

System::System(){
    shape = sf::CircleShape(1.f);
    sf::Vector2f;
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(vel);
}

void System::set_graph_info(Graph_info * Info){
    info = Info;
}


void System::Draw(sf::RenderWindow& window){
    info->set_s_domain(-10,10);
  //  info->set_eq_domain(-2,2);

    translator.set_graph_info(info);
    Plot P(info);
    double SDI = translator.get_SDI();
    int intervals = (info->Screen_domain.y-info->Screen_domain.x);
    for(int i=0;i<intervals;i++){
        sf::Vertex hori_lines[]={
            sf::Vertex(sf::Vector2f(0,i*SDI),sf::Color(50,50,255,75)),
            sf::Vertex(sf::Vector2f(SCREEN_WIDTH,i*SDI),sf::Color(50,50,255,75))
        };
        sf::Vertex vert_lines[]={
        sf::Vertex(sf::Vector2f(i*SDI,0),sf::Color(50,50,255,75)),
        sf::Vertex(sf::Vector2f(i*SDI,SCREEN_HEIGHT),sf::Color(50,50,255,75))
    };
        window.draw(hori_lines,2,sf::Lines);
        window.draw(vert_lines,2,sf::Lines);
    }
        //AXIS
    sf::Vertex x_axis[]={
        sf::Vertex(sf::Vector2f(0,SCREEN_HEIGHT/2),sf::Color(255,255,255,255)),
        sf::Vertex(sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT/2),sf::Color(255,255,255,255))
    };

    sf::Vertex y_axis[]={
        sf::Vertex(sf::Vector2f((WORK_PANEL/2),0),sf::Color(255,255,255,255)),
        sf::Vertex(sf::Vector2f((WORK_PANEL/2),SCREEN_HEIGHT),sf::Color(255,255,255,255))
    };

    window.draw(x_axis,2,sf::Lines); 
    window.draw(y_axis,2,sf::Lines);
    P.create_plot_map();
    //P.Print();
    
    for(int i=0;i<info->total_pts;i++){
        sf::Vector2f point;
        point = translator.cart_to_sfml(P.get_coords(),i);
        shape.setPosition(point);
        window.draw(shape);    
    }
    // sf::Vector2f a;
    // sf::CircleShape origin(3.f);
    // a.x = WORK_PANEL/2;
    // a.y = SCREEN_HEIGHT/2;
    // shape.setPosition(a);
    // shape.setFillColor(sf::Color::Red);
    // window.draw(origin);   
    //axis

}




