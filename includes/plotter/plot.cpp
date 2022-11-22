#include "plot.h"

Plot::Plot(){

}

Plot::Plot(Graph_info info){
    g_info = info;
}

sf::Vector2f Plot::operator()(){
    
}

void Plot::create_plot_map(){
    RPN calculate(g_info.post_fix);
    for(int i=0;i<g_info.total_pts;i++){
        x = i;
        calculate.set_instan(i);
        y = calculate();
        set_point(x,y);
        coordinates.push_back(point);
    }

}

void Plot::set_info(Graph_info info){
    g_info = info;
}

void Plot::set_point(double i, double j){
    point.first = i;
    point.second = j;
}

void Plot::set_point(pair<double,double> pt){
    sf_point.x = pt.first;
    sf_point.y = pt.second;
}

void Plot::Print(){
    int i;
    for(i=0;i<g_info.total_pts;i++){
        point = coordinates[i];
        cout<<"("<<point.first<<","<<point.second<<")"<<endl;
    }
}