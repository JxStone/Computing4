//
//  main.cpp
//  ps3a
//
//  Created by Jingxian Shi on 2/14/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include <iostream>
#include "Body.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    int num_body;
    double universe_radius;
    
    cin >> num_body >> universe_radius;
    
    int window_size = 500;
    sf::RenderWindow window(sf::VideoMode(window_size, window_size), "Universe");
    window.setFramerateLimit(1);
    
    vector<Body*> body;
    
    for(int i = 0; i < num_body; i++)
    {
        body.push_back(new Body);
        cin >> *body[i];
        (*body[i]).setWindowSize(window_size);
        (*body[i]).setUnivSize(universe_radius);
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        
        window.clear(sf::Color::Black);
        for(int i = 0; i < num_body; i++)
        {
            window.draw(*body[i]);
        }
        window.display();
    }

    return 0;
}
