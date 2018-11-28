//
//  Plot.cpp
//  aka Animate
//
//  Created by Winnie Jeng on 11/27/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Plot.hpp"

using namespace std;

Plot::Plot():ControlPanel(WORK_PANEL, SIDE_BAR)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    
    //System will be implemented to manage a vector of objects to be Plotted.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    displayPanel = Display_Panel();
//    system = System();
    window.setFramerateLimit(60);
    
    mouseIn = true;
    
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(20.0);
    mousePoint.setFillColor(sf::Color(1,164,255));
    
    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    //Make sure that the font is loaded from the resourcePath() class with the file name
    // and that the target image file in Recources directory
    if (!font.loadFromFile(resourcePath() + "arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    
    myTextLabel = sf::Text("Graphing Calculator - Winnie Jeng - CS 3A November 2018", font);
    myTextLabel.setCharacterSize(22);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color(1, 164, 255));
    myTextLabel.setPosition(sf::Vector2f(WORK_PANEL/5, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-10));
    
    cout<<"animate instantiated successfully."<<endl;
}


void Plot::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    displayPanel.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }
    
    ControlPanel.draw(window);
    
    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -
    
    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}



void Plot::update(){
    //cause changes to the data for the next frame
//    displayPanel.Step(command);
//    command = 0;
//    if (mouseIn){
//        //mousePoint red dot:
//        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
//                               sf::Mouse::getPosition(window).y-5);
//
//        //mouse location text for sidebar:
//        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
//    }
}



void Plot::render(){
    window.clear();
    Draw();
    window.display();
}



void Plot::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
                // window closed
            case sf::Event::Closed:
                window.close();
                break;
                
                // key pressed
            case sf::Event::KeyPressed:
                switch(event.key.code){
                    case sf::Keyboard::Left:
                        ControlPanel[SB_KEY_PRESSED] = "LEFT ARROW";
                        command = 4;
                        break;
                    case sf::Keyboard::Right:
                        ControlPanel[SB_KEY_PRESSED] = "RIGHT ARROW";
                        command = 6;
                        break;
                    case sf::Keyboard::Escape:
                        ControlPanel[SB_KEY_PRESSED] = "ESC: EXIT";
                        window.close();
                        break;
                }
                break;
            case sf::Event::MouseEntered:
                mouseIn = true;
                break;
                
            case sf::Event::MouseLeft:
                mouseIn = false;
                break;
                
            case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    ControlPanel[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                    mouse_pos_string(window);
                    
                }
                else{
                    ControlPanel[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                    mouse_pos_string(window);
                }
                break;
                
            default:
                break;
        }
    }
}
void Plot::run()
{
    while (window.isOpen())
    {
        processEvents();
//        update();
        render(); //clear/draw/display
    }
    cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
    to_string(sf::Mouse::getPosition(window).x) +
    ", " +
    to_string(sf::Mouse::getPosition(window).y) +
    ")";
}
