//
//  DisplayPanel.cpp
//   aka System
//
//  Created by Winnie Jeng on 11/27/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "DisplayPanel.hpp"

// CTOR
DisplayPanel::DisplayPanel()
{
    //DisplayPanel ctor configs a window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing Calculator");
    
    // DisplayPanel ctor configs x-axis
    xAxis = sf::VertexArray(sf::LinesStrip, 3);
    xAxis[0].position = sf::Vector2f(0, SCREEN_HEIGHT / 2);
    xAxis[0].color = sf::Color(255, 0, 91); //red
    xAxis[1].position = sf::Vector2f(SCREEN_WIDTH*4/10, SCREEN_HEIGHT / 2);
    xAxis[1].color = sf::Color::White;
    xAxis[2].position = sf::Vector2f(SCREEN_WIDTH*4/5, SCREEN_HEIGHT / 2);
    xAxis[2].color = sf::Color(143, 69, 225); //purple
    
    // DisplayPanel ctor configs y-axis
    yAxis = sf::VertexArray(sf::LinesStrip, 3);
    yAxis[0].position = sf::Vector2f(SCREEN_WIDTH*4/10, 0);
    yAxis[0].color = sf::Color(50, 103, 206); //green
    yAxis[1].position = sf::Vector2f(SCREEN_WIDTH*4/10, SCREEN_HEIGHT / 2);
    yAxis[1].color = sf::Color(255, 226, 0); //yellow
    yAxis[2].position = sf::Vector2f(SCREEN_WIDTH*4/10, SCREEN_HEIGHT); //blue
    yAxis[2].color = sf::Color(50, 162, 46);
}


//DisplayPanel's Draw produce a window with x- and y-axis
void DisplayPanel::Draw(sf::RenderWindow& window) {
    //window.clear(); //
    window.draw(xAxis);
    window.draw(yAxis);
}
