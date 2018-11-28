//
//  ControlPanel.hpp
//  aka sidebar
//
//  Created by Winnie Jeng on 11/27/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef ControlPanel_hpp
#define ControlPanel_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Constants.hpp"

using namespace std;

class ControlPanel {
public:
    ControlPanel() {}
    ControlPanel(float left, float width);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);
private:
    sf::RectangleShape rect;            //sidebar rectangle
    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object
    float _left;
    float _width;
};


#endif /* ControlPanel_hpp */
