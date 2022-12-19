#include "sidebar.h"
Sidebar::Sidebar()
{
}

Sidebar::Sidebar(float left, float width) : _left(left), _width(width){
    
    rect.setFillColor(sf::Color(50,50,50,255)); 
    rect.setPosition(sf::Vector2f(left,0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));


    bottomBar.setFillColor(sf::Color(89,157,255,255));
    bottomBar.setPosition(sf::Vector2f(0,SCREEN_HEIGHT-45));
    bottomBar.setSize(sf::Vector2f(SCREEN_WIDTH,45));

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // the font file must be in the "working directory"
    //  check projects->run->working directory
    //       [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("fonts/Roboto-Thin.ttf")){
        cout << "Sidebar() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }

    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setFillColor(sf::Color::Yellow);

    current_eq.setFont(font);
    current_eq.setCharacterSize(40);
    current_eq.setStyle(sf::Text::Bold);
    current_eq.setFillColor(sf::Color::Black);
    current_eq.setPosition(sf::Vector2f(30, SCREEN_HEIGHT-50));

    current_coord.setFont(font);
    current_coord.setCharacterSize(25);
    current_coord.setStyle(sf::Text::Bold);
    current_coord.setFillColor(sf::Color::Black);
    current_coord.setPosition(sf::Vector2f(600, SCREEN_HEIGHT-(bottomBar.getSize().y/2)-15));

}

//draws all renderables 
void Sidebar::draw(sf::RenderWindow &window){
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;
    window.draw(rect);
    window.draw(bottomBar);
    window.draw(current_eq);
    window.draw(current_coord);
}

//current cartesian coords and eq display
void Sidebar::set_bottom_Bar_info(Graph_info* info, sf::RenderWindow& window, bool Mousein, std::string input){
    //we do not want to flood the bottom bar with mass text if user inputs large string
    if(strlen((input.c_str()))>20){
        current_eq.setString("y = "+(input).substr(0,20)+"...");
    }
    else{
        current_eq.setString("y = "+(input).substr(0,20));
    }
    if(Mousein){
        Translator T;
        T.set_graph_info(info);
        sf::Vector2f Mouse_pos(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
        std::string cart_coords;
        cart_coords += "Current Coordinates :(" + to_string(T.sfml_to_cart(Mouse_pos).x) + "," + to_string(T.sfml_to_cart(Mouse_pos).y) + ")";
        current_coord.setString(cart_coords);
    }
}

//interface highlight box
sf::RectangleShape Sidebar::create_button(int i,int activate){
    sf::RectangleShape box1;
    if(activate == 0){
        box1.setFillColor(sf::Color(66,68,77,0));
    }
    else if(i==1){
        box1.setFillColor(sf::Color(66,68,77,255));
    }
    else{
         box1.setFillColor(sf::Color(66,68,77,100));
    }
    box1.setPosition(sf::Vector2f(_left,(SCREEN_HEIGHT/10*activate)));
    box1.setSize(sf::Vector2f(_width,SCREEN_HEIGHT/10));
    return box1;
}

sf::Text Sidebar::show_equation(std::string eq, int j, bool on, int state){
    sf::Text eq_string;
    eq_string.setString(eq);
    eq_string.setStyle(sf::Text::Bold);
    eq_string.setFont(font);
    if(on){
        eq_string.setFillColor(sf::Color::Green);
    }
    else if(state==1){
        eq_string.setFillColor(sf::Color::Yellow);
    }
    else{
        eq_string.setFillColor(sf::Color::White);
    }
    eq_string.setPosition(sf::Vector2f(_left+200,(SCREEN_HEIGHT/10*(j+2))+30));
    eq_string.setCharacterSize(50);
    return eq_string;
}