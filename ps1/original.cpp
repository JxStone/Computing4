//
//  original.cpp
//  ps1
//
//  Created by Jingxian Shi on 1/30/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include "original.hpp"
#include "SFML/Graphics/Shape.hpp"
#include <cmath>

Original::Original(int depth, double side)
{
    recursion_depth = depth;
    _top_left = sf::Vector2f(side, side);
    _top_right = sf::Vector2f(side*2, side);
    _bot_left = sf::Vector2f(side, side*2);
    _bot_right = sf::Vector2f(side*2, side*2);
    outline_square(_top_left, _top_right, _bot_right, _bot_left);
}

void Original::outline_square(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4)
{
    setPointCount(4);
    setPoint(0, p1);
    setPoint(1, p2);
    setPoint(2, p3);
    setPoint(3, p4);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(-1);
}

Original::Original(int depth, sf::Vector2f top_left, sf::Vector2f top_right, sf::Vector2f bot_right, sf::Vector2f bot_left)
{
    recursion_depth = depth;
    _top_left = top_left;
    _top_right = top_right;
    _bot_left = bot_left;
    _bot_right = bot_right;

    outline_square(_top_left, _top_right, _bot_right, _bot_left);
}

void Original::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw((sf::ConvexShape)(*this), states);
    if(recursion_depth <= 0)
    {
        return;
    }
    else
    {
        Original top_left(recursion_depth-1,
                          sf::Vector2f(_top_left.x-(_top_right.x-_top_left.x)/2.0,
                                       _top_left.y+(_top_left.y-_bot_left.y)/2.0),
                          sf::Vector2f(_top_left.x,
                                       _top_left.y+(_top_left.y-_bot_left.y)/2.0),
                          _top_left,
                          sf::Vector2f(_top_left.x-(_top_right.x-_top_left.x)/2.0,
                                       _top_left.y));
        top_left.draw(target, states);
        
        Original top_right(recursion_depth-1,
                           sf::Vector2f(_top_right.x, _top_right.y+(_top_right.y-_bot_right.y)/2.0),
                           sf::Vector2f(_top_right.x+(_top_right.x-_top_left.x)/2.0,
                                        _top_right.y+(_top_right.y-_bot_right.y)/2.0),
                           sf::Vector2f(_top_right.x+(_top_right.x-_top_left.x)/2.0,
                                        _top_right.y),
                           _top_right);
        top_right.draw(target, states);

        Original bot_left(recursion_depth-1,
                          sf::Vector2f(_bot_left.x-(_bot_right.x-_bot_left.x)/2.0, _bot_left.y),
                          _bot_left,
                          sf::Vector2f(_bot_left.x, _bot_left.y+(_bot_left.y-_top_left.y)/2.0),
                          sf::Vector2f(_bot_left.x-(_bot_right.x-_bot_left.x)/2.0,
                                       _bot_left.y+(_bot_left.y-_top_left.y)/2.0));
        bot_left.draw(target, states);
        
        Original bot_right(recursion_depth-1,
                           _bot_right,
                           sf::Vector2f(_bot_right.x+(_top_right.x-_top_left.x)/2.0,
                                        _bot_right.y),
                           sf::Vector2f(_bot_right.x+(_top_right.x-_top_left.x)/2.0,
                                        _bot_right.y+(_bot_right.y-_top_right.y)/2.0),
                           sf::Vector2f(_bot_right.x,
                                        _bot_right.y+(_bot_right.y-_top_right.y)/2.0));
        bot_right.draw(target, states);
    }
}
