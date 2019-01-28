//
//  main.cpp
//  ps2b
//
//  Created by Jingxian Shi on 2/9/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "LFSR.hpp"

sf::Image transform(sf::Image image, LFSR l);

int main(int argc, const char* argv[])
{
//    if(argc != 5)
//    {
//        std::cout << "Wrong number of arguments" << std::endl;
//        return -1;
//    }
    
    std::string input_image = argv[1];
    std::string output_image = argv[2];
    std::string seed = argv[3];
    int tap = atoi(argv[4]);
    
    sf::Image image, encrypted_image;
    if (!image.loadFromFile(input_image))
    {
        return -1;
    }
    if (!encrypted_image.loadFromFile(input_image))
    {
        return -1;
    }
    
    sf::Color p;
    sf::Vector2u size = image.getSize();
    LFSR l(seed, tap);
    
    for (int x = 0; x< size.x; x++) {
        for (int y = 0; y< size.y; y++) {
            p = encrypted_image.getPixel(x, y);
            p.r ^= l.generate(8);
            p.g ^= l.generate(8);
            p.b ^= l.generate(8);
            encrypted_image.setPixel(x, y, p);
        }
    }

    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "PhotoMagic");
    
    sf::Texture texture1, texture2;
    texture1.loadFromImage(image);
    texture2.loadFromImage(encrypted_image);
    
    sf::Sprite sprite1, sprite2;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    
    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window2.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }
    
    if (!encrypted_image.saveToFile(output_image))
    {
        return -1;
    }
    
    return 0;
}

