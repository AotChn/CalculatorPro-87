#include "graph_info.h"
#include "../Graphics/constants.h"

Graph_info::Graph_info(){
    set_s_domain(-10,10);
    set_eq_domain("neg_inf","pos_inf");
    set_window(WORK_PANEL,SCREEN_HEIGHT);
    set_origin(400,400);
    set_scale(0,0);
    total_pts = TOTAL_PTS;
    set_offset();
}

Graph_info::Graph_info(std::string str){
    Eq = str;
    tokenizer T;
    ShuntingYard Sy;
    T.set_str(str);
    T.tokenize();
    post_fix = Sy.postfix(T.get_infix());
    set_s_domain(-10,10);
    set_eq_domain("neg_inf","pos_inf");
    set_window(WORK_PANEL,SCREEN_HEIGHT);
    set_origin(WORK_PANEL/2,SCREEN_HEIGHT/2);
    set_scale(0,0);
    total_pts = TOTAL_PTS;
    set_offset();
}

Graph_info::Graph_info(std::string str, Queue<Token*> postfix){
    Eq = str;
    post_fix = postfix;
}

void Graph_info::set_post_fix(){
    tokenizer T;
    ShuntingYard Sy;
    T.set_str(Eq);
    T.tokenize();
    post_fix = Sy.postfix(T.get_infix());
}

void Graph_info::set_window(double width, double height){
    window_size.x = width;
    window_size.y = height;
}
void Graph_info::set_origin(double x, double y){
    origin.x = x;
    origin.y = y;
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

void Graph_info::set_offset(){
    offset.x = Screen_domain.x - Eq_domain.x; //left side
    offset.y = Screen_domain.y - Eq_domain.y; //right side
}