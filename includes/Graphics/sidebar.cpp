#include "sidebar.h"
Sidebar::Sidebar()
{
}

Sidebar::Sidebar(float left, float width) : _left(left), _width(width){
    cout << "Sidebar CTOR: TOP" << endl;

    // set up the sidebar rectangle:
    rect.setFillColor(sf::Color(50,50,50,255)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left,0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout << "Sidebar CTOR: about to load font." << endl;

    bottomBar.setFillColor(sf::Color(89,157,255,255));
    bottomBar.setPosition(sf::Vector2f(0,SCREEN_HEIGHT-45));
    bottomBar.setSize(sf::Vector2f(SCREEN_WIDTH,45));

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // the font file must be in the "working directory"
    //  check projects->run->working directory
    //       [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout << "Sidebar() CTOR: Font failed to load" << endl;
        cin.get();
       // exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout << "Sidebar CTOR: loaded font." << endl;

    //. . . . . text / font problems: . . . . . . . .
    // initializing text object in this way caused problems
    // (hangs!)
    // only when sb_text was a private member and worked fine
    // when it was a public member. Probably not releavant,
    // but still strange!
    //
    // sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout << "Sidebar CTOR: Text object initialized." << endl;
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

    ////this is how you would position text on screen:
    // sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    items.push_back("sidebar sample text");
    // Fill the items vector with empty strings so that we can use [] to read them:
    for (int i = 0; i < 30; i++){
        items.push_back("");
    }
    cout << "Sidebar: CTOR: Exit." << endl;
}

void Sidebar::draw(sf::RenderWindow &window){
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;
    window.draw(rect);
    window.draw(bottomBar);
    window.draw(current_eq);
    window.draw(current_coord);

    
}

string &Sidebar::operator[](int index){
    return items[index];
}

void Sidebar::set_bottom_Bar_info(Graph_info* info, sf::RenderWindow& window, bool Mousein, std::string input){
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

sf::RectangleShape Sidebar::create_button(int i,int j){
    sf::RectangleShape box1;
    if(j == 0){
        box1.setFillColor(sf::Color(66,68,77,0));
    }
    else if(i==1){
        box1.setFillColor(sf::Color(66,68,77,255));
    }
    else{
         box1.setFillColor(sf::Color(66,68,77,100));
    }
    box1.setPosition(sf::Vector2f(_left,(SCREEN_HEIGHT/10*j)));
    box1.setSize(sf::Vector2f(_width,SCREEN_HEIGHT/10));
    return box1;
}

sf::Text Sidebar::show_equation(std::string eq, int j){
    sf::Text eq_string;
    eq_string.setString(eq);
    eq_string.setStyle(sf::Text::Bold);
    eq_string.setFont(font);
    eq_string.setFillColor(sf::Color::White);
    eq_string.setPosition(sf::Vector2f(_left+200,(SCREEN_HEIGHT/10*(j+2))+30));
    eq_string.setCharacterSize(100);
    return eq_string;
}