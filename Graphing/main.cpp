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
    Plot p;
    p.run();
    
    return 0;
}
