#include "graph_info.h"
#include "../Graphics/constants.h"

Graph_info::Graph_info(){
    set_s_domain(-10,10);
    set_s_range(-10,10);
    set_eq_domain("neg_inf","pos_inf");
    set_window(WORK_PANEL,SCREEN_HEIGHT);
    set_scale(0,0);
    scale.y = 0;
    set_total_pts(TOTAL_PTS);
}

Graph_info::Graph_info(std::string str){
    set_string(str);
    set_post_fix();
    set_s_domain(-10,10);
    set_s_range(-10,10);
    set_eq_domain("neg_inf","pos_inf");
    set_window(WORK_PANEL,SCREEN_HEIGHT);
    set_scale(0,0);
    scale.y = 0;
    set_total_pts(TOTAL_PTS);
}

Graph_info::Graph_info(std::string str, Queue<Token*> postfix){
    post_fix = postfix;
    set_string(str);
    set_post_fix();
    set_s_domain(-10,10);
    set_s_range(-10,10);
    set_eq_domain("neg_inf","pos_inf");
    set_window(WORK_PANEL,SCREEN_HEIGHT);
    set_scale(0,0);
    scale.y = 0;
    set_total_pts(TOTAL_PTS);
}

void Graph_info::set_string(std::string eq){
    Eq = eq;
    update = true;
}

//more pts = more resolution but with lines we do not need anything more than 750 
void Graph_info::set_total_pts(int pts){
    total_pts = pts;
    update = true;
}

//process equation into postfix + validity check
void Graph_info::set_post_fix(){
    tokenizer T;
    ShuntingYard Sy;
    T.set_str(Eq);
    T.tokenize();
    if(T.valid()==false){
        Eq = "!NOT VALID EXPRESSION!";
        T.set_str(Eq);
        T.tokenize();
    }
    post_fix = Sy.postfix(T.get_infix());
    update = true;
}

//window demensions
void Graph_info::set_window(double width, double height){
    window_size.x = width;
    window_size.y = height;
    set_origin();
    update = true;
}

//sfml origin by px
void Graph_info::set_origin(double x, double y){
    origin.x = x;
    origin.y = y;
    update = true;
}

//sfml origin
void Graph_info::set_origin(){ 
    origin.x = window_size.x/2;
    origin.y = window_size.y/2;
    update = true;
}

//when zoom 
void Graph_info::set_scale(double x, double y){ 
    scale.y = scale.y + x;
    if(scale.y>24){ //graph offset becomes too large after scale 2^24
        scale.y = 24;
    }
    else if(scale.y<-7){ //graph inverts itself after scale 2^-7
        scale.y = -7;
    }
    scale.x = scale.y;
    if(scale.y<0){ //scale down by facotr of 2
        scale.x = 1/(std::pow(2,std::abs(scale.y)));
    }
    else if (scale.y>0){ //scale up by factor of 2
        scale.x =(std::pow(2,scale.y));
    }
    else if(scale.y == 0){ //default 
        scale.x = 1;
    }
    set_eq_domain(-10*scale.x-x_offset.y,10*scale.x+x_offset.y);
    set_offset(0,0);
    update = true;
}

//restricted domain of eq
void Graph_info::set_eq_domain(double min, double max){
    Eq_domain.x = min;
    Eq_domain.y = max;
    update = true;
}

//x axis
void Graph_info::set_s_domain(double min, double max){
    Screen_domain.x = min;
    Screen_domain.y = max;
    update = true;
}

//y axis 
void Graph_info::set_s_range(double min, double max){
    Screen_range.x = min;
    Screen_range.y = max;
    update = true;
}

//not used yet
void Graph_info::set_angle(double x, double y){
    angle.x = x;
    angle.y = y;
    update = true;
}

//pos inf approaching a min
void Graph_info::set_eq_domain (double min, std::string pos_inf){
    Eq_domain.x = min;
    Eq_domain.y = Screen_domain.y;
    update = true;
}

//neg inf approching a max
void Graph_info::set_eq_domain (std::string neg_inf, double max){
    Eq_domain.y = max;
    Eq_domain.x = Screen_domain.x;
    update = true;
}

//default 
void Graph_info::set_eq_domain (std::string neg_inf, std::string pos_inf){
    Eq_domain.x = Screen_domain.x;
    Eq_domain.y = Screen_domain.y;
    update = true;
}

//when we pan an offset is created 
void Graph_info::set_offset(double x, double y){
    x_offset.y = x_offset.y + x;
    y_offset.y = y_offset.y + y;
    set_s_domain(Eq_domain.x-(x_offset.y),Eq_domain.y-(x_offset.y)); //x
    set_s_range(Eq_domain.x+(y_offset.y),Eq_domain.y+(y_offset.y));
    x_offset.x = x_offset.x + (x * (window_size.x/(Screen_domain.y - Screen_domain.x)));
    y_offset.x = y_offset.x + (y * (window_size.y/(Screen_domain.y - Screen_domain.x)));
    update = true;
}   

//when we zoom we must recalculate the offset created by new domain
//since domain will grow or shrink by factor of 2 (not linear i think)
void Graph_info::offset_recalculate(){
    x_offset.x = (x_offset.y * (window_size.x/(Screen_domain.y - Screen_domain.x)));
    y_offset.x = ((y_offset.y * (window_size.y/(Screen_domain.y - Screen_domain.x)))*1);
    update = true;
}

//scope of screen domain
void Graph_info::set_intervals(){
    intervals = (Screen_domain.y-Screen_domain.x);
}

//get correct grid positions in-respect to pans and zooms
int Graph_info::set_grid_offset(){ 
    int grid_offset = 0;
    // if((int)(scale.y)%2==0){
    // //     grid_offset = std::pow(2,scale.y-1);
    // // }
    // // else{
    // //     grid_offset = std::pow(2,scale.y);
    // // }
    // if(((int)(scale.y)!=0 &&(int)(scale.y)>0)){
    //     grid_offset = std::pow(2,scale.y);
    // }
    return grid_offset;
}

//reset graph to defualt zoom and pan
void Graph_info::reset_scale(){
    scale.y = 0;
    scale.x = 0;
    x_offset.x = 0;
    y_offset.x = 0;
    x_offset.y = 0;
    y_offset.y = 0;
    set_eq_domain(-10,10);
    set_s_domain(-10,10);
    set_s_range(-10,10);
}