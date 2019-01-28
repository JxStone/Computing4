//
//  Body.cpp
//  ps3a
//
//  Created by Jingxian Shi on 2/19/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include "Body.hpp"

Body::Body()
{
    
}

Body::Body(double xpos, double ypos, double xvel, double yvel, double mass, std::string file_name)
{
    _xpos = xpos;
    _ypos = ypos;
    _xvel = xvel;
    _yvel = yvel;
    _mass = mass;
    _image_file = file_name;
    
    _texture.loadFromFile(_image_file);
    _sprite.setTexture(_texture);
    
}

Body::~Body()
{
    
}

std::istream& operator>>(std::istream& in, Body& body)
{
    in >> body._xpos >> body._ypos >> body._xvel >> body._yvel >> body._mass >> body._image_file;
    body._texture.loadFromFile(body._image_file);
    body._sprite.setTexture(body._texture);
    
    return in;
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Sprite image = _sprite;
    
    image.setPosition(_window_size/2.0 + _xpos * _window_size * 0.5 / _univ_size, _window_size/2.0 - _ypos * _window_size * 0.5 / _univ_size);

    target.draw(image, states);
}
