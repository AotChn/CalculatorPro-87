#include "animate.h"
    
    Animate::Animate() : sidebar(WORK_PANEL, SIDE_BAR)
    {
        window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"Calculator Pro-87");
        window.setFramerateLimit(60);
        if(!font.loadFromFile("fonts/Roboto-Thin.ttf")){
            cout<<"animate font CTOR: Font failed to load"<<endl;
            exit(-1);
        }
        info = &graph;
        system.set_graph_info(info);
        graph.Eq = "";
        input = "";
        button_color = 0;
        highlight_pos = 2;
        Mousein = false;
        help_on = false;
    }

    //run application 
    void Animate::run(){
        cout<<"Calc Pro-87 starting "<<endl;
        cout<<"Preparing to load saved graphs[0%]"<<endl;
        load_graphs();
        cout<<"Graphs Loaded [Check]"<<endl;
        cout<<"Preprocesses complete [100%]"<<endl;
        take_input = false;
        while(window.isOpen()){
            process_events();
            update();
            render();
        }
    }

    //draws to be drawn on screen
    void Animate::Draw(){
        window.draw(name_stamp());
        system.draw_axis(window);
        sidebar.draw(window);
        window.draw(sidebar.create_button(button_color,highlight_pos));
        for(int i=0;i<6;i++){
            window.draw(sidebar.show_equation(graphs[i],i,show_graphs[i],0));
            if(show_graphs[i]){
                info->set_string(graphs[i]);
                system.Draw_curve(window,i);
                graphs[i]= info->Eq;
            }
        }
        gui.set_axis_labels(window);
        gui.set_help_button(window,font,help);
        if(help_on){
            load_help_screen();
        }
        if(take_input){
            window.draw(input_box());
            window.draw(input_text(input));
        }
    }

    //clear->draw->display cycle
    void Animate::render(){
        window.clear(sf::Color(20, 20, 20,255));
        Draw();
        window.display();
    }

    //any updates 
    void Animate::update(){
        sidebar.set_bottom_Bar_info(info,window,Mousein,graphs[highlight_pos-2]);
        gui.set_graph_info(info);
        if(help_on){
            help =2;
        }
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
                        if(highlight_pos<2){
                            highlight_pos = 2;
                        }
                    }
                    else if(event.text.unicode == '\n'){
                        if(take_input==true){
                        graphs[highlight_pos-2] = input;
                        show_graphs[highlight_pos-2] = true;   
                        input = "";
                        save_graphs();
                        take_input = false;
                        }
                    }
                    else if (event.text.unicode<128){
                        if(take_input){
                            input += event.text.unicode;
                        }
                    }
                }
                break;
                case sf::Event::KeyPressed:
                    if(!take_input){
                        if(event.key.code == sf::Keyboard::Left){
                            info->set_offset(-1,0);
                        }
                        else if(event.key.code == sf::Keyboard::Right){
                            info->set_offset(1,0);
                        }
                        else if(event.key.code == sf::Keyboard::Up){
                            info->set_offset(0,-1);
                        }
                        else if(event.key.code == sf::Keyboard::Down){
                            info->set_offset(0,1);
                        }
                        else if(event.key.code == sf::Keyboard::Space){
                            info->set_offset(-info->x_offset.y,-info->y_offset.y);
                        }
                        else if(event.key.code == sf::Keyboard::O){
                            info->set_scale(1,0);
                            info->offset_recalculate();
                        }
                        else if(event.key.code == sf::Keyboard::I){
                            info->set_scale(-1,0);
                            info->offset_recalculate();
                        }
                        else if(event.key.code == sf::Keyboard::R){
                            info->reset_scale();
                            info->offset_recalculate();
                        }
                        else if(event.key.code == sf::Keyboard::H){
                            help_on = !help_on;
                            if(!help_on){
                                help = 0;
                            }
                        }
                    }
                    break;
                // case sf::Event::Resized:
                //     graph.set_window(window.getSize().x,window.getSize().y);
                //     cout<<window.getSize().x<<"|";
                //     cout<<window.getView().getSize().x<<"|";
                //     cout<<window.getSize().y<<"|";
                //     cout<<window.getView().getSize().y<<endl;
                //     break;
                case sf::Event::MouseMoved:
                    Mousein = true;
                    if(sf::Mouse::getPosition(window).x>WORK_PANEL){
                        Mousein = false;
                        button_color = 1;
                        highlight_pos = -1;
                        int Mouse_y = (sf::Mouse::getPosition(window).y);
                        while(Mouse_y>0){
                            Mouse_y = Mouse_y-(BUTTON_SIZE);
                            highlight_pos++;
                        }
                        if(highlight_pos>7){
                            highlight_pos=7;
                        }
                        else if(highlight_pos<2){
                            highlight_pos=2;
                        }
                    }    
                    else{
                        button_color = 0;
                    }
                    if(sf::Mouse::getPosition(window).x>(166-40)&&sf::Mouse::getPosition(window).x<(166+40)){
                        if(sf::Mouse::getPosition(window).y>(166-40)&&sf::Mouse::getPosition(window).y<(166+40)){
                            help = 1;
                        }
                    }
                    else{
                        help = 0;
                    }
                    break;
                 case sf::Event::MouseButtonPressed:
                    //cout<<sf::Mouse::getPosition(window).x<<"|"<<sf::Mouse::getPosition(window).y<<endl;
                    if(sf::Mouse::getPosition(window).x>WORK_PANEL){
                        Mousein = false;
                        button_color = 1;
                        highlight_pos = -1;
                        int Mouse_y = (sf::Mouse::getPosition(window).y);
                        while(Mouse_y>0){
                            Mouse_y = Mouse_y-(BUTTON_SIZE);
                            highlight_pos++;
                        }
                        if(highlight_pos>7){
                            highlight_pos=7;
                        }
                        else if(highlight_pos<2){
                            highlight_pos=2;
                        }
                    }
                    
                    else{
                        button_color = 0;
                    }
                    if(!Mousein){
                        if(show_graphs[highlight_pos-2]==true){
                            show_graphs[highlight_pos-2] = false;    
                        }
                        else
                            show_graphs[highlight_pos-2] = true;
                    }
                    if(sf::Mouse::getPosition(window).x>(166-40)&&sf::Mouse::getPosition(window).x<(166+40)){
                        if(sf::Mouse::getPosition(window).y>(166-40)&&sf::Mouse::getPosition(window).y<(166+40)){
                            help_on = !help_on;
                        }
                    }
        
                    break;
                
                default:
                    break;

            }
        }
    }


//load previously saved graphs
void Animate::load_graphs(){
    ifstream inFile;
    ofstream output_f;
    inFile.open("history.txt");
    if(inFile.fail()){
        cout<< "Output file opening failed \n";
        exit(1);
    }
    for(int i = 0;i<6;i++){
        std::getline(inFile,input,'\n');
        graphs[i] = input;
        show_graphs[i] = false;
    }
    input = "";
    inFile.close();
}

//save graph to txt file when new graph is updated
void Animate::save_graphs(){
    ofstream output_f;
    output_f.open("history.txt",std::ofstream::trunc);
    if(output_f.fail()){
        cout<< "Output file opening failed \n";
        exit(1);
    }
    for(int i = 0;i<6;i++){
        output_f<<graphs[i]<<endl;
    }
    output_f.close();
}

//load help screen sprite
void Animate::load_help_screen(){
    if(!texture.loadFromFile("sprites/help_menu.png")){
        cout<<"help screen failed to load";
    }
    sprite.setPosition(sf::Vector2f(250,168));
    sprite.setTexture(texture);
    window.draw(sprite);
} 

//places logo
sf::Text Animate::name_stamp(){
    sf::Text name;
    name.setFont(font);
    name.setPosition(sf::Vector2f(1700,118));
    name.setFillColor(sf::Color(67,209,190));
    name.setCharacterSize(55);
    name.setString("Powered by CHTN TECH");
    name.setStyle(sf::Text::Bold);

    return name;
}

//text input box echo input
sf::Text Animate::input_text(std::string input){
    sf::Text input_text;
    if(strlen(input.c_str()) > 45){
        input = input.substr(strlen(input.c_str()) - 45, 45);
    }
    input_text.setString(input);
    input_text.setFillColor(sf::Color::Red);
    input_text.setPosition(sf::Vector2f(30,SCREEN_HEIGHT/6+30));
    input_text.setFont(font);
    input_text.setStyle(sf::Text::Bold);
    input_text.setCharacterSize(60);

    return input_text;
}

//input box for user string input
 sf::RectangleShape Animate::input_box(){
    sf::RectangleShape input_box;
    input_box.setFillColor(sf::Color(0,240,0,50));
    input_box.setPosition(sf::Vector2f(0,(SCREEN_HEIGHT/6)));
    input_box.setSize(sf::Vector2f(WORK_PANEL,(SCREEN_HEIGHT/6)));
    return input_box;
}