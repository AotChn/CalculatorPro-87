#include "animate.h"
    
    //run application 
    void Animate::run(){
        graph.Eq = "x";
        create_new_graph();
        while(window.isOpen()){
            text.setFillColor(sf::Color::Red);
            text.setPosition(sf::Vector2f(30,SCREEN_HEIGHT/6+30));
            text.setFont(font);
            text.setStyle(sf::Text::Bold);
            text.setCharacterSize(60);
            font.loadFromFile("Roboto-Thin.ttf");

            process_events();
            update();
            render();
        }
    }

    void Animate::Draw(){
        system.Draw(window);
        sidebar.draw(window);
        if(take_input){
            window.draw(input_box());
        }
        window.draw(text);
        
    }
    //clear->draw->display cycle
    void Animate::render(){
        window.clear(sf::Color(0, 0, 0,255));
        Draw();
        window.display();
    }

    void Animate::update(){
     // graph.set_eq_domain(-2,2);
    }

    void Animate::process_events(){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                window.close();
                break;
                case sf::Event::TextEntered:{
                    if(event.text.unicode == '\b'){
                        input.pop_back();
                    }
                    else if(event.text.unicode == '\t'){
                        take_input = !take_input;
                        if(!take_input){
                            text.setString(input);
                        }   
                    }
                    else if(event.text.unicode == '\n'){
                        take_input = false;
                        if(input != ""){
                            graph.Eq = input;    
                        }
                        input = "";
                        text.setString("");
                    }
                    else if (event.text.unicode<128){
                        if(take_input){
                            input += event.text.unicode;
                        }
                    }
                    if(take_input){
                        text.setString(input);
                    }
                    else{
                        text.setString("");
                    }
                    cout<<input<<endl;
                }
                break;
                case sf::Event::Resized:
                    graph.set_window(window.getSize().x,window.getSize().y);
                    cout<<window.getSize().x<<"|";
                    cout<<window.getView().getSize().x<<"|";
                    cout<<window.getSize().y<<"|";
                    cout<<window.getView().getSize().y<<endl;

                    break;
            }
        }
    }

void Animate::create_new_graph(){
    info = &graph;
    system.set_graph_info(info);
}


 sf::RectangleShape Animate::input_box(){
    sf::RectangleShape input_box;
    input_box.setFillColor(sf::Color(0,240,0,50));
    input_box.setPosition(sf::Vector2f(0,(SCREEN_HEIGHT/6)));
    input_box.setSize(sf::Vector2f(WORK_PANEL,(SCREEN_HEIGHT/6)));
    return input_box;
}