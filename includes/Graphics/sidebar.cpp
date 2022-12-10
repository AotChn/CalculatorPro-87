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

    domain.setFont(font);
    domain.setCharacterSize(25);
    domain.setStyle(sf::Text::Bold);
    domain.setFillColor(sf::Color::Black);
    domain.setPosition(sf::Vector2f(400, SCREEN_HEIGHT-(bottomBar.getSize().y/2)-15));

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
    window.draw(domain);

    
}

string &Sidebar::operator[](int index){
    return items[index];
}

void Sidebar::set_bottom_Bar_info(Graph_info* info){
    current_eq.setString(info->Eq);
    std::string domain_string = "Domain : (";
    domain_string += std::to_string(info->Screen_domain.x);
    domain_string += " , ";
    domain_string += std::to_string(info->Screen_domain.y);
    domain_string += ") | Range : (";
    domain_string += std::to_string(info->Screen_range.x);
    domain_string += " , ";
    domain_string += std::to_string(info->Screen_range.y);
    domain_string += ")";
    domain.setString(domain_string);
}

sf::RectangleShape Sidebar::create_button(int i,int j){
    sf::RectangleShape box1;
    if(i==1){
        box1.setFillColor(sf::Color(66,68,77,255));
    }
    else{
         box1.setFillColor(sf::Color(66,68,77,100));
    }
    box1.setPosition(sf::Vector2f(_left,(SCREEN_HEIGHT/10*j)));
    box1.setSize(sf::Vector2f(_width,SCREEN_HEIGHT/10));
    return box1;
}