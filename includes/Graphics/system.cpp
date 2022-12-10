#include "system.h"
#include <iostream>

System::System(){
    shape = sf::CircleShape(1.f);
    shape.setFillColor(sf::Color(28,198,28));
    shape.setPosition(vel);
}

void System::set_graph_info(Graph_info * Info){
    info = Info;
}

void System::Draw(sf::RenderWindow& window){
    Translator T(info);
    Plot P;
    P.set_info(info);
    double SDI = T.get_SDI();
    info->set_intervals();
    if(info->scale.y>-2&&info->scale.y<2)
    for(int i=0;i<info->intervals;i++){
        sf::Vertex hori_lines[]={
            sf::Vertex(sf::Vector2f(0,i*SDI),sf::Color(70,70,70,255)),
            sf::Vertex(sf::Vector2f(SCREEN_WIDTH,i*SDI),sf::Color(70,70,70,255))
        };
        sf::Vertex vert_lines[]={
        sf::Vertex(sf::Vector2f(i*SDI,0),sf::Color(70,70,70,255)),
        sf::Vertex(sf::Vector2f(i*SDI,SCREEN_HEIGHT),sf::Color(70,70,70,255))
    };
        window.draw(hori_lines,2,sf::Lines);
        window.draw(vert_lines,2,sf::Lines);
    }
        //AXIS
    //info->set_offset(2);
    sf::Vertex x_axis[]={
        sf::Vertex(sf::Vector2f(0,(info->intervals/2*SDI)+info->y_offset.x),sf::Color(255,255,255,255)),
        sf::Vertex(sf::Vector2f(info->window_size.x,(info->intervals/2*SDI)+info->y_offset.x),sf::Color(255,255,255,255))
    };

    sf::Vertex y_axis[]={
        sf::Vertex(sf::Vector2f((info->intervals/2*SDI)+info->x_offset.x+info->scale.y,0),sf::Color(255,255,255,255)),
        sf::Vertex(sf::Vector2f((info->intervals/2*SDI)+info->x_offset.x+info->scale.y,info->window_size.y),sf::Color(255,255,255,255))
    };

    window.draw(x_axis,2,sf::Lines); 
    window.draw(y_axis,2,sf::Lines);
    P.create_plot_map();

    sf::VertexArray curve(sf::LinesStrip, info->total_pts);
    for(int i=0;i<info->total_pts;i++){
        curve[i] = (sf::Vertex(T.cart_to_sfml(P(i)),sf::Color(22,192,22)));
    }
    if(info->Eq!=""){
        window.draw(curve);
    }
}




