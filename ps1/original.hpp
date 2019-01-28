//
//  original.hpp
//  ps1
//
//  Created by Jingxian Shi on 1/30/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#ifndef original_hpp
#define original_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <iostream>

using namespace std;

class Original : public sf::ConvexShape
{
public:
    Original(int depth, double side);
    Original(int depth, sf::Vector2f top_left, sf::Vector2f top_right, sf::Vector2f bot_left, sf::Vector2f bot_right);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void outline_square(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4);
private:
    int recursion_depth;
    sf::Vector2f _top_left, _top_right, _bot_left, _bot_right;
};

#endif /* original_hpp */
