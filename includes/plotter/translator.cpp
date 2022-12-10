#include "../Graphics/constants.h"
#include "translator.h"


 Translator::Translator(Graph_info *Info){
    info = Info;
 }

void Translator::set_graph_info(Graph_info * Info){
    info = Info;
}

void Translator::set_delta_x(){
    dx = (info->window_size.x/(info->Screen_domain.y-info->Screen_domain.x));
}   

void Translator::set_delta_y(){
    dy = (info->window_size.y/(info->Screen_domain.y-info->Screen_domain.x));
}

double Translator::get_SDI(){
    return (info->window_size.x/(info->Screen_domain.y-info->Screen_domain.x));
}


sf::Vector2f Translator::cart_to_sfml(sf::Vector2f coords){
    set_delta_x();
    set_delta_y();
    sfml_point.x = (coords.x  * dx) + info->origin.x + (dx*info->x_offset.y);
    sfml_point.y = -1*(coords.y * dy) + info->origin.y + (dx*info->y_offset.y);
    return sfml_point;
}

void Translator::print(){
    cout<<"SFML_PT.x = "<<sfml_point.x<<"|"<<"SFML_PT.y = "<<sfml_point.y<<endl;
    cout<<"Offset = "<<offset<<endl;
    cout<<"Delta_x = "<<dx<<endl;
    cout<<"Delta_y = "<<dy<<endl;
    cout<<"SDI ="<<get_SDI()<<endl;
    cout<<"eq domain x = "<<info->Eq_domain.x<<endl;
    cout<<"eq domain y = "<<info->Eq_domain.y<<endl;
}
