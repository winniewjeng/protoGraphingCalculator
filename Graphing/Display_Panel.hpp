//
//  Display_Panel.hpp
//  aka System
//
//  Created by Winnie Jeng on 11/27/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#ifndef Display_Panel_hpp
#define Display_Panel_hpp

#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
using namespace std;

class Display_Panel {
public:
    Display_Panel();
    void Draw(sf::RenderWindow& widnow);
private:
    sf::VertexArray xAxis;
    sf::VertexArray yAxis;
};

#endif /* Display_Panel_hpp */
