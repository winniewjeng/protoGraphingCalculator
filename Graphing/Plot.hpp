//
//  Plot.hpp
//  aka Animate
//
//  Created by Winnie Jeng on 11/27/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Plot_hpp
#define Plot_hpp

#include <SFML/Graphics.hpp>
#include "ControlPanel.hpp"
#include "Display_Panel.hpp"
#include "Constants.hpp"
#include <iostream>
#include "ResourcePath.hpp"

class Plot{
public:
    
    Plot();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    Display_Panel displayPanel;                      //container for all the Plotted objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    ControlPanel ControlPanel;                    //rectangular message sidebar
    
};

string mouse_pos_string(sf::RenderWindow& window);

#endif /* Plot_hpp */
