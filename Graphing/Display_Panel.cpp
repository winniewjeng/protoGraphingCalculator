//
//  Display_Panel.cpp
//   aka System
//
//  Created by Winnie Jeng on 11/27/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "Display_Panel.hpp"

Display_Panel::Display_Panel()
{
    //Display_Panel ctor configs a window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing Calculator");
    
    // Display_Panel ctor configs x-axis
    xAxis = sf::VertexArray(sf::LinesStrip, 3);
    xAxis[0].position = sf::Vector2f(0, SCREEN_HEIGHT / 2);
    xAxis[0].color = sf::Color(255, 0, 91);
    xAxis[1].position = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    xAxis[1].color = sf::Color::White;
    xAxis[2].position = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT/2);
    xAxis[2].color = sf::Color(143, 69, 225);
    
    // Display_Panel ctor configs y-axis
    yAxis = sf::VertexArray(sf::LinesStrip, 3);
    yAxis[0].position = sf::Vector2f(SCREEN_WIDTH / 2, 0);
    yAxis[0].color = sf::Color(50, 103, 206);
    yAxis[1].position = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    yAxis[1].color = sf::Color(255, 226, 0);
    yAxis[2].position = sf::Vector2f(SCREEN_WIDTH /2, SCREEN_HEIGHT);
    yAxis[2].color = sf::Color(50, 162, 46);
    
}

/*
 Display_Panel's Draw produce a window with x- and y-axis
 */
void Display_Panel::Draw(sf::RenderWindow& window) {
    //window.clear(); //
    window.draw(xAxis);
    window.draw(yAxis);
}
