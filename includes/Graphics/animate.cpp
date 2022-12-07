#include "animate.h"
    
    //run application 
    void Animate::run(){
        while(window.isOpen()){
            text.setFillColor(sf::Color::Red);
            text.setPosition(sf::Vector2f(600,30));
            text.setFont(font);
            text.setStyle(sf::Text::Bold);
            font.loadFromFile("Roboto-Thin.ttf");

            process_events();
            update();
            render();
        }
    }

    void Animate::Draw(){
        system.Draw(window);
        sidebar.draw(window);
        window.draw(text);
        
    }
    //clear->draw->display cycle
    void Animate::render(){
        window.clear(sf::Color(0, 0, 0,255));
        Draw();
        window.display();
    }

    void Animate::update(){

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
                        input = "";
                    }
                    else if (event.text.unicode<128){
                        input += event.text.unicode;
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
                
                default:
                break;
            }
        }
    }

// void Animate::create_new_graph(){
//     Graph_info graph("");
//     info = &graph;

// }



 //bool flag = !flag; toggle switch



// class window{

//     public:
//     window(){}

//     void show(){
//         sf::RenderWindow screen;
//         screen.create(sf::VideoMode(1400,800),"Cool window");
//         //we should see nothing program immediately closes with just this ^^
//         // lets make it do something cool 

//         while(screen.isOpen()){ //app stays open as long as not closed
//             sf::Event event;
//             while(screen.pollEvent(event)){
                
//                 if(event.type == sf::Event::Closed)
//                     screen.close();
//             }
        

//         screen.clear();
//         sf::CircleShape a(1.f);
//         a.setFillColor(sf::Color::Red);
//         a.setPosition(sf::Vector2f(700, 400));
//         screen.draw(a);
//       //  screen.draw(sf::CircleShape(500));
//         screen.display();
//         }
//     }

// };



