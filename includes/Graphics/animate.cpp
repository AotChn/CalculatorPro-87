#include "animate.h"
    
    //run application 
    void Animate::run(){
        graph.Eq = "";
        load_graphs();
        take_input = false;
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
        system.Draw_axis(window);
        sidebar.draw(window);
        if(take_input){
            window.draw(input_box());
        }
        window.draw(text);
        window.draw(sidebar.create_button(button_color,j));
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
        window.draw(name_stamp());
    }
    //clear->draw->display cycle
    void Animate::render(){
        window.clear(sf::Color(20, 20, 20,255));
        Draw();
        window.display();
    }

    void Animate::update(){
        sidebar.set_bottom_Bar_info(info,window,Mousein,graphs[j-2]);
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
                        if(j<2){
                            j = 2;
                        }
                        if(!take_input){
                            text.setString(input);
                        }   
                    }
                    else if(event.text.unicode == '\n'){
                        if(take_input==true){
                        graphs[j-2] = input;
                        show_graphs[j-2] = true;   
                        input = "";
                        text.setString("");
                        save_graphs();
                        take_input = false;
                        }
                    }
                    else if (event.text.unicode<128){
                        if(take_input){
                            input += event.text.unicode;
                        }
                    }
                    if(take_input){
                        if(strlen(input.c_str())>45){
                            text.setString(input.substr(strlen(input.c_str())-45,45));
                        }
                        else{
                            text.setString(input);
                        }
                    }
                    else{
                        text.setString("");
                    }
                   // cout<<input<<endl;
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
                case sf::Event::Resized:
                    graph.set_window(window.getSize().x,window.getSize().y);
                    cout<<window.getSize().x<<"|";
                    cout<<window.getView().getSize().x<<"|";
                    cout<<window.getSize().y<<"|";
                    cout<<window.getView().getSize().y<<endl;
                    break;
                case sf::Event::MouseMoved:
                    Mousein = true;
                    if(sf::Mouse::getPosition(window).x>WORK_PANEL){
                        Mousein = false;
                        button_color = 1;
                        j = -1;
                        int Mouse_y = (sf::Mouse::getPosition(window).y);
                        while(Mouse_y>0){
                            Mouse_y = Mouse_y-(BUTTON_SIZE);
                            j++;
                        }
                        if(j>7){
                            j=7;
                        }
                        else if(j<2){
                            j=2;
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
                        j = -1;
                        int Mouse_y = (sf::Mouse::getPosition(window).y);
                        while(Mouse_y>0){
                            Mouse_y = Mouse_y-(BUTTON_SIZE);
                            j++;
                        }
                        if(j>7){
                            j=7;
                        }
                        else if(j<2){
                            j=2;
                        }
                    }
                    
                    else{
                        button_color = 0;
                    }
                    if(!Mousein){
                        if(show_graphs[j-2]==true){
                            show_graphs[j-2] = false;    
                        }
                        else
                            show_graphs[j-2] = true;
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

void Animate::create_graphs(){

}


 sf::RectangleShape Animate::input_box(){
    sf::RectangleShape input_box;
    input_box.setFillColor(sf::Color(0,240,0,50));
    input_box.setPosition(sf::Vector2f(0,(SCREEN_HEIGHT/6)));
    input_box.setSize(sf::Vector2f(WORK_PANEL,(SCREEN_HEIGHT/6)));
    return input_box;
}

void Animate::load_graphs(){
    ifstream inFile;
    ofstream output_f;
    inFile.open("history.txt");
   // output_f.open("Custom_function.tet");
// Test for failure here…
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

void Animate::save_graphs(){
    ofstream output_f;
    output_f.open("history.txt",std::ofstream::trunc);
   // output_f.open("Custom_function.tet");
// Test for failure here…
    if(output_f.fail()){
        cout<< "Output file opening failed \n";
        exit(1);
    }
    for(int i = 0;i<6;i++){
        output_f<<graphs[i]<<endl;
    }
    output_f.close();
}

void Animate::load_help_screen(){
    if(!texture.loadFromFile("help_menu.png")){
        cout<<"help screen failed to load";
    }
    sprite.setPosition(sf::Vector2f(250,168));
    sprite.setTexture(texture);
    window.draw(sprite);
} 

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