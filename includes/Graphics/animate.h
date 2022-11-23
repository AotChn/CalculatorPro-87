#ifndef AOTS_ANIMATE_H
#define AOTS_ANIMATE_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include <string>
// #include "sidebar.h"

class Animate{

    public:

    Animate(){
        window.create(sf::VideoMode(1400,800),"TEST_WINDOW");
        window.setFramerateLimit(60);
    }
    
    void run();
    void Draw();
    void render();
    void update();
    void process_events();

    private:
    System system;
    Sidebar sidebar;
    sf::RenderWindow window;


};
//clear -> draw -> display cycle  is the way to draw stuff
//no other good way to do it 


#endif 
