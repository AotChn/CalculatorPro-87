#include "plot.h"

Plot::Plot(){

}

Plot::Plot(Graph_info Info){
    info = &Info;
}

sf::Vector2f Plot::operator()(int i){
    return coordinates[i];
}

void Plot::create_plot_map(){
    info->set_post_fix();
    RPN calculate(info->get_post_fix());
    x = info->get_Eq_domain().x;
    for(int i=0;i<info->get_total_pts();i++){
        calculate.set_instan(x);
        y = calculate();
        set_point(x,y);
        coordinates.push_back(point);
        x = x + get_delta();
    }
}
void Plot::set_info(Graph_info info){
    info = info;
}

void Plot::set_point(double i, double j){
    point.x = i;
    point.y = j;
}

double Plot::get_delta(){
    return (info->Eq_domain.y-info->Eq_domain.x)/info->total_pts;
}

void Plot::Print(){
    int i;
    cout<<"GET DELTA ="<<get_delta();
    cout<<endl;
    for(i=0;i<info->total_pts;i++){
        point = coordinates[i];
        cout<<point.x<<"|"<<point.y<<endl;
    }
}

void Plot::print2(){
    cout<<"THIS MY INFO:"<<endl;
    cout<<info->Eq<<endl;
    cout<<info->Eq_domain.x<<endl;
    cout<<info->Eq_domain.y<<endl;
    cout<<"THIS IS MY EQuALTION:"<<info->Eq<<endl;
    info->set_post_fix();
    info->get_post_fix().print_pointers();
}

//we have set the point to become a real sf::Vector2f
//in this way we are able to be to handle coordinates and set them to be in the thing;