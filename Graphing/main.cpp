#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <cmath>
#include "Constants.hpp"
#include "ControlPanel.hpp"
#include "Display_Panel.hpp"
#include "Plot.hpp"

using namespace std;

//const sf::Color::
double fxn(double x) {
    return 7*sin(x/4);
}

int main() {
//    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML GRAPH");
//
//    sf::Cursor cursor;
//    if (cursor.loadFromSystem(sf::Cursor::Hand))
//        window.setMouseCursor(cursor);
//
//    sf::VertexArray x_axis(sf::LinesStrip, 3);
//    x_axis[0].position = sf::Vector2f(0, SCREEN_HEIGHT / 2);
//    x_axis[0].color = sf::Color(255, 0, 91);
//    x_axis[1].position = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
//    x_axis[1].color = sf::Color::White;
//    x_axis[2].position = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT/2);
//    x_axis[2].color = sf::Color(143, 69, 225);
//
//    sf::VertexArray y_axis(sf::LinesStrip, 3);
//    y_axis[0].position = sf::Vector2f(SCREEN_WIDTH / 2, 0);
//    y_axis[0].color = sf::Color(50, 103, 206);
//    y_axis[1].position = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
//    y_axis[1].color = sf::Color(255, 226, 0);
//    y_axis[2].position = sf::Vector2f(SCREEN_WIDTH /2, SCREEN_HEIGHT);
//    y_axis[2].color = sf::Color(50, 162, 46);
//
//    sf::Color colors[9];
//    colors[0] = sf::Color(1, 63, 255);
//    colors[1] = sf::Color(1, 217, 255);
//    colors[2] = sf::Color(1, 164, 255);
//    colors[3] = sf::Color(1, 63, 255);
//    colors[4] = sf::Color(1, 217, 255);
//    colors[5] = sf::Color(1, 164, 255);
//    colors[6] = sf::Color(1, 63, 255);
//    colors[7] = sf::Color(1, 217, 255);
//    colors[8] = sf::Color(1, 164, 255);
//
//
//    sf::VertexArray curve(sf::LineStrip, 500);
//
//    for (int x = -1*SCREEN_WIDTH; x < SCREEN_WIDTH; x++) {
//        curve.append(sf::Vertex(sf::Vector2f(SCALESIZE * x + SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - fxn(x) * SCALESIZE), colors[abs(x)%9]));
//    }
//
//    while (window.isOpen()){
//        sf::Event event;
//        while (window.pollEvent(event)){
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        window.clear();
//        window.draw(x_axis);
//        window.draw(y_axis);
//        window.draw(curve);
//        window.display();
//    }
    Plot p;
    p.run();
    
    return 0;
}
