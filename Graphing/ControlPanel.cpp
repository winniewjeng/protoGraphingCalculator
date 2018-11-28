//
//  ControlPanel.cpp
//  aka sidebar
//
//  Created by Winnie Jeng on 11/27/18.
//  Copyright © 2018 Winnie Jeng. All rights reserved.
//

#include "ControlPanel.hpp"
#include "Constants.hpp"
#include "ResourcePath.hpp"

ControlPanel::ControlPanel(float left, float width):_left(left), _width(width){
    cout<<"Control_Panel CTOR: TOP"<<endl;
    items.reserve(50);
    
    //set up the Control_Panel rectangle:
    rect.setFillColor(sf::Color(210,239,255));
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout<<"Control_Panel CTOR: about to load font."<<endl;
    
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]
    
    if (!font.loadFromFile(resourcePath() + "Roboto-Thin.ttf")){
        cout<<"Control_Panel() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    cout<<"Control_Panel CTOR: loaded font."<<endl;
    
    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Control_Panel CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(40);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color(0,78,121));
    ////this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));
    
    items.push_back("Control_Panel sample text");
    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i=0 ; i<30; i++){
        items.push_back("");
    }
    cout<<"Control_Panel: CTOR: Exit."<<endl;
}

void ControlPanel::draw(sf::RenderWindow& window){
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;
    
    window.draw(rect);
    float height = 10;
    
    for (vector<string>::iterator it = items.begin();
         it != items.end(); it++){
        bool blank = false;
        if (strlen(it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else{
            sb_text.setString(it->c_str());
        }
        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(sb_text);
    }
}

string& ControlPanel::operator [](int index){
    return items[index];
}

