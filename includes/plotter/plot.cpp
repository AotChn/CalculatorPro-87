#include "plot.h"

Plot::Plot(){

}

Plot::Plot(Graph_info info){
    g_info = info;
}

sf::Vector2f Plot::operator()(int i){
    return coordinates[i];
}

void Plot::create_plot_map(){
    RPN calculate(g_info.post_fix);
    int var = -400;
    double delta = 1200/300;
    for(int i=0;i<300;i++){
        x = var;
        calculate.set_instan(var);
        var = var + delta;
        y = calculate();
        set_point(x,y);
        coordinates.push_back(point);
    }
}

void Plot::set_info(Graph_info info){
    g_info = info;
}

void Plot::set_point(double i, double j){
    point.x = i;
    point.y = j;
}

void Plot::Print(){
    int i;
    for(i=0;i<g_info.total_pts;i++){
        point = coordinates[i];
        cout<<point.x<<"|"<<point.y<<endl;
    }
}

//we have set the point to become a real sf::Vector2f
//in this way we are able to be to handle coordinates and set them to be in the thing;