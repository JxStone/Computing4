
#include <iostream>
#include <cmath>
#include "sierpinski.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

int main(int argc, const char * argv[])
{
    if(argc < 3)
    {
        cout << "Sierpinski[recursion-depth] [side-length]" << endl;
        return -1;
    }
    
    int depth = atoi(argv[1]);
    double side = atoi(argv[2]);
    
    if (depth <= 0 || side <= 0)
    {
        cout << "Both argument needs to be positive" << endl;
        return -1;
    }
    
   Sierpinski st(depth-1, side);
    
    sf::RenderWindow window(sf::VideoMode(side, (double)((sqrt(3.)/2.0)*(double)side)), "Sierpinski");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }
        window.clear(sf::Color::White);
        window.draw(st);
        window.display();
    }

    return 0;
}
