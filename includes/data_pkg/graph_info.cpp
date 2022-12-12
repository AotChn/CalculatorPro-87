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
    Eq = str;
    post_fix = postfix;
}
void Graph_info::set_string(std::string eq){
    Eq = eq;
    update = true;
}
void Graph_info::set_total_pts(int pts){
    total_pts = pts;
    update = true;
}
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

void Graph_info::set_window(double width, double height){
    window_size.x = width;
    window_size.y = height;
    set_origin();
    update = true;
}
void Graph_info::set_origin(double x, double y){
    origin.x = x;
    origin.y = y;
    update = true;
}
void Graph_info::set_origin(){
    origin.x = window_size.x/2;
    origin.y = window_size.y/2;
    update = true;
}
void Graph_info::set_scale(double x, double y){ 
    scale.y = scale.y + x;
    if(scale.y>24){
        scale.y = 24;
    }
    else if(scale.y<-7){
        scale.y = -7;
    }
    scale.x = scale.y;
    if(scale.y<0){
        scale.x = 1/(std::pow(2,std::abs(scale.y)));
    }
    else if (scale.y>0){
        scale.x =(std::pow(2,scale.y));
    }
    else if(scale.y == 0){
        scale.x = 1;
    }
    set_eq_domain(-10*scale.x-x_offset.y,10*scale.x+x_offset.y);
    set_offset(0,0);
    cout<<scale.y<<endl;
    update = true;
}
void Graph_info::set_eq_domain(double min, double max){
    Eq_domain.x = min;
    Eq_domain.y = max;
    update = true;
}
void Graph_info::set_s_domain(double min, double max){
    Screen_domain.x = min;
    Screen_domain.y = max;
    update = true;
}
void Graph_info::set_s_range(double min, double max){
    Screen_range.x = min;
    Screen_range.y = max;
    update = true;
}
void Graph_info::set_angle(double x, double y){
    angle.x = x;
    angle.y = y;
    update = true;
}

void Graph_info::set_eq_domain (double min, std::string pos_inf){
    Eq_domain.x = min;
    Eq_domain.y = Screen_domain.y;
    update = true;
}
void Graph_info::set_eq_domain (std::string neg_inf, double max){
    Eq_domain.y = max;
    Eq_domain.x = Screen_domain.x;
    update = true;
}
void Graph_info::set_eq_domain (std::string neg_inf, std::string pos_inf){
    Eq_domain.x = Screen_domain.x;
    Eq_domain.y = Screen_domain.y;
    update = true;
}

void Graph_info::set_offset(double x, double y){
    x_offset.y = x_offset.y + x;
    y_offset.y = y_offset.y + y;
    set_s_domain(Eq_domain.x-(x_offset.y),Eq_domain.y-(x_offset.y)); //x
    set_s_range(Eq_domain.x+(y_offset.y),Eq_domain.y+(y_offset.y));
    x_offset.x = x_offset.x + (x * (window_size.x/(Screen_domain.y - Screen_domain.x)));
    y_offset.x = y_offset.x + (y * (window_size.y/(Screen_domain.y - Screen_domain.x)));
    update = true;
}   
void Graph_info::offset_recalculate(){
    x_offset.x = (x_offset.y * (window_size.x/(Screen_domain.y - Screen_domain.x)));
    y_offset.x = ((y_offset.y * (window_size.y/(Screen_domain.y - Screen_domain.x)))*1);
    update = true;
}

void Graph_info::set_intervals(){
    intervals = (Screen_domain.y-Screen_domain.x);
}

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