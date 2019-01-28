//
//  sierpinski.hpp
//  ps1
//
//  Created by Jingxian Shi on 1/30/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#ifndef sierpinski_hpp
#define sierpinski_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <iostream>

using namespace std;

class Sierpinski : public sf::ConvexShape
{
public:
    Sierpinski(int depth, double side);
    Sierpinski(int depth, sf::Vector2f top, sf::Vector2f left, sf::Vector2f right);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    int recursion_depth;
    sf::Vector2f _top, _left, _right;
};

#endif /* sierpinski_hpp */


