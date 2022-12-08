#include "../Graphics/constants.h"
#include "translator.h"


 Translator::Translator(Graph_info *Info){
    info = Info;
 }

void Translator::set_graph_info(Graph_info * Info){
    info = Info;
}

void Translator::set_delta_x(){
    dx = ((WORK_PANEL-(get_L_offset()+get_R_offset()))/TOTAL_PTS);
}   

void Translator::set_delta_y(){
    dy = (SCREEN_HEIGHT/(info->Screen_domain.y-info->Screen_domain.x));
}

double Translator::get_L_offset(){
    return (std::abs(info->Screen_domain.x-info->Eq_domain.x)*get_SDI());
}

double Translator::get_R_offset(){
    return (std::abs(info->Screen_domain.y-info->Eq_domain.y)*get_SDI());
}

double Translator::get_SDI(){
    return (WORK_PANEL/(info->Screen_domain.y-info->Screen_domain.x));
}

void Translator::set_start(){
    offset = get_L_offset();
}

sf::Vector2f Translator::cart_to_sfml(Vector<sf::Vector2f> coordinates, int i){
    set_delta_x();
    set_delta_y();
    set_start();
    sfml_point.x = std::abs(i * dx) + offset;
    sfml_point.y = -1*(coordinates[i].y * dy)+(SCREEN_HEIGHT/2);

    return sfml_point;
}

void Translator::print(){
    cout<<"SFML_PT.x = "<<sfml_point.x<<"|"<<"SFML_PT.y = "<<sfml_point.y<<endl;
    cout<<"Offset = "<<offset<<endl;
    cout<<"Delta_x = "<<dx<<endl;
    cout<<"Delta_y = "<<dy<<endl;
    cout<<"R_offset ="<<get_R_offset()<<endl;
    cout<<"L_offset ="<<get_L_offset()<<endl;
    cout<<"SDI ="<<get_SDI()<<endl;
    cout<<"eq domain x = "<<info->Eq_domain.x<<endl;
    cout<<"eq domain y = "<<info->Eq_domain.y<<endl;
}
