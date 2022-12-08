#include "graph_info.h"
#include "../Graphics/constants.h"

Graph_info::Graph_info(){
    set_s_domain(-10,10);
    set_eq_domain("neg_inf","pos_inf");
    set_window(WORK_PANEL,SCREEN_HEIGHT);
    set_scale(0,0);
    set_total_pts(TOTAL_PTS);
}

Graph_info::Graph_info(std::string str){
    set_string(str);
    set_post_fix();
    set_s_domain(-10,10);
    set_eq_domain("neg_inf","pos_inf");
    set_window(WORK_PANEL,SCREEN_HEIGHT);
    set_scale(0,0);
    set_total_pts(TOTAL_PTS);
}

Graph_info::Graph_info(std::string str, Queue<Token*> postfix){
    Eq = str;
    post_fix = postfix;
}
void Graph_info::set_string(std::string eq){
    Eq = eq;
}
void Graph_info::set_total_pts(int pts){
    total_pts = pts;
}
void Graph_info::set_post_fix(){
    T.set_str(Eq);
    T.tokenize();
    post_fix = Sy.postfix(T.get_infix());
}

void Graph_info::set_window(double width, double height){
    window_size.x = width;
    window_size.y = height;
    set_origin();
}
void Graph_info::set_origin(double x, double y){
    origin.x = x;
    origin.y = y;
}
void Graph_info::set_origin(){
    origin.x = window_size.x/2;
    origin.y = window_size.y/2;
}
void Graph_info::set_scale(double x, double y){
    scale.x = x;
    scale.y = y;
}
void Graph_info::set_eq_domain(double min, double max){
    Eq_domain.x = min;
    Eq_domain.y = max;
}
void Graph_info::set_s_domain(double min, double max){
    Screen_domain.x = min;
    Screen_domain.y = max;
}
void Graph_info::set_angle(double x, double y){
    angle.x = x;
    angle.y = y;
}

void Graph_info::set_eq_domain (double min, std::string pos_inf){
    Eq_domain.x = min;
    Eq_domain.y = Screen_domain.y;
}
void Graph_info::set_eq_domain (std::string neg_inf, double max){
    Eq_domain.y = max;
    Eq_domain.x = Screen_domain.x;
}
void Graph_info::set_eq_domain (std::string neg_inf, std::string pos_inf){
    Eq_domain.x = Screen_domain.x;
    Eq_domain.y = Screen_domain.y;
}
