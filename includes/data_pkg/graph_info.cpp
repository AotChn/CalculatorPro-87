#include "graph_info.h"



Graph_info::Graph_info(std::string str){
    Eq = str;
    tokenizer T;
    ShuntingYard Sy;
    T.set_str(str);
    T.tokenize();
    post_fix = Sy.postfix(T.get_infix());
}

Graph_info::Graph_info(std::string str, Queue<Token*> postfix){
    Eq = str;
    post_fix = postfix;
}

void Graph_info::set_window(double x, double y){
    window_size.x = x;
    window_size.y = y;
}
void Graph_info::set_origin(double x, double y){
    origin.x = x;
    origin.y = y;
}
void Graph_info::set_scale(double x, double y){
    scale.x = x;
    scale.y = y;
}
void Graph_info::set_domain(double x, double y){
    domain.x = x;
    domain.y = y;
}
void Graph_info::set_angle(double x, double y){
    angle.x = x;
    angle.y = y;
}
