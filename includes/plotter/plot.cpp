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
        cout<<endl<<"("<<x<<","<<y<<")";
        //this crashes because when i run rpn it deletes the postfix 
        //thus we can not run this more than once;
        set_point(x,y);
        coordinates.push_back(point);
        cout<<coordinates[i].first<<"|"<<coordinates[i].second; 
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
