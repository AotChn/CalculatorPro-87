#include "animate.h"
    
    //run application 
    void Animate::run(){
        while(window.isOpen()){
            
            process_events();
            update();
            render();
        }
    }

    void Animate::Draw(){
        system.Draw(window);
        sidebar.draw(window);
    }
    //clear->draw->display cycle
    void Animate::render(){
        window.clear();
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
                default:
                break;
            }
        }
    }

 



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



